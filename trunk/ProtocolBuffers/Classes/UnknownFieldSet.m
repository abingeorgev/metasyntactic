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

#import "UnknownFieldSet.h"

#import "CodedInputStream.h"
#import "CodedOutputStream.h"
#import "Field.h"
#import "UnknownFieldSet_Builder.h"

@implementation PBUnknownFieldSet

static PBUnknownFieldSet* defaultInstance = nil;

+ (void) initialize {
    if (self == [PBUnknownFieldSet class]) {
        defaultInstance = [[PBUnknownFieldSet setWithFields:[NSMutableDictionary dictionary]] retain];
    }
}


@synthesize fields;

- (void) dealloc {
    self.fields = nil;

    [super dealloc];
}


+ (PBUnknownFieldSet_Builder*) newBuilder {
    return [PBUnknownFieldSet_Builder newBuilder];
}


+ (PBUnknownFieldSet_Builder*) newBuilder:(PBUnknownFieldSet*) copyFrom {
    return [[PBUnknownFieldSet_Builder newBuilder] mergeUnknownFields:copyFrom];
}


+ (PBUnknownFieldSet*) defaultInstance {
    return defaultInstance;
}


- (id) initWithFields:(NSMutableDictionary*) fields_ {
    if (self = [super init]) {
        self.fields = fields_;
    }

    return self;
}


+ (PBUnknownFieldSet*) setWithFields:(NSMutableDictionary*) fields {
    return [[[PBUnknownFieldSet alloc] initWithFields:fields] autorelease];
}


- (NSDictionary*) asMap {
    return fields;
}


- (BOOL) hasField:(int32_t) number {
    return [fields objectForKey:[NSNumber numberWithInt:number]] != nil;
}


- (PBField*) getField:(int32_t) number {
    PBField* result = [fields objectForKey:[NSNumber numberWithInt:number]];
    return (result == nil) ? [PBField defaultInstance] : result;
}


- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output {
    NSArray* sortedKeys = [fields.allKeys sortedArrayUsingSelector:@selector(compare:)];
    for (NSNumber* number in sortedKeys) {
        PBField* value = [fields objectForKey:number];
        [value writeTo:number.intValue output:output];
    }
}


- (void) writeToOutputStream:(NSOutputStream*) output {
    PBCodedOutputStream* codedOutput = [PBCodedOutputStream newInstance:output];
    [self writeToCodedOutputStream:codedOutput];
    [codedOutput flush];
}


+ (PBUnknownFieldSet*) parseFromCodedInputStream:(PBCodedInputStream*) input {
    return [[[PBUnknownFieldSet newBuilder] mergeFromCodedInputStream:input] build];
}


+ (PBUnknownFieldSet*) parseFromData:(NSData*) data {
    return [[[PBUnknownFieldSet newBuilder] mergeFromData:data] build];
}


+ (PBUnknownFieldSet*) parseFromInputStream:(NSInputStream*) input {
    return [[[PBUnknownFieldSet newBuilder] mergeFromInputStream:input] build];
}


/** Get the number of bytes required to encode this set. */
- (int32_t) getSerializedSize {
    int32_t result = 0;
    for (NSNumber* number in fields) {
        result += [[fields objectForKey:number] getSerializedSize:number.intValue];
    }
    return result;
}

/**
 * Serializes the set and writes it to {@code output} using
 * {@code MessageSet} wire format.
 */
- (void) writeAsMessageSetTo:(PBCodedOutputStream*) output {
    for (NSNumber* number in fields) {
        [[fields objectForKey:number] writeAsMessageSetExtensionTo:number.intValue output:output];
    }
}


/**
 * Get the number of bytes required to encode this set using
 * {@code MessageSet} wire format.
 */
- (int32_t) getSerializedSizeAsMessageSet {
    int32_t result = 0;
    for (NSNumber* number in fields) {
        result += [[fields objectForKey:number] getSerializedSizeAsMessageSetExtension:number.intValue];
    }
    return result;
}

#if 0


/**
 * Converts the set to a string in protocol buffer text format. This is
 * just a trivial wrapper around
 * {@link TextFormat#printToString(PBUnknownFieldSet)}.
 */
public final String toString() {
    return TextFormat.printToString(this);
}

/**
 * Serializes the message to a {@code ByteString} and returns it. This is
 * just a trivial wrapper around {@link #writeTo(PBCodedOutputStream)}.
 */
public final ByteString toByteString() {
    try {
        ByteString.CodedBuilder out =
        ByteString.newCodedBuilder(getSerializedSize());
        writeTo(out.getCodedOutput());
        return out.build();
    } catch (IOException e) {
        throw new RuntimeException(
                                   "Serializing to a ByteString threw an IOException (should " +
                                   "never happen).", e);
    }
}


/**
 * Serializes the message and writes it to {@code output}.  This is just a
 * trivial wrapper around {@link #writeTo(PBCodedOutputStream)}.
 */



}
#endif
@end
