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

// Author: kenton@google.com (Kenton Varda)
//  Based on original Protocol Buffers design by
//  Sanjay Ghemawat, Jeff Dean, and others.

#include <map>
#include <string>

#include <google/protobuf/compiler/objectivec/objectivec_primitive_field.h>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/compiler/objectivec/objectivec_helpers.h>
#include <google/protobuf/io/printer.h>
#include <google/protobuf/stubs/strutil.h>
#include <google/protobuf/stubs/substitute.h>

namespace google { namespace protobuf { namespace compiler { namespace objectivec {

  namespace {

    const char* PrimitiveTypeName(ObjectiveCType type) {
      switch (type) {
        case OBJECTIVECTYPE_INT    : return "int32_t";
        case OBJECTIVECTYPE_LONG   : return "int64_t";
        case OBJECTIVECTYPE_FLOAT  : return "Float32";
        case OBJECTIVECTYPE_DOUBLE : return "Float64";
        case OBJECTIVECTYPE_BOOLEAN: return "BOOL";
        case OBJECTIVECTYPE_STRING : return "NSString";
        case OBJECTIVECTYPE_DATA   : return "NSData";
        case OBJECTIVECTYPE_ENUM   : return NULL;
        case OBJECTIVECTYPE_MESSAGE: return NULL;
      }

      GOOGLE_LOG(FATAL) << "Can't get here.";
      return NULL;
    }

    const char* GetCapitalizedType(const FieldDescriptor* field) {
      switch (field->type()) {
        case FieldDescriptor::TYPE_INT32   : return "Int32"   ;
        case FieldDescriptor::TYPE_UINT32  : return "UInt32"  ;
        case FieldDescriptor::TYPE_SINT32  : return "SInt32"  ;
        case FieldDescriptor::TYPE_FIXED32 : return "Fixed32" ;
        case FieldDescriptor::TYPE_SFIXED32: return "SFixed32";
        case FieldDescriptor::TYPE_INT64   : return "Int64"   ;
        case FieldDescriptor::TYPE_UINT64  : return "UInt64"  ;
        case FieldDescriptor::TYPE_SINT64  : return "SInt64"  ;
        case FieldDescriptor::TYPE_FIXED64 : return "Fixed64" ;
        case FieldDescriptor::TYPE_SFIXED64: return "SFixed64";
        case FieldDescriptor::TYPE_FLOAT   : return "Float"   ;
        case FieldDescriptor::TYPE_DOUBLE  : return "Double"  ;
        case FieldDescriptor::TYPE_BOOL    : return "Bool"    ;
        case FieldDescriptor::TYPE_STRING  : return "String"  ;
        case FieldDescriptor::TYPE_BYTES   : return "Data"   ;
        case FieldDescriptor::TYPE_ENUM    : return "Enum"    ;
        case FieldDescriptor::TYPE_GROUP   : return "Group"   ;
        case FieldDescriptor::TYPE_MESSAGE : return "Message" ;
      }

      GOOGLE_LOG(FATAL) << "Can't get here.";
      return NULL;
    }

    void SetPrimitiveVariables(const FieldDescriptor* descriptor,
      map<string, string>* variables) {
        (*variables)["classname"] = ClassName(descriptor->containing_type());
        (*variables)["name"] = UnderscoresToCamelCase(descriptor);
        (*variables)["capitalized_name"] = UnderscoresToCapitalizedCamelCase(descriptor);
        (*variables)["list_name"] = UnderscoresToCamelCase(descriptor) + "List";
        (*variables)["mutable_list_name"] = "mutable" + UnderscoresToCapitalizedCamelCase(descriptor) + "List";
        (*variables)["number"] = SimpleItoa(descriptor->number());
        (*variables)["type"] = PrimitiveTypeName(GetObjectiveCType(descriptor));

        if (IsPrimitiveType(GetObjectiveCType(descriptor))) {
          (*variables)["storage_type"] = PrimitiveTypeName(GetObjectiveCType(descriptor));
        } else {
          (*variables)["storage_type"] = string(PrimitiveTypeName(GetObjectiveCType(descriptor))) + "*";
        }

        (*variables)["boxed_type"] = BoxedPrimitiveTypeName(GetObjectiveCType(descriptor));
        (*variables)["default"] = DefaultValue(descriptor);
        (*variables)["capitalized_type"] = GetCapitalizedType(descriptor);
        (*variables)["boxed_value"] = BoxValue(descriptor, "value");

        string unboxed_value = "value";
        switch (GetObjectiveCType(descriptor)) {
          case OBJECTIVECTYPE_INT:
            unboxed_value = "[value intValue]";
            break;
          case OBJECTIVECTYPE_LONG:
            unboxed_value = "[value longLongValue]";
            break;
          case OBJECTIVECTYPE_FLOAT:
            unboxed_value = "[value floatValue]";
            break;
          case OBJECTIVECTYPE_DOUBLE:
            unboxed_value = "[value doubleValue]";
            break;
          case OBJECTIVECTYPE_BOOLEAN:
            unboxed_value = "[value boolValue]";
            break;
        } 

        (*variables)["unboxed_value"] = unboxed_value;
    }
  }  // namespace


