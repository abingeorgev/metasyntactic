// Copyright (C) 2008 Cyrus Najmabadi
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the Free Software Foundation, Inc., 51
// Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#import "NowPlayingController.h"

#import "Application.h"
#import "ApplicationTabBarController.h"
#import "DataProvider.h"
#import "DateUtilities.h"
#import "NowPlayingAppDelegate.h"
#import "NowPlayingModel.h"
#import "RatingsCache.h"
#import "ThreadingUtilities.h"
#import "UserLocationCache.h"
#import "Utilities.h"

@implementation NowPlayingController

@synthesize appDelegate;
@synthesize determineLocationLock;
@synthesize dataProviderLock;
@synthesize ratingsLookupLock;
@synthesize upcomingMoviesLookupLock;

- (void) dealloc {
    self.appDelegate = nil;
    self.determineLocationLock = nil;
    self.dataProviderLock = nil;
    self.ratingsLookupLock = nil;
    self.upcomingMoviesLookupLock = nil;

    [super dealloc];
}


- (NowPlayingModel*) model {
    return appDelegate.model;
}


- (BOOL) tooSoon:(NSDate*) lastDate {
    if (lastDate == nil) {
        return NO;
    }

    NSDate* now = [NSDate date];

    if (![DateUtilities isSameDay:now date:lastDate]) {
        // different days. we definitely need to refresh
        return NO;
    }

    NSDateComponents* lastDateComponents = [[NSCalendar currentCalendar] components:NSHourCalendarUnit fromDate:lastDate];
    NSDateComponents* nowDateComponents = [[NSCalendar currentCalendar] components:NSHourCalendarUnit fromDate:now];

    // same day, check if they're at least 8 hours apart.
    if (nowDateComponents.hour >= (lastDateComponents.hour + 8)) {
        return NO;
    }

    // it's been less than 8 hours. it's too soon to refresh
    return YES;
}


- (void) spawnDataProviderLookupThread {
    if (self.model.userAddress.length == 0) {
        return;
    }

    if ([self tooSoon:[self.model.dataProvider lastLookupDate]]) {
        return;
    }

    [ThreadingUtilities performSelector:@selector(lookup)
                               onTarget:self.model.dataProvider
               inBackgroundWithArgument:nil
                                   gate:dataProviderLock
                                visible:YES
                            lowPriority:NO];
}


- (void) spawnRatingsLookupThread {
    NSDate* lastLookupDate = [[[NSFileManager defaultManager] attributesOfItemAtPath:[Application ratingsFile:self.model.currentRatingsProvider]
                                                                               error:NULL] objectForKey:NSFileModificationDate];
    if ([self tooSoon:lastLookupDate]) {
        return;
    }

    [ThreadingUtilities performSelector:@selector(ratingsLookupBackgroundThreadEntryPoint)
                               onTarget:self
               inBackgroundWithArgument:nil
                                   gate:ratingsLookupLock
                                visible:YES];
}


- (void) spawnUpcomingMoviesLookupThread {
    NSDate* lastLookupDate = [[[NSFileManager defaultManager] attributesOfItemAtPath:[Application upcomingMoviesIndexFile]
                                                                               error:NULL] objectForKey:NSFileModificationDate];

    if (lastLookupDate != nil) {
        if (ABS([lastLookupDate timeIntervalSinceNow]) > (3 * ONE_DAY)) {
            return;
        }
    }

    [ThreadingUtilities performSelector:@selector(updateMoviesList)
                               onTarget:self.model.upcomingCache
               inBackgroundWithArgument:nil
                                   gate:upcomingMoviesLookupLock
                                visible:YES];
}

- (void) spawnDetermineLocationThread {
    [ThreadingUtilities performSelector:@selector(determineLocation)
                               onTarget:self
               inBackgroundWithArgument:nil
                                   gate:determineLocationLock
                                visible:YES];
}


- (void) spawnBackgroundThreads {
    [self spawnRatingsLookupThread];
    [self spawnDataProviderLookupThread];
    [self spawnUpcomingMoviesLookupThread];
}


- (id) initWithAppDelegate:(NowPlayingAppDelegate*) appDelegate_ {
    if (self = [super init]) {
        self.appDelegate = appDelegate_;
        self.dataProviderLock = [[[NSLock alloc] init] autorelease];
        self.ratingsLookupLock = [[[NSLock alloc] init] autorelease];
        self.upcomingMoviesLookupLock = [[[NSLock alloc] init] autorelease];

        [self spawnDetermineLocationThread];
    }

    return self;
}


+ (NowPlayingController*) controllerWithAppDelegate:(NowPlayingAppDelegate*) appDelegate {
    return [[[NowPlayingController alloc] initWithAppDelegate:appDelegate] autorelease];
}


- (NSDictionary*) ratingsLookup {
    return [self.model.ratingsCache update];
}


- (void) ratingsLookupBackgroundThreadEntryPoint {
    NSDictionary* ratings = [self ratingsLookup];
    [self performSelectorOnMainThread:@selector(setRatings:) withObject:ratings waitUntilDone:NO];

}


- (void) setRatings:(NSDictionary*) ratings {
    if (ratings.count > 0) {
        [self.model onRatingsUpdated];
    }
}


- (void) determineLocation {
    if (self.model.userAddress.length > 0) {
        Location* location = [self.model.userLocationCache downloadUserAddressLocationBackgroundEntryPoint:self.model.userAddress];

        [self performSelectorOnMainThread:@selector(reportUserLocation:) withObject:location waitUntilDone:NO];
    }
}


- (void) reportUserLocation:(Location*) location {
    if (location == nil) {
        UIAlertView* alert = [[[UIAlertView alloc] initWithTitle:nil
                                                         message:NSLocalizedString(@"Could not find location.", nil)
                                                        delegate:nil
                                               cancelButtonTitle:NSLocalizedString(@"OK", nil)
                                               otherButtonTitles:nil] autorelease];

        [alert show];
        return;
    }

    [self spawnBackgroundThreads];
    [NowPlayingAppDelegate refresh];
}


- (void) setSearchDate:(NSDate*) searchDate {
    if ([searchDate isEqual:self.model.searchDate]) {
        return;
    }

    [self.model setSearchDate:searchDate];
    [self spawnBackgroundThreads];
    [appDelegate.tabBarController popNavigationControllersToRoot];
    [NowPlayingAppDelegate refresh];
}


- (void) setUserAddress:(NSString*) userAddress {
    if ([userAddress isEqual:self.model.userAddress]) {
        return;
    }

    [self.model setUserAddress:userAddress];
    [appDelegate.tabBarController popNavigationControllersToRoot];
    [self spawnDetermineLocationThread];
}


- (void) setSearchRadius:(NSInteger) radius {
    [self.model setSearchRadius:radius];
    [NowPlayingAppDelegate refresh];
}


- (void) setRatingsProviderIndex:(NSInteger) index {
    if (index == self.model.ratingsProviderIndex) {
        return;
    }

    [self.model setRatingsProviderIndex:index];
    [self spawnRatingsLookupThread];
    [NowPlayingAppDelegate refresh];
}


@end