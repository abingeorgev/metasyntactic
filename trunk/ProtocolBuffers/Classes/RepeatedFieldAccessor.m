// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.
// http://code.google.com/p/protobuf/
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import "RepeatedFieldAccessor.h"

@interface PBRepeatedFieldAccessor()
    @property SEL itemListSelector;
    @property SEL itemAtIndexSelector;
    @property SEL replaceItemAtIndexWithItemSelector;
    @property SEL addItemSelector;
    @property SEL addAllItemSelector;
    @property SEL clearItemListSelector;
@end


@implementation PBRepeatedFieldAccessor

@synthesize itemListSelector;
@synthesize itemAtIndexSelector;
@synthesize replaceItemAtIndexWithItemSelector;
@synthesize addItemSelector;
@synthesize addAllItemSelector;
@synthesize clearItemListSelector;

- (void) dealloc {
    self.itemListSelector = nil;
    self.itemAtIndexSelector = nil;
    self.replaceItemAtIndexWithItemSelector = nil;
    self.addItemSelector = nil;
    self.addAllItemSelector = nil;
    self.clearItemListSelector = nil;

    [super dealloc];
}

- (id) initWithField:(PBFieldDescriptor*) field_
                name:(NSString*) name
        messageClass:(Class) messageClass
        builderClass:(Class) builderClass {
    if (self = [super initWithField:field_]) {
        NSString* camelName = [self camelName:name];
        self.itemListSelector = sel_getUid([[NSString stringWithFormat:@"%@List", camelName] UTF8String]);
        self.itemAtIndexSelector = sel_getUid([[NSString stringWithFormat:@"%@AtIndex:", camelName] UTF8String]);
        self.replaceItemAtIndexWithItemSelector = 
        sel_getUid([[NSString stringWithFormat:@"replace%@AtIndex:with%@:", name, name] UTF8String]);
        self.addItemSelector = sel_getUid([[NSString stringWithFormat:@"add%@:", name] UTF8String]);
        self.addAllItemSelector = sel_getUid([[NSString stringWithFormat:@"addAll%@:", name] UTF8String]);
        self.clearItemListSelector = sel_getUid([[NSString stringWithFormat:@"clear%@List", name] UTF8String]);
    }
    
    return self;
}


+ (PBRepeatedFieldAccessor*) accessorWithField:(PBFieldDescriptor*) field
                                          name:(NSString*) name
                                  messageClass:(Class) messageClass
                                  builderClass:(Class) builderClass {
    return [[[PBRepeatedFieldAccessor alloc] initWithField:field name:name messageClass:messageClass builderClass:builderClass] autorelease];
}

- (id) get:(PBGeneratedMessage*) message {
    return [message performSelector:itemListSelector];
}


- (void) set:(PBGeneratedMessage_Builder*) builder value:(id) value {
    @throw [NSException exceptionWithName:@"NYI" reason:@"" userInfo:nil];
}


- (id) getRepeated:(PBGeneratedMessage*) message index:(int32_t) index {
    @throw [NSException exceptionWithName:@"NYI" reason:@"" userInfo:nil];
}


- (void) setRepeated:(PBGeneratedMessage_Builder*) builder index:(int32_t) index value:(id) value {
    @throw [NSException exceptionWithName:@"NYI" reason:@"" userInfo:nil];
}


- (void) addRepeated:(PBGeneratedMessage_Builder*) builder value:(id) value {
    [builder performSelector:addItemSelector withObject:value];
}


- (BOOL) has:(PBGeneratedMessage*) message {
    @throw [NSException exceptionWithName:@"NYI" reason:@"" userInfo:nil];
}


- (int32_t) getRepeatedCount:(PBGeneratedMessage*) message {
    @throw [NSException exceptionWithName:@"NYI" reason:@"" userInfo:nil];
}


- (void) clear:(PBGeneratedMessage_Builder*) builder {
    @throw [NSException exceptionWithName:@"NYI" reason:@"" userInfo:nil];
}


- (id<PBMessage_Builder>) newBuilder {
    @throw [NSException exceptionWithName:@"NYI" reason:@"" userInfo:nil];
}


@end
