// Generated by the protocol buffer compiler.  DO NOT EDIT!

#import <ProtocolBuffers/ProtocolBuffers.h>

#import "UnittestOptimizeFor.pb.h"

@class PBDescriptor;
@class PBEnumDescriptor;
@class PBEnumValueDescriptor;
@class PBFieldAccessorTable;
@class PBFileDescriptor;
@class PBGeneratedMessage_Builder;
@class BarRequest;
@class BarRequest_Builder;
@class BarResponse;
@class BarResponse_Builder;
@class FooRequest;
@class FooRequest_Builder;
@class FooResponse;
@class FooResponse_Builder;
@class ForeignEnum;
@class ForeignMessage;
@class ForeignMessage_Builder;
@class ImportEnum;
@class ImportMessage;
@class ImportMessage_Builder;
@class OptionalGroup_extension;
@class OptionalGroup_extension_Builder;
@class RepeatedGroup_extension;
@class RepeatedGroup_extension_Builder;
@class TestAllExtensions;
@class TestAllExtensions_Builder;
@class TestAllTypes;
@class TestAllTypes_Builder;
@class TestAllTypes_NestedEnum;
@class TestAllTypes_NestedMessage;
@class TestAllTypes_NestedMessage_Builder;
@class TestAllTypes_OptionalGroup;
@class TestAllTypes_OptionalGroup_Builder;
@class TestAllTypes_RepeatedGroup;
@class TestAllTypes_RepeatedGroup_Builder;
@class TestCamelCaseFieldNames;
@class TestCamelCaseFieldNames_Builder;
@class TestDupFieldNumber;
@class TestDupFieldNumber_Bar;
@class TestDupFieldNumber_Bar_Builder;
@class TestDupFieldNumber_Builder;
@class TestDupFieldNumber_Foo;
@class TestDupFieldNumber_Foo_Builder;
@class TestEmbedOptimizedForSize;
@class TestEmbedOptimizedForSize_Builder;
@class TestEmptyMessage;
@class TestEmptyMessageWithExtensions;
@class TestEmptyMessageWithExtensions_Builder;
@class TestEmptyMessage_Builder;
@class TestEnumWithDupValue;
@class TestExtremeDefaultValues;
@class TestExtremeDefaultValues_Builder;
@class TestFieldOrderings;
@class TestFieldOrderings_Builder;
@class TestForeignNested;
@class TestForeignNested_Builder;
@class TestMutualRecursionA;
@class TestMutualRecursionA_Builder;
@class TestMutualRecursionB;
@class TestMutualRecursionB_Builder;
@class TestNestedMessageHasBits;
@class TestNestedMessageHasBits_Builder;
@class TestNestedMessageHasBits_NestedMessage;
@class TestNestedMessageHasBits_NestedMessage_Builder;
@class TestOptimizedForSize;
@class TestOptimizedForSize_Builder;
@class TestReallyLargeTagNumber;
@class TestReallyLargeTagNumber_Builder;
@class TestRecursiveMessage;
@class TestRecursiveMessage_Builder;
@class TestRequired;
@class TestRequiredForeign;
@class TestRequiredForeign_Builder;
@class TestRequired_Builder;
@class TestService;
@class TestSparseEnum;

@interface UnittestEmbedOptimizeForProtoRoot : NSObject {
}
+ (PBFileDescriptor*) descriptor;
+ (PBFileDescriptor*) buildDescriptor;
@end

@interface TestEmbedOptimizedForSize : PBGeneratedMessage {
  BOOL hasOptionalMessage;
  TestOptimizedForSize* optionalMessage;
  NSMutableArray* mutableRepeatedMessageList;
}
@property (readonly) BOOL hasOptionalMessage;
@property (retain, readonly) TestOptimizedForSize* optionalMessage;
- (NSArray*) repeatedMessageList;
- (TestOptimizedForSize*) repeatedMessageAtIndex:(int32_t) index;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptorForType;
+ (TestEmbedOptimizedForSize*) defaultInstance;
- (TestEmbedOptimizedForSize*) defaultInstanceForType;
- (PBFieldAccessorTable*) internalGetFieldAccessorTable;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
+ (TestEmbedOptimizedForSize_Builder*) newBuilder;
- (TestEmbedOptimizedForSize_Builder*) newBuilderForType;
+ (TestEmbedOptimizedForSize_Builder*) newBuilderWithPrototype:(TestEmbedOptimizedForSize*) prototype;

+ (TestEmbedOptimizedForSize*) parseFromData:(NSData*) data;
+ (TestEmbedOptimizedForSize*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (TestEmbedOptimizedForSize*) parseFromInputStream:(NSInputStream*) input;
+ (TestEmbedOptimizedForSize*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (TestEmbedOptimizedForSize*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (TestEmbedOptimizedForSize*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface TestEmbedOptimizedForSize_Builder : PBGeneratedMessage_Builder {
 @private
  TestEmbedOptimizedForSize* result;
}
@property (retain) TestEmbedOptimizedForSize* result;

- (PBDescriptor*) descriptorForType;
- (TestEmbedOptimizedForSize*) defaultInstanceForType;

- (TestEmbedOptimizedForSize_Builder*) clear;
- (TestEmbedOptimizedForSize_Builder*) clone;

- (TestEmbedOptimizedForSize*) build;
- (TestEmbedOptimizedForSize*) buildPartial;

- (TestEmbedOptimizedForSize_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (TestEmbedOptimizedForSize_Builder*) mergeFromTestEmbedOptimizedForSize:(TestEmbedOptimizedForSize*) other;
- (TestEmbedOptimizedForSize_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (TestEmbedOptimizedForSize_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasOptionalMessage;
- (TestOptimizedForSize*) optionalMessage;
- (TestEmbedOptimizedForSize_Builder*) setOptionalMessage:(TestOptimizedForSize*) value;
- (TestEmbedOptimizedForSize_Builder*) setOptionalMessageBuilder:(TestOptimizedForSize_Builder*) builderForValue;
- (TestEmbedOptimizedForSize_Builder*) mergeOptionalMessage:(TestOptimizedForSize*) value;
- (TestEmbedOptimizedForSize_Builder*) clearOptionalMessage;

- (NSArray*) repeatedMessageList;
- (TestOptimizedForSize*) repeatedMessageAtIndex:(int32_t) index;
- (TestEmbedOptimizedForSize_Builder*) replaceRepeatedMessageAtIndex:(int32_t) index withRepeatedMessage:(TestOptimizedForSize*) value;
- (TestEmbedOptimizedForSize_Builder*) addRepeatedMessage:(TestOptimizedForSize*) value;
- (TestEmbedOptimizedForSize_Builder*) addAllRepeatedMessage:(NSArray*) values;
- (TestEmbedOptimizedForSize_Builder*) clearRepeatedMessageList;
@end

