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

#import "CreditsViewController.h"

#import "Application.h"
#import "SettingCell.h"

@implementation CreditsViewController

@synthesize fandangoImage;
@synthesize metacriticImage;
@synthesize rottenTomatoesImage;
@synthesize tryntImage;
@synthesize yahooImage;
@synthesize localizers;

- (void) dealloc {
    self.fandangoImage = nil;
    self.metacriticImage = nil;
    self.rottenTomatoesImage = nil;
    self.tryntImage = nil;
    self.yahooImage = nil;
    self.localizers = nil;

    [super dealloc];
}


- (id) init {
    if (self = [super initWithStyle:UITableViewStyleGrouped]) {
        self.fandangoImage = [UIImage imageNamed:@"FandangoLogo.png"];
        self.metacriticImage = [UIImage imageNamed:@"MetacriticLogo.png"];
        self.rottenTomatoesImage = [UIImage imageNamed:@"RottenTomatoesLogo.png"];
        self.tryntImage = [UIImage imageNamed:@"TryntLogo.png"];
        self.yahooImage = [UIImage imageNamed:@"YahooLogo.png"];

        self.title = NSLocalizedString(@"About", nil);

        NSMutableDictionary* dictionary = [NSMutableDictionary dictionary];
        [dictionary setObject:@"Allan Lund Jensen"  forKey:@"da"];
        [dictionary setObject:@"André van Haren"    forKey:@"nl"];
        [dictionary setObject:@"Jonathan Grenier"   forKey:@"fr"];
        [dictionary setObject:@"Leo Yamamoto"       forKey:@"ja"];
        [dictionary setObject:@"Pedro Pinhão"       forKey:@"pt"];
        [dictionary setObject:@"Jorge Herskovic"    forKey:@"es"];
        [dictionary setObject:@"Oğuz Taş"           forKey:@"tr"];
        [dictionary setObject:@"J-P. Helisten"      forKey:@"fi"];
        self.localizers = dictionary;
    }

    return self;
}


- (void) refresh {
    [self.tableView reloadData];
}


- (void) viewWillAppear:(BOOL) animated {
    [self.tableView deselectRowAtIndexPath:self.tableView.indexPathForSelectedRow animated:animated];
}


- (NSInteger) numberOfSectionsInTableView:(UITableView*) tableView {
    return 8;
}


- (NSInteger)       tableView:(UITableView*) table
        numberOfRowsInSection:(NSInteger) section {
    if (section == 0) {
        return 2;
    } else if (section == 1) {
        return 2;
    } else if (section == 2) {
        return 2;
    } else if (section == 3) {
        return 1;
    } else if (section == 4) {
        return 1;
    } else if (section == 5) {
        return 3;
    } else if (section == 6) {
        return localizers.count;
    } else if (section == 7) {
        return 1;
    }

    return 1;
}


- (UIImage*) getImage:(NSIndexPath*) indexPath {
    NSInteger section = indexPath.section;
    NSInteger row = indexPath.row;

    if (section == 2) {
        if (row == 0) {
            return rottenTomatoesImage;
        } else if (row == 1) {
            return metacriticImage;
        }
    } else if (section == 3) {
        return fandangoImage;
    } else if (section == 4) {
        return tryntImage;
    } else if (section == 5) {
        if (row == 0) {
            return yahooImage;
        }
    }

    return nil;
}


- (CGFloat)         tableView:(UITableView*) tableView
      heightForRowAtIndexPath:(NSIndexPath*) indexPath {
    UIImage* image = [self getImage:indexPath];
    CGFloat height = tableView.rowHeight;
    if (image != nil) {
        CGFloat imageHeight = image.size.height + 10;
        if (imageHeight > height) {
            height = imageHeight;
        }
    }

    return height;
}


NSComparisonResult compareLanguageCodes(id code1, id code2, void* context) {
    NSString* language1 = [[NSLocale currentLocale] displayNameForKey:NSLocaleIdentifier value:code1];
    NSString* language2 = [[NSLocale currentLocale] displayNameForKey:NSLocaleIdentifier value:code2];

    return [language1 compare:language2];
}


- (UITableViewCell*) localizationCellForRow:(NSInteger) row {
    SettingCell* cell = [[[SettingCell alloc] initWithFrame:CGRectZero reuseIdentifier:nil] autorelease];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;

    NSString* code = [[localizers.allKeys sortedArrayUsingFunction:compareLanguageCodes context:NULL] objectAtIndex:row];
    NSString* person = [localizers objectForKey:code];
    NSString* language = [[NSLocale currentLocale] displayNameForKey:NSLocaleIdentifier value:code];

    [cell setKey:language value:person];
    return cell;
}