  PrimitiveFieldGenerator::PrimitiveFieldGenerator(const FieldDescriptor* descriptor)
    : descriptor_(descriptor) {
      SetPrimitiveVariables(descriptor, &variables_);
  }


  PrimitiveFieldGenerator::~PrimitiveFieldGenerator() {
  }


  void PrimitiveFieldGenerator::GenerateHasFieldHeader(io::Printer* printer) const {
    printer->Print(variables_, "BOOL has$capitalized_name$_:1;\n");
  }


  void PrimitiveFieldGenerator::GenerateFieldHeader(io::Printer* printer) const {
    if (descriptor_->type() ==  FieldDescriptor::TYPE_BOOL) {
      printer->Print(variables_, "$storage_type$ $name$_:1;\n");
    } else {
      printer->Print(variables_, "$storage_type$ $name$;\n");
    }
  }


  void PrimitiveFieldGenerator::GenerateHasPropertyHeader(io::Printer* printer) const {
    printer->Print(variables_, "- (BOOL) has$capitalized_name$;\n");
  }

  void PrimitiveFieldGenerator::GeneratePropertyHeader(io::Printer* printer) const {
    if (IsReferenceType(GetObjectiveCType(descriptor_))) {
      printer->Print(variables_,
        "@property (readonly, retain) $storage_type$ $name$;\n");
    } else if (GetObjectiveCType(descriptor_) == OBJECTIVECTYPE_BOOLEAN) {
      printer->Print(variables_,
        "- (BOOL) $name$;\n");
    } else {
      printer->Print(variables_,
        "@property (readonly) $storage_type$ $name$;\n");
    }
  }


  void PrimitiveFieldGenerator::GenerateExtensionSource(io::Printer* printer) const {
    if (IsReferenceType(GetObjectiveCType(descriptor_))) {
      printer->Print(variables_,
        "@property (retain) $storage_type$ $name$;\n");
    } else {
      printer->Print(variables_,
        "@property $storage_type$ $name$;\n");
    }
  }


  void PrimitiveFieldGenerator::GenerateSynthesizeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "- (BOOL) has$capitalized_name$ {\n"
      "  return !!has$capitalized_name$_;\n"
      "}\n"
      "- (void) setHas$capitalized_name$:(BOOL) value {\n"
      "  has$capitalized_name$_ = !!value;\n"
      "}\n");

    if (GetObjectiveCType(descriptor_) == OBJECTIVECTYPE_BOOLEAN) {
      printer->Print(variables_,
        "- (BOOL) $name$ {\n"
        "  return !!$name$_;\n"
        "}\n"
        "- (void) set$capitalized_name$:(BOOL) value {\n"
        "  $name$_ = !!value;\n"
        "}\n");
    } else {
      printer->Print(variables_, "@synthesize $name$;\n");
    }
  }


  void PrimitiveFieldGenerator::GenerateDeallocSource(io::Printer* printer) const {
    if (IsReferenceType(GetObjectiveCType(descriptor_))) {
      printer->Print(variables_,
        "self.$name$ = nil;\n");
    }
  }


  void PrimitiveFieldGenerator::GenerateInitializationSource(io::Printer* printer) const {
    printer->Print(variables_,
      "self.$name$ = $default$;\n");
  }


  void PrimitiveFieldGenerator::GenerateMembersHeader(io::Printer* printer) const {
  }


  void PrimitiveFieldGenerator::GenerateMembersSource(io::Printer* printer) const {
  }


  void PrimitiveFieldGenerator::GenerateBuilderMembersHeader(io::Printer* printer) const {
    printer->Print(variables_,
      "- (BOOL) has$capitalized_name$;\n"
      "- ($storage_type$) $name$;\n"
      "- ($classname$_Builder*) set$capitalized_name$:($storage_type$) value;\n"
      "- ($classname$_Builder*) clear$capitalized_name$;\n");
  }


  void PrimitiveFieldGenerator::GenerateMergingCodeHeader(io::Printer* printer) const {
  }


  void PrimitiveFieldGenerator::GenerateBuildingCodeHeader(io::Printer* printer) const {
  }


  void PrimitiveFieldGenerator::GenerateParsingCodeHeader(io::Printer* printer) const {
  }


  void PrimitiveFieldGenerator::GenerateSerializationCodeHeader(io::Printer* printer) const {
  }


  void PrimitiveFieldGenerator::GenerateSerializedSizeCodeHeader(io::Printer* printer) const {
  }


