// Copyright 2008 Cyrus Najmabadi
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

@class PBDescriptor;
@class PBEnumDescriptor;
@class PBEnumValueDescriptor;
@class PBFieldAccessorTable;
@class PBFileDescriptor;
@class PBGeneratedMessage_Builder;
@class PBDescriptorProto;
@class PBDescriptorProto_Builder;
@class PBDescriptorProto_ExtensionRange;
@class PBDescriptorProto_ExtensionRange_Builder;
@class PBEnumDescriptorProto;
@class PBEnumDescriptorProto_Builder;
@class PBEnumOptions;
@class PBEnumOptions_Builder;
@class PBEnumValueDescriptorProto;
@class PBEnumValueDescriptorProto_Builder;
@class PBEnumValueOptions;
@class PBEnumValueOptions_Builder;
@class PBFieldDescriptorProto;
@class PBFieldDescriptorProto_Builder;
@class PBFieldDescriptorProto_Label;
@class PBFieldDescriptorProto_Type;
@class PBFieldOptions;
@class PBFieldOptions_Builder;
@class PBFieldOptions_CType;
@class PBFileDescriptorProto;
@class PBFileDescriptorProto_Builder;
@class PBFileDescriptorSet;
@class PBFileDescriptorSet_Builder;
@class PBFileOptions;
@class PBFileOptions_Builder;
@class PBFileOptions_OptimizeMode;
@class PBMessageOptions;
@class PBMessageOptions_Builder;
@class PBMethodDescriptorProto;
@class PBMethodDescriptorProto_Builder;
@class PBMethodOptions;
@class PBMethodOptions_Builder;
@class PBServiceDescriptorProto;
@class PBServiceDescriptorProto_Builder;
@class PBServiceOptions;
@class PBServiceOptions_Builder;
@class PBUninterpretedOption;
@class PBUninterpretedOption_Builder;
@class PBUninterpretedOption_NamePart;
@class PBUninterpretedOption_NamePart_Builder;

@interface PBDescriptorRoot : NSObject {
}
+ (PBFileDescriptor*) descriptor;
+ (PBFileDescriptor*) buildDescriptor;
@end

@interface PBFileDescriptorSet : PBGeneratedMessage {
 @private
  NSMutableArray* mutableFileList;
}
- (NSArray*) fileList;
- (PBFileDescriptorProto*) fileAtIndex:(int32_t) index;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBFileDescriptorSet*) defaultInstance;
- (PBFileDescriptorSet*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBFileDescriptorSet_Builder*) builder;
+ (PBFileDescriptorSet_Builder*) builder;
+ (PBFileDescriptorSet_Builder*) builderWithPrototype:(PBFileDescriptorSet*) prototype;