- (UITableViewCell*) tableView:(UITableView*) tableView
         cellForRowAtIndexPath:(NSIndexPath*) indexPath {
    NSInteger section = indexPath.section;
    NSInteger row = indexPath.row;

    if (section == 6) {
        return [self localizationCellForRow:row];
    }

    UITableViewCell* cell = [[[UITableViewCell alloc] initWithFrame:[UIScreen mainScreen].applicationFrame] autorelease];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;

    UIImage* image = [self getImage:indexPath];

    if (image != nil) {
        UIImageView* imageView = [[[UIImageView alloc] initWithImage:image] autorelease];

        NSInteger x = (self.tableView.contentSize.width - image.size.width) / 2 - 20;
        NSInteger y = ([self tableView:tableView heightForRowAtIndexPath:indexPath] - image.size.height) / 2;

        imageView.frame = CGRectMake(x, y, image.size.width, image.size.height);

        [cell.contentView addSubview:imageView];
    } else if (section == 0) {
        if (row == 0) {
            cell.text = NSLocalizedString(@"E-mail", nil);
        } else {
            cell.text = NSLocalizedString(@"Project website", nil);
        }
    } else if (section == 1) {
        if (row == 0) {
            cell.text = NSLocalizedString(@"E-mail", nil);
        } else {
            cell.text = NSLocalizedString(@"Website", nil);
        }
    } else if (section == 5) {
        if (row == 1) {
            cell.text = @"GeoNames";
        } else if (row == 2) {
            cell.text = @"GeoCoder.ca";
        }
    } else if (section == 7) {
        cell.text = NSLocalizedString(@"License", nil);
        cell.selectionStyle = UITableViewCellSelectionStyleBlue;
    }

    return cell;
}


- (NSString*)       tableView:(UITableView*) tableView
      titleForHeaderInSection:(NSInteger) section {
    if (section == 0) {
        return NSLocalizedString(@"Written by Cyrus Najmabadi", nil);
    } else if (section == 1) {
        return NSLocalizedString(@"Graphics by Jeffrey Nee", nil);
    } else if (section == 2) {
        return NSLocalizedString(@"Movie reviews provided by:", nil);
    } else if (section == 3) {
        return NSLocalizedString(@"Ticket sales provided by:", nil);
    } else if (section == 4) {
        return NSLocalizedString(@"Movie details provided by:", nil);
    } else if (section == 5) {
        return NSLocalizedString(@"Geolocation services provided by:", nil);
    } else if (section == 6) {
        return NSLocalizedString(@"Localized by:", nil);
    }

    return nil;
}


- (NSString*)       tableView:(UITableView*) tableView
      titleForFooterInSection:(NSInteger) section {
    if (section == 7) {
        return @"All Rotten Tomatoes content is used under license from Rotten Tomatoes. Rotten Tomatoes, Certified Fresh and the Tomatometer are the trademarks of Incfusion Corporation, d/b/a Rotten Tomatoes, a subsidiary of IGN Entertainment, Inc.";
    }

    return nil;
}


- (UITableViewCellAccessoryType) tableView:(UITableView*) tableView
          accessoryTypeForRowWithIndexPath:(NSIndexPath*) indexPath {
    if (indexPath.section >= 0 && indexPath.section <= 5) {
        return UITableViewCellAccessoryDetailDisclosureButton;
    } else if (indexPath.section == 6) {
        return UITableViewCellAccessoryNone;
    } else {
        return UITableViewCellAccessoryDisclosureIndicator;
    }
}


- (void) licenseCellTapped {
    UIViewController* controller = [[[UIViewController alloc] init] autorelease];
    controller.title = NSLocalizedString(@"License", nil);

    UITextView* textView = [[[UITextView alloc] initWithFrame:[UIScreen mainScreen].bounds] autorelease];
    textView.editable = NO;
    textView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;

    NSString* licensePath = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"License.txt"];
    textView.text = [NSString stringWithContentsOfFile:licensePath];
    textView.font = [UIFont boldSystemFontOfSize:12];
    textView.textColor = [UIColor grayColor];

    [controller.view addSubview:textView];
    [self.navigationController pushViewController:controller animated:YES];
}


- (void)            tableView:(UITableView*) tableView
      didSelectRowAtIndexPath:(NSIndexPath*) indexPath {
    if (indexPath.section == 6) {
        [self.tableView deselectRowAtIndexPath:indexPath animated:NO];
    } else if (indexPath.section == 7) {
        [self licenseCellTapped];
    }
}


- (void)                            tableView:(UITableView*) tableView
     accessoryButtonTappedForRowWithIndexPath:(NSIndexPath*) indexPath {
    NSInteger section = indexPath.section;
    NSInteger row = indexPath.row;

    NSString* url = nil;
    if (section == 0) {
        if (row == 0) {
            url = @"mailto:cyrus.najmabadi@gmail.com?subject=Now%20Playing";
        } else {
            url = @"http://metasyntactic.googlecode.com";
        }
    } else if (section == 1) {
        if (row == 0) {
            url = @"mailto:jeff@jeffnee.com";
        } else {
            url = @"http://www.jeffnee.com";
        }
    } else if (section == 2) {
        if (row == 0) {
            url = @"http://www.rottentomatoes.com";
        } else {
            url = @"http://www.metacritic.com";
        }
    } else if (section == 3) {
        url = @"http://www.fandango.com";
    } else if (section == 4) {
        url = @"http://www.trynt.com";
    } else if (section == 5) {
        if (row == 0) {
            url = @"http://www.yahoo.com";
        } else if (row == 1) {
            url = @"http://www.geonames.org";
        } else {
            url = @"http://geocoder.ca";
        }
    } else if (section == 6) {
        return;
    } else if (section == 7) {
        return;
    }

    [Application openBrowser:url];
}


- (void) didRotateFromInterfaceOrientation:(UIInterfaceOrientation) fromInterfaceOrientation {
    [self refresh];
}


@end