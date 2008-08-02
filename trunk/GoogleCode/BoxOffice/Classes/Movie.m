// Copyright (C) 2008 Cyrus Najmabadi
//
// This program is free software; you can redistribute it and/or modify it 
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the Free Software Foundation, Inc., 51 
// Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#import "Movie.h"
#import "Utilities.h"

@implementation Movie

@synthesize identifier;
@synthesize title;
@synthesize rating;
@synthesize length;
@synthesize releaseDate;
@synthesize poster;
@synthesize synopsis;

- (void) dealloc {
    self.identifier = nil;
    self.title = nil;
    self.rating = nil;
    self.length = nil;
    self.releaseDate = nil;
    self.poster = nil;
    self.synopsis = nil;

    [super dealloc];
}

+ (NSString*) massageTitle:(NSString*) title {
    title = [title stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];

    if ([title hasSuffix:@", The"]) {
        title = [NSString stringWithFormat:@"The %@", [title substringToIndex:([title length] - 5)]];
    } else if ([title hasSuffix:@", A"]) {
        title = [NSString stringWithFormat:@"A %@", [title substringToIndex:([title length] - 3)]];
    }

    return title;
}

- (id) initWithIdentifier:(NSString*) identifier_
                    title:(NSString*) title_
                   rating:(NSString*) rating_
                   length:(NSString*) length_
              releaseDate:(NSDate*) releaseDate_
                   poster:(NSString*) poster_
                 synopsis:(NSString*) synopsis_ {
    if (self = [self init]) {
        self.identifier = identifier_;
        self.title    = [Movie massageTitle:title_];
        self.rating   = [rating_   stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
        if (self.rating == nil) {
            self.rating = @"NR";
        }
        self.length = length_;
        self.releaseDate = releaseDate_;
        self.poster = poster_;
        self.synopsis =
            [[synopsis_ stringByReplacingOccurrencesOfString:@"<em>" withString:@""]
                stringByReplacingOccurrencesOfString:@"</em>" withString:@""];
    }

    return self;
}

+ (Movie*) movieWithIdentifier:(NSString*) identifier
                         title:(NSString*) title
                        rating:(NSString*) rating
                        length:(NSString*) length
                   releaseDate:(NSDate*) releaseDate
                        poster:(NSString*) poster
                      synopsis:(NSString*) synopsis  {
    return [[[Movie alloc] initWithIdentifier:identifier
                                        title:title
                                       rating:rating
                                       length:length
                                  releaseDate:releaseDate
                                       poster:poster
                                     synopsis:synopsis] autorelease];
}

+ (Movie*) movieWithDictionary:(NSDictionary*) dictionary {
    return [Movie movieWithIdentifier:[dictionary objectForKey:@"identifier"]
                                title:[dictionary objectForKey:@"title"]
                               rating:[dictionary objectForKey:@"rating"]
                               length:[dictionary objectForKey:@"length"]
                          releaseDate:[dictionary objectForKey:@"releaseDate"]
                               poster:[dictionary objectForKey:@"poster"]
                             synopsis:[dictionary objectForKey:@"synopsis"]];
}

- (NSDictionary*) dictionary {
    NSMutableDictionary* dictionary = [NSMutableDictionary dictionary];
    [dictionary setValue:self.identifier     forKey:@"identifier"];
    [dictionary setValue:self.title          forKey:@"title"];
    [dictionary setValue:self.rating         forKey:@"rating"];
    [dictionary setValue:self.length         forKey:@"length"];
    [dictionary setValue:self.releaseDate    forKey:@"releaseDate"];
    [dictionary setValue:self.poster         forKey:@"poster"];
    [dictionary setValue:self.synopsis       forKey:@"synopsis"];
    return dictionary;
}

- (NSString*) description {
    return [[self dictionary] description];
}

- (BOOL) isEqual:(id) anObject {
    Movie* other = anObject;

    return
    [self.identifier isEqual:other.identifier] &&
    [self.title isEqual:other.title];
}

- (NSUInteger) hash {
    return
    [self.identifier hash];
    [self.title hash];
}

- (NSString*) ratingAndRuntimeString {
    NSInteger movieLength = [self.length intValue];
    NSInteger hours = movieLength / 60;
    NSInteger minutes = movieLength % 60;

    NSString* ratingString;
    if ([Utilities isNilOrEmpty:rating] || [rating isEqual:@"NR"]) {
        ratingString = NSLocalizedString(@"Unrated.", nil);
    }  else {
        ratingString = [NSString stringWithFormat:NSLocalizedString(@"Rated %@.", nil), self.rating];
    }

    NSMutableString* text = [NSMutableString stringWithString:ratingString];
    if (movieLength != 0) {
        if (hours == 1) {
            [text appendString:@" 1 hour"];
        } else if (hours > 1) {
            [text appendFormat:@" %d hours", hours];
        }

        if (minutes == 1) {
            [text appendString:@" 1 minute"];
        } else if (minutes > 1) {
            [text appendFormat:@" %d minutes", minutes];
        }
    }

    return text;
}

@end