+ (PBFileDescriptorSet*) parseFromData:(NSData*) data;
+ (PBFileDescriptorSet*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBFileDescriptorSet*) parseFromInputStream:(NSInputStream*) input;
+ (PBFileDescriptorSet*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBFileDescriptorSet*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBFileDescriptorSet*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBFileDescriptorSet_Builder : PBGeneratedMessage_Builder {
 @private
  PBFileDescriptorSet* result;
}

- (PBDescriptor*) descriptor;
- (PBFileDescriptorSet*) defaultInstance;

- (PBFileDescriptorSet_Builder*) clear;
- (PBFileDescriptorSet_Builder*) clone;

- (PBFileDescriptorSet*) build;
- (PBFileDescriptorSet*) buildPartial;

- (PBFileDescriptorSet_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBFileDescriptorSet_Builder*) mergeFromPBFileDescriptorSet:(PBFileDescriptorSet*) other;
- (PBFileDescriptorSet_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBFileDescriptorSet_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (NSArray*) fileList;
- (PBFileDescriptorProto*) fileAtIndex:(int32_t) index;
- (PBFileDescriptorSet_Builder*) replaceFileAtIndex:(int32_t) index with:(PBFileDescriptorProto*) value;
- (PBFileDescriptorSet_Builder*) addFile:(PBFileDescriptorProto*) value;
- (PBFileDescriptorSet_Builder*) addAllFile:(NSArray*) values;
- (PBFileDescriptorSet_Builder*) clearFileList;
@end

@interface PBFileDescriptorProto : PBGeneratedMessage {
 @private
  BOOL hasName;
  BOOL hasPackage;
  BOOL hasOptions;
  NSString* name;
  NSString* package;
  PBFileOptions* options;
  NSMutableArray* mutableDependencyList;
  NSMutableArray* mutableMessageTypeList;
  NSMutableArray* mutableEnumTypeList;
  NSMutableArray* mutableServiceList;
  NSMutableArray* mutableExtensionList;
}
- (BOOL) hasName;
- (BOOL) hasPackage;
- (BOOL) hasOptions;
@property (readonly, retain) NSString* name;
@property (readonly, retain) NSString* package;
@property (readonly, retain) PBFileOptions* options;
- (NSArray*) dependencyList;
- (NSString*) dependencyAtIndex:(int32_t) index;
- (NSArray*) messageTypeList;
- (PBDescriptorProto*) messageTypeAtIndex:(int32_t) index;
- (NSArray*) enumTypeList;
- (PBEnumDescriptorProto*) enumTypeAtIndex:(int32_t) index;
- (NSArray*) serviceList;
- (PBServiceDescriptorProto*) serviceAtIndex:(int32_t) index;
- (NSArray*) extensionList;
- (PBFieldDescriptorProto*) extensionAtIndex:(int32_t) index;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBFileDescriptorProto*) defaultInstance;
- (PBFileDescriptorProto*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBFileDescriptorProto_Builder*) builder;
+ (PBFileDescriptorProto_Builder*) builder;
+ (PBFileDescriptorProto_Builder*) builderWithPrototype:(PBFileDescriptorProto*) prototype;

+ (PBFileDescriptorProto*) parseFromData:(NSData*) data;
+ (PBFileDescriptorProto*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBFileDescriptorProto*) parseFromInputStream:(NSInputStream*) input;
+ (PBFileDescriptorProto*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBFileDescriptorProto*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBFileDescriptorProto*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBFileDescriptorProto_Builder : PBGeneratedMessage_Builder {
 @private
  PBFileDescriptorProto* result;
}

- (PBDescriptor*) descriptor;
- (PBFileDescriptorProto*) defaultInstance;

- (PBFileDescriptorProto_Builder*) clear;
- (PBFileDescriptorProto_Builder*) clone;

- (PBFileDescriptorProto*) build;
- (PBFileDescriptorProto*) buildPartial;

- (PBFileDescriptorProto_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBFileDescriptorProto_Builder*) mergeFromPBFileDescriptorProto:(PBFileDescriptorProto*) other;
- (PBFileDescriptorProto_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBFileDescriptorProto_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasName;
- (NSString*) name;
- (PBFileDescriptorProto_Builder*) setName:(NSString*) value;
- (PBFileDescriptorProto_Builder*) clearName;

- (BOOL) hasPackage;
- (NSString*) package;
- (PBFileDescriptorProto_Builder*) setPackage:(NSString*) value;
- (PBFileDescriptorProto_Builder*) clearPackage;

- (NSArray*) dependencyList;
- (NSString*) dependencyAtIndex:(int32_t) index;
- (PBFileDescriptorProto_Builder*) replaceDependencyAtIndex:(int32_t) index with:(NSString*) value;
- (PBFileDescriptorProto_Builder*) addDependency:(NSString*) value;
- (PBFileDescriptorProto_Builder*) addAllDependency:(NSArray*) values;
- (PBFileDescriptorProto_Builder*) clearDependencyList;

- (NSArray*) messageTypeList;
- (PBDescriptorProto*) messageTypeAtIndex:(int32_t) index;
- (PBFileDescriptorProto_Builder*) replaceMessageTypeAtIndex:(int32_t) index with:(PBDescriptorProto*) value;
- (PBFileDescriptorProto_Builder*) addMessageType:(PBDescriptorProto*) value;
- (PBFileDescriptorProto_Builder*) addAllMessageType:(NSArray*) values;
- (PBFileDescriptorProto_Builder*) clearMessageTypeList;

- (NSArray*) enumTypeList;
- (PBEnumDescriptorProto*) enumTypeAtIndex:(int32_t) index;
- (PBFileDescriptorProto_Builder*) replaceEnumTypeAtIndex:(int32_t) index with:(PBEnumDescriptorProto*) value;
- (PBFileDescriptorProto_Builder*) addEnumType:(PBEnumDescriptorProto*) value;
- (PBFileDescriptorProto_Builder*) addAllEnumType:(NSArray*) values;
- (PBFileDescriptorProto_Builder*) clearEnumTypeList;

- (NSArray*) serviceList;
- (PBServiceDescriptorProto*) serviceAtIndex:(int32_t) index;
- (PBFileDescriptorProto_Builder*) replaceServiceAtIndex:(int32_t) index with:(PBServiceDescriptorProto*) value;
- (PBFileDescriptorProto_Builder*) addService:(PBServiceDescriptorProto*) value;
- (PBFileDescriptorProto_Builder*) addAllService:(NSArray*) values;
- (PBFileDescriptorProto_Builder*) clearServiceList;

- (NSArray*) extensionList;
- (PBFieldDescriptorProto*) extensionAtIndex:(int32_t) index;
- (PBFileDescriptorProto_Builder*) replaceExtensionAtIndex:(int32_t) index with:(PBFieldDescriptorProto*) value;
- (PBFileDescriptorProto_Builder*) addExtension:(PBFieldDescriptorProto*) value;
- (PBFileDescriptorProto_Builder*) addAllExtension:(NSArray*) values;
- (PBFileDescriptorProto_Builder*) clearExtensionList;

- (BOOL) hasOptions;
- (PBFileOptions*) options;
- (PBFileDescriptorProto_Builder*) setOptions:(PBFileOptions*) value;
- (PBFileDescriptorProto_Builder*) setOptionsBuilder:(PBFileOptions_Builder*) builderForValue;
- (PBFileDescriptorProto_Builder*) mergeOptions:(PBFileOptions*) value;
- (PBFileDescriptorProto_Builder*) clearOptions;
@end

@interface PBDescriptorProto : PBGeneratedMessage {
 @private
  BOOL hasName;
  BOOL hasOptions;
  NSString* name;
  PBMessageOptions* options;
  NSMutableArray* mutableFieldList;
  NSMutableArray* mutableExtensionList;
  NSMutableArray* mutableNestedTypeList;
  NSMutableArray* mutableEnumTypeList;
  NSMutableArray* mutableExtensionRangeList;
}
- (BOOL) hasName;
- (BOOL) hasOptions;
@property (readonly, retain) NSString* name;
@property (readonly, retain) PBMessageOptions* options;
- (NSArray*) fieldList;
- (PBFieldDescriptorProto*) fieldAtIndex:(int32_t) index;
- (NSArray*) extensionList;
- (PBFieldDescriptorProto*) extensionAtIndex:(int32_t) index;
- (NSArray*) nestedTypeList;
- (PBDescriptorProto*) nestedTypeAtIndex:(int32_t) index;
- (NSArray*) enumTypeList;
- (PBEnumDescriptorProto*) enumTypeAtIndex:(int32_t) index;
- (NSArray*) extensionRangeList;
- (PBDescriptorProto_ExtensionRange*) extensionRangeAtIndex:(int32_t) index;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBDescriptorProto*) defaultInstance;
- (PBDescriptorProto*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBDescriptorProto_Builder*) builder;
+ (PBDescriptorProto_Builder*) builder;
+ (PBDescriptorProto_Builder*) builderWithPrototype:(PBDescriptorProto*) prototype;

+ (PBDescriptorProto*) parseFromData:(NSData*) data;
+ (PBDescriptorProto*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBDescriptorProto*) parseFromInputStream:(NSInputStream*) input;
+ (PBDescriptorProto*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBDescriptorProto*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBDescriptorProto*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBDescriptorProto_ExtensionRange : PBGeneratedMessage {
 @private
  BOOL hasStart;
  BOOL hasEnd;
  int32_t start;
  int32_t end;
}
- (BOOL) hasStart;
- (BOOL) hasEnd;
@property (readonly) int32_t start;
@property (readonly) int32_t end;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBDescriptorProto_ExtensionRange*) defaultInstance;
- (PBDescriptorProto_ExtensionRange*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBDescriptorProto_ExtensionRange_Builder*) builder;
+ (PBDescriptorProto_ExtensionRange_Builder*) builder;
+ (PBDescriptorProto_ExtensionRange_Builder*) builderWithPrototype:(PBDescriptorProto_ExtensionRange*) prototype;

+ (PBDescriptorProto_ExtensionRange*) parseFromData:(NSData*) data;
+ (PBDescriptorProto_ExtensionRange*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBDescriptorProto_ExtensionRange*) parseFromInputStream:(NSInputStream*) input;
+ (PBDescriptorProto_ExtensionRange*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBDescriptorProto_ExtensionRange*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBDescriptorProto_ExtensionRange*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBDescriptorProto_ExtensionRange_Builder : PBGeneratedMessage_Builder {
 @private
  PBDescriptorProto_ExtensionRange* result;
}

- (PBDescriptor*) descriptor;
- (PBDescriptorProto_ExtensionRange*) defaultInstance;

- (PBDescriptorProto_ExtensionRange_Builder*) clear;
- (PBDescriptorProto_ExtensionRange_Builder*) clone;

- (PBDescriptorProto_ExtensionRange*) build;
- (PBDescriptorProto_ExtensionRange*) buildPartial;

- (PBDescriptorProto_ExtensionRange_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBDescriptorProto_ExtensionRange_Builder*) mergeFromPBDescriptorProto_ExtensionRange:(PBDescriptorProto_ExtensionRange*) other;
- (PBDescriptorProto_ExtensionRange_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBDescriptorProto_ExtensionRange_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasStart;
- (int32_t) start;
- (PBDescriptorProto_ExtensionRange_Builder*) setStart:(int32_t) value;
- (PBDescriptorProto_ExtensionRange_Builder*) clearStart;

- (BOOL) hasEnd;
- (int32_t) end;
- (PBDescriptorProto_ExtensionRange_Builder*) setEnd:(int32_t) value;
- (PBDescriptorProto_ExtensionRange_Builder*) clearEnd;
@end

@interface PBDescriptorProto_Builder : PBGeneratedMessage_Builder {
 @private
  PBDescriptorProto* result;
}

- (PBDescriptor*) descriptor;
- (PBDescriptorProto*) defaultInstance;

- (PBDescriptorProto_Builder*) clear;
- (PBDescriptorProto_Builder*) clone;

- (PBDescriptorProto*) build;
- (PBDescriptorProto*) buildPartial;

- (PBDescriptorProto_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBDescriptorProto_Builder*) mergeFromPBDescriptorProto:(PBDescriptorProto*) other;
- (PBDescriptorProto_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBDescriptorProto_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasName;
- (NSString*) name;
- (PBDescriptorProto_Builder*) setName:(NSString*) value;
- (PBDescriptorProto_Builder*) clearName;

- (NSArray*) fieldList;
- (PBFieldDescriptorProto*) fieldAtIndex:(int32_t) index;
- (PBDescriptorProto_Builder*) replaceFieldAtIndex:(int32_t) index with:(PBFieldDescriptorProto*) value;
- (PBDescriptorProto_Builder*) addField:(PBFieldDescriptorProto*) value;
- (PBDescriptorProto_Builder*) addAllField:(NSArray*) values;
- (PBDescriptorProto_Builder*) clearFieldList;

- (NSArray*) extensionList;
- (PBFieldDescriptorProto*) extensionAtIndex:(int32_t) index;
- (PBDescriptorProto_Builder*) replaceExtensionAtIndex:(int32_t) index with:(PBFieldDescriptorProto*) value;
- (PBDescriptorProto_Builder*) addExtension:(PBFieldDescriptorProto*) value;
- (PBDescriptorProto_Builder*) addAllExtension:(NSArray*) values;
- (PBDescriptorProto_Builder*) clearExtensionList;

- (NSArray*) nestedTypeList;
- (PBDescriptorProto*) nestedTypeAtIndex:(int32_t) index;
- (PBDescriptorProto_Builder*) replaceNestedTypeAtIndex:(int32_t) index with:(PBDescriptorProto*) value;
- (PBDescriptorProto_Builder*) addNestedType:(PBDescriptorProto*) value;
- (PBDescriptorProto_Builder*) addAllNestedType:(NSArray*) values;
- (PBDescriptorProto_Builder*) clearNestedTypeList;

- (NSArray*) enumTypeList;
- (PBEnumDescriptorProto*) enumTypeAtIndex:(int32_t) index;
- (PBDescriptorProto_Builder*) replaceEnumTypeAtIndex:(int32_t) index with:(PBEnumDescriptorProto*) value;
- (PBDescriptorProto_Builder*) addEnumType:(PBEnumDescriptorProto*) value;
- (PBDescriptorProto_Builder*) addAllEnumType:(NSArray*) values;
- (PBDescriptorProto_Builder*) clearEnumTypeList;

- (NSArray*) extensionRangeList;
- (PBDescriptorProto_ExtensionRange*) extensionRangeAtIndex:(int32_t) index;
- (PBDescriptorProto_Builder*) replaceExtensionRangeAtIndex:(int32_t) index with:(PBDescriptorProto_ExtensionRange*) value;
- (PBDescriptorProto_Builder*) addExtensionRange:(PBDescriptorProto_ExtensionRange*) value;
- (PBDescriptorProto_Builder*) addAllExtensionRange:(NSArray*) values;
- (PBDescriptorProto_Builder*) clearExtensionRangeList;

- (BOOL) hasOptions;
- (PBMessageOptions*) options;
- (PBDescriptorProto_Builder*) setOptions:(PBMessageOptions*) value;
- (PBDescriptorProto_Builder*) setOptionsBuilder:(PBMessageOptions_Builder*) builderForValue;
- (PBDescriptorProto_Builder*) mergeOptions:(PBMessageOptions*) value;
- (PBDescriptorProto_Builder*) clearOptions;
@end

@interface PBFieldDescriptorProto : PBGeneratedMessage {
 @private
  BOOL hasNumber;
  BOOL hasName;
  BOOL hasTypeName;
  BOOL hasExtendee;
  BOOL hasDefaultValue;
  BOOL hasOptions;
  BOOL hasLabel;
  BOOL hasType;
  int32_t number;
  NSString* name;
  NSString* typeName;
  NSString* extendee;
  NSString* defaultValue;
  PBFieldOptions* options;
  PBFieldDescriptorProto_Label* label;
  PBFieldDescriptorProto_Type* type;
}
- (BOOL) hasName;
- (BOOL) hasNumber;
- (BOOL) hasLabel;
- (BOOL) hasType;
- (BOOL) hasTypeName;
- (BOOL) hasExtendee;
- (BOOL) hasDefaultValue;
- (BOOL) hasOptions;
@property (readonly, retain) NSString* name;
@property (readonly) int32_t number;
@property (readonly, retain) PBFieldDescriptorProto_Label* label;
@property (readonly, retain) PBFieldDescriptorProto_Type* type;
@property (readonly, retain) NSString* typeName;
@property (readonly, retain) NSString* extendee;
@property (readonly, retain) NSString* defaultValue;
@property (readonly, retain) PBFieldOptions* options;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBFieldDescriptorProto*) defaultInstance;
- (PBFieldDescriptorProto*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBFieldDescriptorProto_Builder*) builder;
+ (PBFieldDescriptorProto_Builder*) builder;
+ (PBFieldDescriptorProto_Builder*) builderWithPrototype:(PBFieldDescriptorProto*) prototype;

+ (PBFieldDescriptorProto*) parseFromData:(NSData*) data;
+ (PBFieldDescriptorProto*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBFieldDescriptorProto*) parseFromInputStream:(NSInputStream*) input;
+ (PBFieldDescriptorProto*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBFieldDescriptorProto*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBFieldDescriptorProto*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBFieldDescriptorProto_Type : NSObject {
 @private
  int32_t index;
  int32_t value;
}
@property (readonly) int32_t index;
@property (readonly) int32_t value;
+ (PBFieldDescriptorProto_Type*) newWithIndex:(int32_t) index value:(int32_t) value;
+ (PBFieldDescriptorProto_Type*) TYPE_DOUBLE;
+ (PBFieldDescriptorProto_Type*) TYPE_FLOAT;
+ (PBFieldDescriptorProto_Type*) TYPE_INT64;
+ (PBFieldDescriptorProto_Type*) TYPE_UINT64;
+ (PBFieldDescriptorProto_Type*) TYPE_INT32;
+ (PBFieldDescriptorProto_Type*) TYPE_FIXED64;
+ (PBFieldDescriptorProto_Type*) TYPE_FIXED32;
+ (PBFieldDescriptorProto_Type*) TYPE_BOOL_;
+ (PBFieldDescriptorProto_Type*) TYPE_STRING;
+ (PBFieldDescriptorProto_Type*) TYPE_GROUP;
+ (PBFieldDescriptorProto_Type*) TYPE_MESSAGE;
+ (PBFieldDescriptorProto_Type*) TYPE_BYTES;
+ (PBFieldDescriptorProto_Type*) TYPE_UINT32;
+ (PBFieldDescriptorProto_Type*) TYPE_ENUM;
+ (PBFieldDescriptorProto_Type*) TYPE_SFIXED32;
+ (PBFieldDescriptorProto_Type*) TYPE_SFIXED64;
+ (PBFieldDescriptorProto_Type*) TYPE_SINT32;
+ (PBFieldDescriptorProto_Type*) TYPE_SINT64;

- (int32_t) number;
+ (PBFieldDescriptorProto_Type*) valueOf:(int32_t) value;
- (PBEnumValueDescriptor*) valueDescriptor;
- (PBEnumDescriptor*) descriptor;
+ (PBEnumDescriptor*) descriptor;

+ (PBFieldDescriptorProto_Type*) valueOfDescriptor:(PBEnumValueDescriptor*) desc;
@end

@interface PBFieldDescriptorProto_Label : NSObject {
 @private
  int32_t index;
  int32_t value;
}
@property (readonly) int32_t index;
@property (readonly) int32_t value;
+ (PBFieldDescriptorProto_Label*) newWithIndex:(int32_t) index value:(int32_t) value;
+ (PBFieldDescriptorProto_Label*) LABEL_OPTIONAL;
+ (PBFieldDescriptorProto_Label*) LABEL_REQUIRED;
+ (PBFieldDescriptorProto_Label*) LABEL_REPEATED;

- (int32_t) number;
+ (PBFieldDescriptorProto_Label*) valueOf:(int32_t) value;
- (PBEnumValueDescriptor*) valueDescriptor;
- (PBEnumDescriptor*) descriptor;
+ (PBEnumDescriptor*) descriptor;

+ (PBFieldDescriptorProto_Label*) valueOfDescriptor:(PBEnumValueDescriptor*) desc;
@end

@interface PBFieldDescriptorProto_Builder : PBGeneratedMessage_Builder {
 @private
  PBFieldDescriptorProto* result;
}

- (PBDescriptor*) descriptor;
- (PBFieldDescriptorProto*) defaultInstance;

- (PBFieldDescriptorProto_Builder*) clear;
- (PBFieldDescriptorProto_Builder*) clone;

- (PBFieldDescriptorProto*) build;
- (PBFieldDescriptorProto*) buildPartial;

- (PBFieldDescriptorProto_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBFieldDescriptorProto_Builder*) mergeFromPBFieldDescriptorProto:(PBFieldDescriptorProto*) other;
- (PBFieldDescriptorProto_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBFieldDescriptorProto_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasName;
- (NSString*) name;
- (PBFieldDescriptorProto_Builder*) setName:(NSString*) value;
- (PBFieldDescriptorProto_Builder*) clearName;

- (BOOL) hasNumber;
- (int32_t) number;
- (PBFieldDescriptorProto_Builder*) setNumber:(int32_t) value;
- (PBFieldDescriptorProto_Builder*) clearNumber;

- (BOOL) hasLabel;
- (PBFieldDescriptorProto_Label*) label;
- (PBFieldDescriptorProto_Builder*) setLabel:(PBFieldDescriptorProto_Label*) value;
- (PBFieldDescriptorProto_Builder*) clearLabel;

- (BOOL) hasType;
- (PBFieldDescriptorProto_Type*) type;
- (PBFieldDescriptorProto_Builder*) setType:(PBFieldDescriptorProto_Type*) value;
- (PBFieldDescriptorProto_Builder*) clearType;

- (BOOL) hasTypeName;
- (NSString*) typeName;
- (PBFieldDescriptorProto_Builder*) setTypeName:(NSString*) value;
- (PBFieldDescriptorProto_Builder*) clearTypeName;

- (BOOL) hasExtendee;
- (NSString*) extendee;
- (PBFieldDescriptorProto_Builder*) setExtendee:(NSString*) value;
- (PBFieldDescriptorProto_Builder*) clearExtendee;

- (BOOL) hasDefaultValue;
- (NSString*) defaultValue;
- (PBFieldDescriptorProto_Builder*) setDefaultValue:(NSString*) value;
- (PBFieldDescriptorProto_Builder*) clearDefaultValue;

- (BOOL) hasOptions;
- (PBFieldOptions*) options;
- (PBFieldDescriptorProto_Builder*) setOptions:(PBFieldOptions*) value;
- (PBFieldDescriptorProto_Builder*) setOptionsBuilder:(PBFieldOptions_Builder*) builderForValue;
- (PBFieldDescriptorProto_Builder*) mergeOptions:(PBFieldOptions*) value;
- (PBFieldDescriptorProto_Builder*) clearOptions;
@end

@interface PBEnumDescriptorProto : PBGeneratedMessage {
 @private
  BOOL hasName;
  BOOL hasOptions;
  NSString* name;
  PBEnumOptions* options;
  NSMutableArray* mutableValueList;
}
- (BOOL) hasName;
- (BOOL) hasOptions;
@property (readonly, retain) NSString* name;
@property (readonly, retain) PBEnumOptions* options;
- (NSArray*) valueList;
- (PBEnumValueDescriptorProto*) valueAtIndex:(int32_t) index;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBEnumDescriptorProto*) defaultInstance;
- (PBEnumDescriptorProto*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBEnumDescriptorProto_Builder*) builder;
+ (PBEnumDescriptorProto_Builder*) builder;
+ (PBEnumDescriptorProto_Builder*) builderWithPrototype:(PBEnumDescriptorProto*) prototype;

+ (PBEnumDescriptorProto*) parseFromData:(NSData*) data;
+ (PBEnumDescriptorProto*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBEnumDescriptorProto*) parseFromInputStream:(NSInputStream*) input;
+ (PBEnumDescriptorProto*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBEnumDescriptorProto*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBEnumDescriptorProto*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBEnumDescriptorProto_Builder : PBGeneratedMessage_Builder {
 @private
  PBEnumDescriptorProto* result;
}

- (PBDescriptor*) descriptor;
- (PBEnumDescriptorProto*) defaultInstance;

- (PBEnumDescriptorProto_Builder*) clear;
- (PBEnumDescriptorProto_Builder*) clone;

- (PBEnumDescriptorProto*) build;
- (PBEnumDescriptorProto*) buildPartial;

- (PBEnumDescriptorProto_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBEnumDescriptorProto_Builder*) mergeFromPBEnumDescriptorProto:(PBEnumDescriptorProto*) other;
- (PBEnumDescriptorProto_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBEnumDescriptorProto_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasName;
- (NSString*) name;
- (PBEnumDescriptorProto_Builder*) setName:(NSString*) value;
- (PBEnumDescriptorProto_Builder*) clearName;

- (NSArray*) valueList;
- (PBEnumValueDescriptorProto*) valueAtIndex:(int32_t) index;
- (PBEnumDescriptorProto_Builder*) replaceValueAtIndex:(int32_t) index with:(PBEnumValueDescriptorProto*) value;
- (PBEnumDescriptorProto_Builder*) addValue:(PBEnumValueDescriptorProto*) value;
- (PBEnumDescriptorProto_Builder*) addAllValue:(NSArray*) values;
- (PBEnumDescriptorProto_Builder*) clearValueList;

- (BOOL) hasOptions;
- (PBEnumOptions*) options;
- (PBEnumDescriptorProto_Builder*) setOptions:(PBEnumOptions*) value;
- (PBEnumDescriptorProto_Builder*) setOptionsBuilder:(PBEnumOptions_Builder*) builderForValue;
- (PBEnumDescriptorProto_Builder*) mergeOptions:(PBEnumOptions*) value;
- (PBEnumDescriptorProto_Builder*) clearOptions;
@end

@interface PBEnumValueDescriptorProto : PBGeneratedMessage {
 @private
  BOOL hasNumber;
  BOOL hasName;
  BOOL hasOptions;
  int32_t number;
  NSString* name;
  PBEnumValueOptions* options;
}
- (BOOL) hasName;
- (BOOL) hasNumber;
- (BOOL) hasOptions;
@property (readonly, retain) NSString* name;
@property (readonly) int32_t number;
@property (readonly, retain) PBEnumValueOptions* options;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBEnumValueDescriptorProto*) defaultInstance;
- (PBEnumValueDescriptorProto*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBEnumValueDescriptorProto_Builder*) builder;
+ (PBEnumValueDescriptorProto_Builder*) builder;
+ (PBEnumValueDescriptorProto_Builder*) builderWithPrototype:(PBEnumValueDescriptorProto*) prototype;

+ (PBEnumValueDescriptorProto*) parseFromData:(NSData*) data;
+ (PBEnumValueDescriptorProto*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBEnumValueDescriptorProto*) parseFromInputStream:(NSInputStream*) input;
+ (PBEnumValueDescriptorProto*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBEnumValueDescriptorProto*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBEnumValueDescriptorProto*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBEnumValueDescriptorProto_Builder : PBGeneratedMessage_Builder {
 @private
  PBEnumValueDescriptorProto* result;
}

- (PBDescriptor*) descriptor;
- (PBEnumValueDescriptorProto*) defaultInstance;

- (PBEnumValueDescriptorProto_Builder*) clear;
- (PBEnumValueDescriptorProto_Builder*) clone;

- (PBEnumValueDescriptorProto*) build;
- (PBEnumValueDescriptorProto*) buildPartial;

- (PBEnumValueDescriptorProto_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBEnumValueDescriptorProto_Builder*) mergeFromPBEnumValueDescriptorProto:(PBEnumValueDescriptorProto*) other;
- (PBEnumValueDescriptorProto_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBEnumValueDescriptorProto_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasName;
- (NSString*) name;
- (PBEnumValueDescriptorProto_Builder*) setName:(NSString*) value;
- (PBEnumValueDescriptorProto_Builder*) clearName;

- (BOOL) hasNumber;
- (int32_t) number;
- (PBEnumValueDescriptorProto_Builder*) setNumber:(int32_t) value;
- (PBEnumValueDescriptorProto_Builder*) clearNumber;

- (BOOL) hasOptions;
- (PBEnumValueOptions*) options;
- (PBEnumValueDescriptorProto_Builder*) setOptions:(PBEnumValueOptions*) value;
- (PBEnumValueDescriptorProto_Builder*) setOptionsBuilder:(PBEnumValueOptions_Builder*) builderForValue;
- (PBEnumValueDescriptorProto_Builder*) mergeOptions:(PBEnumValueOptions*) value;
- (PBEnumValueDescriptorProto_Builder*) clearOptions;
@end

@interface PBServiceDescriptorProto : PBGeneratedMessage {
 @private
  BOOL hasName;
  BOOL hasOptions;
  NSString* name;
  PBServiceOptions* options;
  NSMutableArray* mutableMethodList;
}
- (BOOL) hasName;
- (BOOL) hasOptions;
@property (readonly, retain) NSString* name;
@property (readonly, retain) PBServiceOptions* options;
- (NSArray*) methodList;
- (PBMethodDescriptorProto*) methodAtIndex:(int32_t) index;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBServiceDescriptorProto*) defaultInstance;
- (PBServiceDescriptorProto*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBServiceDescriptorProto_Builder*) builder;
+ (PBServiceDescriptorProto_Builder*) builder;
+ (PBServiceDescriptorProto_Builder*) builderWithPrototype:(PBServiceDescriptorProto*) prototype;

+ (PBServiceDescriptorProto*) parseFromData:(NSData*) data;
+ (PBServiceDescriptorProto*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBServiceDescriptorProto*) parseFromInputStream:(NSInputStream*) input;
+ (PBServiceDescriptorProto*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBServiceDescriptorProto*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBServiceDescriptorProto*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBServiceDescriptorProto_Builder : PBGeneratedMessage_Builder {
 @private
  PBServiceDescriptorProto* result;
}

- (PBDescriptor*) descriptor;
- (PBServiceDescriptorProto*) defaultInstance;

- (PBServiceDescriptorProto_Builder*) clear;
- (PBServiceDescriptorProto_Builder*) clone;

- (PBServiceDescriptorProto*) build;
- (PBServiceDescriptorProto*) buildPartial;

- (PBServiceDescriptorProto_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBServiceDescriptorProto_Builder*) mergeFromPBServiceDescriptorProto:(PBServiceDescriptorProto*) other;
- (PBServiceDescriptorProto_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBServiceDescriptorProto_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasName;
- (NSString*) name;
- (PBServiceDescriptorProto_Builder*) setName:(NSString*) value;
- (PBServiceDescriptorProto_Builder*) clearName;

- (NSArray*) methodList;
- (PBMethodDescriptorProto*) methodAtIndex:(int32_t) index;
- (PBServiceDescriptorProto_Builder*) replaceMethodAtIndex:(int32_t) index with:(PBMethodDescriptorProto*) value;
- (PBServiceDescriptorProto_Builder*) addMethod:(PBMethodDescriptorProto*) value;
- (PBServiceDescriptorProto_Builder*) addAllMethod:(NSArray*) values;
- (PBServiceDescriptorProto_Builder*) clearMethodList;

- (BOOL) hasOptions;
- (PBServiceOptions*) options;
- (PBServiceDescriptorProto_Builder*) setOptions:(PBServiceOptions*) value;
- (PBServiceDescriptorProto_Builder*) setOptionsBuilder:(PBServiceOptions_Builder*) builderForValue;
- (PBServiceDescriptorProto_Builder*) mergeOptions:(PBServiceOptions*) value;
- (PBServiceDescriptorProto_Builder*) clearOptions;
@end

@interface PBMethodDescriptorProto : PBGeneratedMessage {
 @private
  BOOL hasName;
  BOOL hasInputType;
  BOOL hasOutputType;
  BOOL hasOptions;
  NSString* name;
  NSString* inputType;
  NSString* outputType;
  PBMethodOptions* options;
}
- (BOOL) hasName;
- (BOOL) hasInputType;
- (BOOL) hasOutputType;
- (BOOL) hasOptions;
@property (readonly, retain) NSString* name;
@property (readonly, retain) NSString* inputType;
@property (readonly, retain) NSString* outputType;
@property (readonly, retain) PBMethodOptions* options;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBMethodDescriptorProto*) defaultInstance;
- (PBMethodDescriptorProto*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBMethodDescriptorProto_Builder*) builder;
+ (PBMethodDescriptorProto_Builder*) builder;
+ (PBMethodDescriptorProto_Builder*) builderWithPrototype:(PBMethodDescriptorProto*) prototype;

+ (PBMethodDescriptorProto*) parseFromData:(NSData*) data;
+ (PBMethodDescriptorProto*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBMethodDescriptorProto*) parseFromInputStream:(NSInputStream*) input;
+ (PBMethodDescriptorProto*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBMethodDescriptorProto*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBMethodDescriptorProto*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBMethodDescriptorProto_Builder : PBGeneratedMessage_Builder {
 @private
  PBMethodDescriptorProto* result;
}

- (PBDescriptor*) descriptor;
- (PBMethodDescriptorProto*) defaultInstance;

- (PBMethodDescriptorProto_Builder*) clear;
- (PBMethodDescriptorProto_Builder*) clone;

- (PBMethodDescriptorProto*) build;
- (PBMethodDescriptorProto*) buildPartial;

- (PBMethodDescriptorProto_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBMethodDescriptorProto_Builder*) mergeFromPBMethodDescriptorProto:(PBMethodDescriptorProto*) other;
- (PBMethodDescriptorProto_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBMethodDescriptorProto_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasName;
- (NSString*) name;
- (PBMethodDescriptorProto_Builder*) setName:(NSString*) value;
- (PBMethodDescriptorProto_Builder*) clearName;

- (BOOL) hasInputType;
- (NSString*) inputType;
- (PBMethodDescriptorProto_Builder*) setInputType:(NSString*) value;
- (PBMethodDescriptorProto_Builder*) clearInputType;

- (BOOL) hasOutputType;
- (NSString*) outputType;
- (PBMethodDescriptorProto_Builder*) setOutputType:(NSString*) value;
- (PBMethodDescriptorProto_Builder*) clearOutputType;

- (BOOL) hasOptions;
- (PBMethodOptions*) options;
- (PBMethodDescriptorProto_Builder*) setOptions:(PBMethodOptions*) value;
- (PBMethodDescriptorProto_Builder*) setOptionsBuilder:(PBMethodOptions_Builder*) builderForValue;
- (PBMethodDescriptorProto_Builder*) mergeOptions:(PBMethodOptions*) value;
- (PBMethodDescriptorProto_Builder*) clearOptions;
@end

@interface PBFileOptions : PBExtendableMessage {
 @private
  BOOL hasJavaMultipleFiles;
  BOOL hasJavaPackage;
  BOOL hasJavaOuterClassname;
  BOOL hasOptimizeFor;
  BOOL javaMultipleFiles;
  NSString* javaPackage;
  NSString* javaOuterClassname;
  PBFileOptions_OptimizeMode* optimizeFor;
  NSMutableArray* mutableUninterpretedOptionList;
}
- (BOOL) hasJavaPackage;
- (BOOL) hasJavaOuterClassname;
- (BOOL) hasJavaMultipleFiles;
- (BOOL) hasOptimizeFor;
@property (readonly, retain) NSString* javaPackage;
@property (readonly, retain) NSString* javaOuterClassname;
- (BOOL) javaMultipleFiles;
@property (readonly, retain) PBFileOptions_OptimizeMode* optimizeFor;
- (NSArray*) uninterpretedOptionList;
- (PBUninterpretedOption*) uninterpretedOptionAtIndex:(int32_t) index;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBFileOptions*) defaultInstance;
- (PBFileOptions*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBFileOptions_Builder*) builder;
+ (PBFileOptions_Builder*) builder;
+ (PBFileOptions_Builder*) builderWithPrototype:(PBFileOptions*) prototype;

+ (PBFileOptions*) parseFromData:(NSData*) data;
+ (PBFileOptions*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBFileOptions*) parseFromInputStream:(NSInputStream*) input;
+ (PBFileOptions*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBFileOptions*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBFileOptions*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBFileOptions_OptimizeMode : NSObject {
 @private
  int32_t index;
  int32_t value;
}
@property (readonly) int32_t index;
@property (readonly) int32_t value;
+ (PBFileOptions_OptimizeMode*) newWithIndex:(int32_t) index value:(int32_t) value;
+ (PBFileOptions_OptimizeMode*) SPEED;
+ (PBFileOptions_OptimizeMode*) CODE_SIZE;

- (int32_t) number;
+ (PBFileOptions_OptimizeMode*) valueOf:(int32_t) value;
- (PBEnumValueDescriptor*) valueDescriptor;
- (PBEnumDescriptor*) descriptor;
+ (PBEnumDescriptor*) descriptor;

+ (PBFileOptions_OptimizeMode*) valueOfDescriptor:(PBEnumValueDescriptor*) desc;
@end

@interface PBFileOptions_Builder : PBExtendableBuilder {
 @private
  PBFileOptions* result;
}

- (PBDescriptor*) descriptor;
- (PBFileOptions*) defaultInstance;

- (PBFileOptions_Builder*) clear;
- (PBFileOptions_Builder*) clone;

- (PBFileOptions*) build;
- (PBFileOptions*) buildPartial;

- (PBFileOptions_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBFileOptions_Builder*) mergeFromPBFileOptions:(PBFileOptions*) other;
- (PBFileOptions_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBFileOptions_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasJavaPackage;
- (NSString*) javaPackage;
- (PBFileOptions_Builder*) setJavaPackage:(NSString*) value;
- (PBFileOptions_Builder*) clearJavaPackage;

- (BOOL) hasJavaOuterClassname;
- (NSString*) javaOuterClassname;
- (PBFileOptions_Builder*) setJavaOuterClassname:(NSString*) value;
- (PBFileOptions_Builder*) clearJavaOuterClassname;

- (BOOL) hasJavaMultipleFiles;
- (BOOL) javaMultipleFiles;
- (PBFileOptions_Builder*) setJavaMultipleFiles:(BOOL) value;
- (PBFileOptions_Builder*) clearJavaMultipleFiles;

- (BOOL) hasOptimizeFor;
- (PBFileOptions_OptimizeMode*) optimizeFor;
- (PBFileOptions_Builder*) setOptimizeFor:(PBFileOptions_OptimizeMode*) value;
- (PBFileOptions_Builder*) clearOptimizeFor;

- (NSArray*) uninterpretedOptionList;
- (PBUninterpretedOption*) uninterpretedOptionAtIndex:(int32_t) index;
- (PBFileOptions_Builder*) replaceUninterpretedOptionAtIndex:(int32_t) index with:(PBUninterpretedOption*) value;
- (PBFileOptions_Builder*) addUninterpretedOption:(PBUninterpretedOption*) value;
- (PBFileOptions_Builder*) addAllUninterpretedOption:(NSArray*) values;
- (PBFileOptions_Builder*) clearUninterpretedOptionList;
@end

@interface PBMessageOptions : PBExtendableMessage {
 @private
  BOOL hasMessageSetWireFormat;
  BOOL messageSetWireFormat;
  NSMutableArray* mutableUninterpretedOptionList;
}
- (BOOL) hasMessageSetWireFormat;
- (BOOL) messageSetWireFormat;
- (NSArray*) uninterpretedOptionList;
- (PBUninterpretedOption*) uninterpretedOptionAtIndex:(int32_t) index;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBMessageOptions*) defaultInstance;
- (PBMessageOptions*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBMessageOptions_Builder*) builder;
+ (PBMessageOptions_Builder*) builder;
+ (PBMessageOptions_Builder*) builderWithPrototype:(PBMessageOptions*) prototype;

+ (PBMessageOptions*) parseFromData:(NSData*) data;
+ (PBMessageOptions*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBMessageOptions*) parseFromInputStream:(NSInputStream*) input;
+ (PBMessageOptions*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBMessageOptions*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBMessageOptions*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBMessageOptions_Builder : PBExtendableBuilder {
 @private
  PBMessageOptions* result;
}

- (PBDescriptor*) descriptor;
- (PBMessageOptions*) defaultInstance;

- (PBMessageOptions_Builder*) clear;
- (PBMessageOptions_Builder*) clone;

- (PBMessageOptions*) build;
- (PBMessageOptions*) buildPartial;

- (PBMessageOptions_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBMessageOptions_Builder*) mergeFromPBMessageOptions:(PBMessageOptions*) other;
- (PBMessageOptions_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBMessageOptions_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasMessageSetWireFormat;
- (BOOL) messageSetWireFormat;
- (PBMessageOptions_Builder*) setMessageSetWireFormat:(BOOL) value;
- (PBMessageOptions_Builder*) clearMessageSetWireFormat;

- (NSArray*) uninterpretedOptionList;
- (PBUninterpretedOption*) uninterpretedOptionAtIndex:(int32_t) index;
- (PBMessageOptions_Builder*) replaceUninterpretedOptionAtIndex:(int32_t) index with:(PBUninterpretedOption*) value;
- (PBMessageOptions_Builder*) addUninterpretedOption:(PBUninterpretedOption*) value;
- (PBMessageOptions_Builder*) addAllUninterpretedOption:(NSArray*) values;
- (PBMessageOptions_Builder*) clearUninterpretedOptionList;
@end

@interface PBFieldOptions : PBExtendableMessage {
 @private
  BOOL hasExperimentalMapKey;
  BOOL hasCtype;
  NSString* experimentalMapKey;
  PBFieldOptions_CType* ctype;
  NSMutableArray* mutableUninterpretedOptionList;
}
- (BOOL) hasCtype;
- (BOOL) hasExperimentalMapKey;
@property (readonly, retain) PBFieldOptions_CType* ctype;
@property (readonly, retain) NSString* experimentalMapKey;
- (NSArray*) uninterpretedOptionList;
- (PBUninterpretedOption*) uninterpretedOptionAtIndex:(int32_t) index;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBFieldOptions*) defaultInstance;
- (PBFieldOptions*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBFieldOptions_Builder*) builder;
+ (PBFieldOptions_Builder*) builder;
+ (PBFieldOptions_Builder*) builderWithPrototype:(PBFieldOptions*) prototype;

+ (PBFieldOptions*) parseFromData:(NSData*) data;
+ (PBFieldOptions*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBFieldOptions*) parseFromInputStream:(NSInputStream*) input;
+ (PBFieldOptions*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBFieldOptions*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBFieldOptions*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBFieldOptions_CType : NSObject {
 @private
  int32_t index;
  int32_t value;
}
@property (readonly) int32_t index;
@property (readonly) int32_t value;
+ (PBFieldOptions_CType*) newWithIndex:(int32_t) index value:(int32_t) value;
+ (PBFieldOptions_CType*) CORD;
+ (PBFieldOptions_CType*) STRING_PIECE;

- (int32_t) number;
+ (PBFieldOptions_CType*) valueOf:(int32_t) value;
- (PBEnumValueDescriptor*) valueDescriptor;
- (PBEnumDescriptor*) descriptor;
+ (PBEnumDescriptor*) descriptor;

+ (PBFieldOptions_CType*) valueOfDescriptor:(PBEnumValueDescriptor*) desc;
@end

@interface PBFieldOptions_Builder : PBExtendableBuilder {
 @private
  PBFieldOptions* result;
}

- (PBDescriptor*) descriptor;
- (PBFieldOptions*) defaultInstance;

- (PBFieldOptions_Builder*) clear;
- (PBFieldOptions_Builder*) clone;

- (PBFieldOptions*) build;
- (PBFieldOptions*) buildPartial;

- (PBFieldOptions_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBFieldOptions_Builder*) mergeFromPBFieldOptions:(PBFieldOptions*) other;
- (PBFieldOptions_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBFieldOptions_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasCtype;
- (PBFieldOptions_CType*) ctype;
- (PBFieldOptions_Builder*) setCtype:(PBFieldOptions_CType*) value;
- (PBFieldOptions_Builder*) clearCtype;

- (BOOL) hasExperimentalMapKey;
- (NSString*) experimentalMapKey;
- (PBFieldOptions_Builder*) setExperimentalMapKey:(NSString*) value;
- (PBFieldOptions_Builder*) clearExperimentalMapKey;

- (NSArray*) uninterpretedOptionList;
- (PBUninterpretedOption*) uninterpretedOptionAtIndex:(int32_t) index;
- (PBFieldOptions_Builder*) replaceUninterpretedOptionAtIndex:(int32_t) index with:(PBUninterpretedOption*) value;
- (PBFieldOptions_Builder*) addUninterpretedOption:(PBUninterpretedOption*) value;
- (PBFieldOptions_Builder*) addAllUninterpretedOption:(NSArray*) values;
- (PBFieldOptions_Builder*) clearUninterpretedOptionList;
@end

@interface PBEnumOptions : PBExtendableMessage {
 @private
  NSMutableArray* mutableUninterpretedOptionList;
}
- (NSArray*) uninterpretedOptionList;
- (PBUninterpretedOption*) uninterpretedOptionAtIndex:(int32_t) index;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBEnumOptions*) defaultInstance;
- (PBEnumOptions*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBEnumOptions_Builder*) builder;
+ (PBEnumOptions_Builder*) builder;
+ (PBEnumOptions_Builder*) builderWithPrototype:(PBEnumOptions*) prototype;

+ (PBEnumOptions*) parseFromData:(NSData*) data;
+ (PBEnumOptions*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBEnumOptions*) parseFromInputStream:(NSInputStream*) input;
+ (PBEnumOptions*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBEnumOptions*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBEnumOptions*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBEnumOptions_Builder : PBExtendableBuilder {
 @private
  PBEnumOptions* result;
}

- (PBDescriptor*) descriptor;
- (PBEnumOptions*) defaultInstance;

- (PBEnumOptions_Builder*) clear;
- (PBEnumOptions_Builder*) clone;

- (PBEnumOptions*) build;
- (PBEnumOptions*) buildPartial;

- (PBEnumOptions_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBEnumOptions_Builder*) mergeFromPBEnumOptions:(PBEnumOptions*) other;
- (PBEnumOptions_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBEnumOptions_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (NSArray*) uninterpretedOptionList;
- (PBUninterpretedOption*) uninterpretedOptionAtIndex:(int32_t) index;
- (PBEnumOptions_Builder*) replaceUninterpretedOptionAtIndex:(int32_t) index with:(PBUninterpretedOption*) value;
- (PBEnumOptions_Builder*) addUninterpretedOption:(PBUninterpretedOption*) value;
- (PBEnumOptions_Builder*) addAllUninterpretedOption:(NSArray*) values;
- (PBEnumOptions_Builder*) clearUninterpretedOptionList;
@end

@interface PBEnumValueOptions : PBExtendableMessage {
 @private
  NSMutableArray* mutableUninterpretedOptionList;
}
- (NSArray*) uninterpretedOptionList;
- (PBUninterpretedOption*) uninterpretedOptionAtIndex:(int32_t) index;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBEnumValueOptions*) defaultInstance;
- (PBEnumValueOptions*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBEnumValueOptions_Builder*) builder;
+ (PBEnumValueOptions_Builder*) builder;
+ (PBEnumValueOptions_Builder*) builderWithPrototype:(PBEnumValueOptions*) prototype;

+ (PBEnumValueOptions*) parseFromData:(NSData*) data;
+ (PBEnumValueOptions*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBEnumValueOptions*) parseFromInputStream:(NSInputStream*) input;
+ (PBEnumValueOptions*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBEnumValueOptions*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBEnumValueOptions*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBEnumValueOptions_Builder : PBExtendableBuilder {
 @private
  PBEnumValueOptions* result;
}

- (PBDescriptor*) descriptor;
- (PBEnumValueOptions*) defaultInstance;

- (PBEnumValueOptions_Builder*) clear;
- (PBEnumValueOptions_Builder*) clone;

- (PBEnumValueOptions*) build;
- (PBEnumValueOptions*) buildPartial;

- (PBEnumValueOptions_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBEnumValueOptions_Builder*) mergeFromPBEnumValueOptions:(PBEnumValueOptions*) other;
- (PBEnumValueOptions_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBEnumValueOptions_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (NSArray*) uninterpretedOptionList;
- (PBUninterpretedOption*) uninterpretedOptionAtIndex:(int32_t) index;
- (PBEnumValueOptions_Builder*) replaceUninterpretedOptionAtIndex:(int32_t) index with:(PBUninterpretedOption*) value;
- (PBEnumValueOptions_Builder*) addUninterpretedOption:(PBUninterpretedOption*) value;
- (PBEnumValueOptions_Builder*) addAllUninterpretedOption:(NSArray*) values;
- (PBEnumValueOptions_Builder*) clearUninterpretedOptionList;
@end

@interface PBServiceOptions : PBExtendableMessage {
 @private
  NSMutableArray* mutableUninterpretedOptionList;
}
- (NSArray*) uninterpretedOptionList;
- (PBUninterpretedOption*) uninterpretedOptionAtIndex:(int32_t) index;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBServiceOptions*) defaultInstance;
- (PBServiceOptions*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBServiceOptions_Builder*) builder;
+ (PBServiceOptions_Builder*) builder;
+ (PBServiceOptions_Builder*) builderWithPrototype:(PBServiceOptions*) prototype;

+ (PBServiceOptions*) parseFromData:(NSData*) data;
+ (PBServiceOptions*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBServiceOptions*) parseFromInputStream:(NSInputStream*) input;
+ (PBServiceOptions*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBServiceOptions*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBServiceOptions*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBServiceOptions_Builder : PBExtendableBuilder {
 @private
  PBServiceOptions* result;
}

- (PBDescriptor*) descriptor;
- (PBServiceOptions*) defaultInstance;

- (PBServiceOptions_Builder*) clear;
- (PBServiceOptions_Builder*) clone;

- (PBServiceOptions*) build;
- (PBServiceOptions*) buildPartial;

- (PBServiceOptions_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBServiceOptions_Builder*) mergeFromPBServiceOptions:(PBServiceOptions*) other;
- (PBServiceOptions_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBServiceOptions_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (NSArray*) uninterpretedOptionList;
- (PBUninterpretedOption*) uninterpretedOptionAtIndex:(int32_t) index;
- (PBServiceOptions_Builder*) replaceUninterpretedOptionAtIndex:(int32_t) index with:(PBUninterpretedOption*) value;
- (PBServiceOptions_Builder*) addUninterpretedOption:(PBUninterpretedOption*) value;
- (PBServiceOptions_Builder*) addAllUninterpretedOption:(NSArray*) values;
- (PBServiceOptions_Builder*) clearUninterpretedOptionList;
@end

@interface PBMethodOptions : PBExtendableMessage {
 @private
  NSMutableArray* mutableUninterpretedOptionList;
}
- (NSArray*) uninterpretedOptionList;
- (PBUninterpretedOption*) uninterpretedOptionAtIndex:(int32_t) index;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBMethodOptions*) defaultInstance;
- (PBMethodOptions*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBMethodOptions_Builder*) builder;
+ (PBMethodOptions_Builder*) builder;
+ (PBMethodOptions_Builder*) builderWithPrototype:(PBMethodOptions*) prototype;

+ (PBMethodOptions*) parseFromData:(NSData*) data;
+ (PBMethodOptions*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBMethodOptions*) parseFromInputStream:(NSInputStream*) input;
+ (PBMethodOptions*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBMethodOptions*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBMethodOptions*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBMethodOptions_Builder : PBExtendableBuilder {
 @private
  PBMethodOptions* result;
}

- (PBDescriptor*) descriptor;
- (PBMethodOptions*) defaultInstance;

- (PBMethodOptions_Builder*) clear;
- (PBMethodOptions_Builder*) clone;

- (PBMethodOptions*) build;
- (PBMethodOptions*) buildPartial;

- (PBMethodOptions_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBMethodOptions_Builder*) mergeFromPBMethodOptions:(PBMethodOptions*) other;
- (PBMethodOptions_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBMethodOptions_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (NSArray*) uninterpretedOptionList;
- (PBUninterpretedOption*) uninterpretedOptionAtIndex:(int32_t) index;
- (PBMethodOptions_Builder*) replaceUninterpretedOptionAtIndex:(int32_t) index with:(PBUninterpretedOption*) value;
- (PBMethodOptions_Builder*) addUninterpretedOption:(PBUninterpretedOption*) value;
- (PBMethodOptions_Builder*) addAllUninterpretedOption:(NSArray*) values;
- (PBMethodOptions_Builder*) clearUninterpretedOptionList;
@end

@interface PBUninterpretedOption : PBGeneratedMessage {
 @private
  BOOL hasDoubleValue;
  BOOL hasNegativeIntValue;
  BOOL hasPositiveIntValue;
  BOOL hasIdentifierValue;
  BOOL hasStringValue;
  Float64 doubleValue;
  int64_t negativeIntValue;
  int64_t positiveIntValue;
  NSString* identifierValue;
  NSData* stringValue;
  NSMutableArray* mutableNameList;
}
- (BOOL) hasIdentifierValue;
- (BOOL) hasPositiveIntValue;
- (BOOL) hasNegativeIntValue;
- (BOOL) hasDoubleValue;
- (BOOL) hasStringValue;
@property (readonly, retain) NSString* identifierValue;
@property (readonly) int64_t positiveIntValue;
@property (readonly) int64_t negativeIntValue;
@property (readonly) Float64 doubleValue;
@property (readonly, retain) NSData* stringValue;
- (NSArray*) nameList;
- (PBUninterpretedOption_NamePart*) nameAtIndex:(int32_t) index;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBUninterpretedOption*) defaultInstance;
- (PBUninterpretedOption*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBUninterpretedOption_Builder*) builder;
+ (PBUninterpretedOption_Builder*) builder;
+ (PBUninterpretedOption_Builder*) builderWithPrototype:(PBUninterpretedOption*) prototype;

+ (PBUninterpretedOption*) parseFromData:(NSData*) data;
+ (PBUninterpretedOption*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBUninterpretedOption*) parseFromInputStream:(NSInputStream*) input;
+ (PBUninterpretedOption*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBUninterpretedOption*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBUninterpretedOption*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBUninterpretedOption_NamePart : PBGeneratedMessage {
 @private
  BOOL hasIsExtension;
  BOOL hasNamePart;
  BOOL isExtension;
  NSString* namePart;
}
- (BOOL) hasNamePart;
- (BOOL) hasIsExtension;
@property (readonly, retain) NSString* namePart;
- (BOOL) isExtension;

+ (PBDescriptor*) descriptor;
- (PBDescriptor*) descriptor;
+ (PBUninterpretedOption_NamePart*) defaultInstance;
- (PBUninterpretedOption_NamePart*) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (PBUninterpretedOption_NamePart_Builder*) builder;
+ (PBUninterpretedOption_NamePart_Builder*) builder;
+ (PBUninterpretedOption_NamePart_Builder*) builderWithPrototype:(PBUninterpretedOption_NamePart*) prototype;

+ (PBUninterpretedOption_NamePart*) parseFromData:(NSData*) data;
+ (PBUninterpretedOption_NamePart*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBUninterpretedOption_NamePart*) parseFromInputStream:(NSInputStream*) input;
+ (PBUninterpretedOption_NamePart*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (PBUninterpretedOption_NamePart*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (PBUninterpretedOption_NamePart*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface PBUninterpretedOption_NamePart_Builder : PBGeneratedMessage_Builder {
 @private
  PBUninterpretedOption_NamePart* result;
}

- (PBDescriptor*) descriptor;
- (PBUninterpretedOption_NamePart*) defaultInstance;

- (PBUninterpretedOption_NamePart_Builder*) clear;
- (PBUninterpretedOption_NamePart_Builder*) clone;

- (PBUninterpretedOption_NamePart*) build;
- (PBUninterpretedOption_NamePart*) buildPartial;

- (PBUninterpretedOption_NamePart_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBUninterpretedOption_NamePart_Builder*) mergeFromPBUninterpretedOption_NamePart:(PBUninterpretedOption_NamePart*) other;
- (PBUninterpretedOption_NamePart_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBUninterpretedOption_NamePart_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasNamePart;
- (NSString*) namePart;
- (PBUninterpretedOption_NamePart_Builder*) setNamePart:(NSString*) value;
- (PBUninterpretedOption_NamePart_Builder*) clearNamePart;

- (BOOL) hasIsExtension;
- (BOOL) isExtension;
- (PBUninterpretedOption_NamePart_Builder*) setIsExtension:(BOOL) value;
- (PBUninterpretedOption_NamePart_Builder*) clearIsExtension;
@end

@interface PBUninterpretedOption_Builder : PBGeneratedMessage_Builder {
 @private
  PBUninterpretedOption* result;
}

- (PBDescriptor*) descriptor;
- (PBUninterpretedOption*) defaultInstance;

- (PBUninterpretedOption_Builder*) clear;
- (PBUninterpretedOption_Builder*) clone;

- (PBUninterpretedOption*) build;
- (PBUninterpretedOption*) buildPartial;

- (PBUninterpretedOption_Builder*) mergeFromMessage:(id<PBMessage>) other;
- (PBUninterpretedOption_Builder*) mergeFromPBUninterpretedOption:(PBUninterpretedOption*) other;
- (PBUninterpretedOption_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (PBUninterpretedOption_Builder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (NSArray*) nameList;
- (PBUninterpretedOption_NamePart*) nameAtIndex:(int32_t) index;
- (PBUninterpretedOption_Builder*) replaceNameAtIndex:(int32_t) index with:(PBUninterpretedOption_NamePart*) value;
- (PBUninterpretedOption_Builder*) addName:(PBUninterpretedOption_NamePart*) value;
- (PBUninterpretedOption_Builder*) addAllName:(NSArray*) values;
- (PBUninterpretedOption_Builder*) clearNameList;

- (BOOL) hasIdentifierValue;
- (NSString*) identifierValue;
- (PBUninterpretedOption_Builder*) setIdentifierValue:(NSString*) value;
- (PBUninterpretedOption_Builder*) clearIdentifierValue;

- (BOOL) hasPositiveIntValue;
- (int64_t) positiveIntValue;
- (PBUninterpretedOption_Builder*) setPositiveIntValue:(int64_t) value;
- (PBUninterpretedOption_Builder*) clearPositiveIntValue;

- (BOOL) hasNegativeIntValue;
- (int64_t) negativeIntValue;
- (PBUninterpretedOption_Builder*) setNegativeIntValue:(int64_t) value;
- (PBUninterpretedOption_Builder*) clearNegativeIntValue;

- (BOOL) hasDoubleValue;
- (Float64) doubleValue;
- (PBUninterpretedOption_Builder*) setDoubleValue:(Float64) value;
- (PBUninterpretedOption_Builder*) clearDoubleValue;

- (BOOL) hasStringValue;
- (NSData*) stringValue;
- (PBUninterpretedOption_Builder*) setStringValue:(NSData*) value;
- (PBUninterpretedOption_Builder*) clearStringValue;
@end