  void PrimitiveFieldGenerator::GenerateBuilderMembersSource(io::Printer* printer) const {
    printer->Print(variables_,
      "- (BOOL) has$capitalized_name$ {\n"
      "  return result.has$capitalized_name$;\n"
      "}\n"
      "- ($storage_type$) $name$ {\n"
      "  return result.$name$;\n"
      "}\n"
      "- ($classname$_Builder*) set$capitalized_name$:($storage_type$) value {\n"
      "  result.has$capitalized_name$ = YES;\n"
      "  result.$name$ = value;\n"
      "  return self;\n"
      "}\n"
      "- ($classname$_Builder*) clear$capitalized_name$ {\n"
      "  result.has$capitalized_name$ = NO;\n"
      "  result.$name$ = $default$;\n"
      "  return self;\n"
      "}\n");
  }


  void PrimitiveFieldGenerator::GenerateMergingCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "if (other.has$capitalized_name$) {\n"
      "  [self set$capitalized_name$:other.$name$];\n"
      "}\n");
  }

  void PrimitiveFieldGenerator::GenerateBuildingCodeSource(io::Printer* printer) const {
  }

  void PrimitiveFieldGenerator::GenerateParsingCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "[self set$capitalized_name$:[input read$capitalized_type$]];\n");
  }

  void PrimitiveFieldGenerator::GenerateSerializationCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "if (self.has$capitalized_name$) {\n"
      "  [output write$capitalized_type$:$number$ value:self.$name$];\n"
      "}\n");
  }

  void PrimitiveFieldGenerator::GenerateSerializedSizeCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "if (self.has$capitalized_name$) {\n"
      "  size += compute$capitalized_type$Size($number$, self.$name$);\n"
      "}\n");
  }

  string PrimitiveFieldGenerator::GetBoxedType() const {
    return BoxedPrimitiveTypeName(GetObjectiveCType(descriptor_));
  }


  RepeatedPrimitiveFieldGenerator::RepeatedPrimitiveFieldGenerator(const FieldDescriptor* descriptor)
    : descriptor_(descriptor) {
      SetPrimitiveVariables(descriptor, &variables_);
  }


  RepeatedPrimitiveFieldGenerator::~RepeatedPrimitiveFieldGenerator() {
  }


  void RepeatedPrimitiveFieldGenerator::GenerateHasFieldHeader(io::Printer* printer) const {
  }


  void RepeatedPrimitiveFieldGenerator::GenerateFieldHeader(io::Printer* printer) const {
    printer->Print(variables_, "NSMutableArray* $mutable_list_name$;\n");
  }


  void RepeatedPrimitiveFieldGenerator::GenerateHasPropertyHeader(io::Printer* printer) const {
  }


  void RepeatedPrimitiveFieldGenerator::GeneratePropertyHeader(io::Printer* printer) const {
  }


  void RepeatedPrimitiveFieldGenerator::GenerateExtensionSource(io::Printer* printer) const {
    printer->Print(variables_,
      "@property (retain) NSMutableArray* $mutable_list_name$;\n");
  }


  void RepeatedPrimitiveFieldGenerator::GenerateSynthesizeSource(io::Printer* printer) const {
    printer->Print(variables_, "@synthesize $mutable_list_name$;\n");
  }


  void RepeatedPrimitiveFieldGenerator::GenerateDeallocSource(io::Printer* printer) const {
    printer->Print(variables_, "self.$mutable_list_name$ = nil;\n");
  }


  void RepeatedPrimitiveFieldGenerator::GenerateInitializationSource(io::Printer* printer) const {;
  }


  void RepeatedPrimitiveFieldGenerator::GenerateMembersHeader(io::Printer* printer) const {
    printer->Print(variables_,
      "- (NSArray*) $list_name$;\n"
      "- ($storage_type$) $name$AtIndex:(int32_t) index;\n");
  }

  void RepeatedPrimitiveFieldGenerator::GenerateBuilderMembersHeader(io::Printer* printer) const {
    printer->Print(variables_,
      "- (NSArray*) $list_name$;\n"
      "- ($storage_type$) $name$AtIndex:(int32_t) index;\n"
      "- ($classname$_Builder*) replace$capitalized_name$AtIndex:(int32_t) index with:($storage_type$) value;\n"
      "- ($classname$_Builder*) add$capitalized_name$:($storage_type$) value;\n"
      "- ($classname$_Builder*) addAll$capitalized_name$:(NSArray*) values;\n"
      "- ($classname$_Builder*) clear$capitalized_name$List;\n");
  }


  void RepeatedPrimitiveFieldGenerator::GenerateMergingCodeHeader(io::Printer* printer) const {
  }


  void RepeatedPrimitiveFieldGenerator::GenerateBuildingCodeHeader(io::Printer* printer) const {
  }


  void RepeatedPrimitiveFieldGenerator::GenerateParsingCodeHeader(io::Printer* printer) const {
  }


  void RepeatedPrimitiveFieldGenerator::GenerateSerializationCodeHeader(io::Printer* printer) const {
  }


  void RepeatedPrimitiveFieldGenerator::GenerateSerializedSizeCodeHeader(io::Printer* printer) const {
  }


  void RepeatedPrimitiveFieldGenerator::GenerateMembersSource(io::Printer* printer) const {
    printer->Print(variables_,
      "- (NSArray*) $list_name$ {\n"
      "  return $mutable_list_name$;\n"
      "}\n"
      "- ($storage_type$) $name$AtIndex:(int32_t) index {\n"
      "  id value = [$mutable_list_name$ objectAtIndex:index];\n"
      "  return $unboxed_value$;\n"
      "}\n");
  }

  void RepeatedPrimitiveFieldGenerator::GenerateBuilderMembersSource(io::Printer* printer) const {
    printer->Print(variables_,
      "- (NSArray*) $list_name$ {\n"
      "  if (result.$mutable_list_name$ == nil) {\n"
      "    return [NSArray array];\n"
      "  }\n"
      "  return result.$mutable_list_name$;\n"
      "}\n"
      "- ($storage_type$) $name$AtIndex:(int32_t) index {\n"
      "  return [result $name$AtIndex:index];\n"
      "}\n"
      "- ($classname$_Builder*) replace$capitalized_name$AtIndex:(int32_t) index with:($storage_type$) value {\n"
      "  [result.$mutable_list_name$ replaceObjectAtIndex:index withObject:$boxed_value$];\n"
      "  return self;\n"
      "}\n"
      "- ($classname$_Builder*) add$capitalized_name$:($storage_type$) value {\n"
      "  if (result.$mutable_list_name$ == nil) {\n"
      "    result.$mutable_list_name$ = [NSMutableArray array];\n"
      "  }\n"
      "  [result.$mutable_list_name$ addObject:$boxed_value$];\n"
      "  return self;\n"
      "}\n"
      "- ($classname$_Builder*) addAll$capitalized_name$:(NSArray*) values {\n"
      "  if (result.$mutable_list_name$ == nil) {\n"
      "    result.$mutable_list_name$ = [NSMutableArray array];\n"
      "  }\n"
      "  [result.$mutable_list_name$ addObjectsFromArray:values];\n"
      "  return self;\n"
      "}\n"
      "- ($classname$_Builder*) clear$capitalized_name$List {\n"
      "  result.$mutable_list_name$ = nil;\n"
      "  return self;\n"
      "}\n");
  }

  void RepeatedPrimitiveFieldGenerator::GenerateMergingCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "if (other.$mutable_list_name$.count > 0) {\n"
      "  if (result.$mutable_list_name$ == nil) {\n"
      "    result.$mutable_list_name$ = [NSMutableArray array];\n"
      "  }\n"
      "  [result.$mutable_list_name$ addObjectsFromArray:other.$mutable_list_name$];\n"
      "}\n");
  }


  void RepeatedPrimitiveFieldGenerator::GenerateBuildingCodeSource(io::Printer* printer) const {
  }


  void RepeatedPrimitiveFieldGenerator::GenerateParsingCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "[self add$capitalized_name$:[input read$capitalized_type$]];\n");
  }


  void RepeatedPrimitiveFieldGenerator::GenerateSerializationCodeSource(io::Printer* printer) const {
    if (ReturnsPrimitiveType(descriptor_)) {
      printer->Print(variables_,
        "for (NSNumber* value in self.$mutable_list_name$) {\n"
        "  [output write$capitalized_type$:$number$ value:$unboxed_value$];\n"
        "}\n");
    } else {
      printer->Print(variables_,
        "for ($storage_type$ element in self.$mutable_list_name$) {\n"
        "  [output write$capitalized_type$:$number$ value:element];\n"
        "}\n");
    }
  }

  void RepeatedPrimitiveFieldGenerator::GenerateSerializedSizeCodeSource(io::Printer* printer) const {
    if (ReturnsPrimitiveType(descriptor_)) {
      printer->Print(variables_,
        "for (NSNumber* value in self.$mutable_list_name$) {\n"
        "  size += compute$capitalized_type$Size($number$, $unboxed_value$);\n"
        "}\n");
    } else {
      printer->Print(variables_,
        "for ($storage_type$ element in self.$mutable_list_name$) {\n"
        "  size += compute$capitalized_type$Size($number$, element);\n"
        "}\n");
    }
  }


  string RepeatedPrimitiveFieldGenerator::GetBoxedType() const {
    return BoxedPrimitiveTypeName(GetObjectiveCType(descriptor_));
  }
}  // namespace objectivec
}  // namespace compiler
}  // namespace protobuf
}  // namespace google