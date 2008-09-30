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

#ifndef GOOGLE_PROTOBUF_COMPILER_OBJECTIVEC_HELPERS_H__
#define GOOGLE_PROTOBUF_COMPILER_OBJECTIVEC_HELPERS_H__

#include <string>
#include <google/protobuf/descriptor.h>

namespace google {
namespace protobuf {
namespace compiler {
namespace objectivec {

// Commonly-used separator comments.  Thick is a line of '=', thin is a line
// of '-'.
extern const char kThickSeparator[];
extern const char kThinSeparator[];

// Converts the field's name to camel-case, e.g. "foo_bar_baz" becomes
// "fooBarBaz" or "FooBarBaz", respectively.
string UnderscoresToCamelCase(const FieldDescriptor* field);
string UnderscoresToCapitalizedCamelCase(const FieldDescriptor* field);

// Similar, but for method names.  (Typically, this merely has the effect
// of lower-casing the first letter of the name.)
string UnderscoresToCamelCase(const MethodDescriptor* method);

// Strips ".proto" or ".protodevel" from the end of a filename.
string StripProto(const string& filename);

// Gets the unqualified class name for the file.  Each .proto file becomes a
// single ObjectiveC class, with all its contents nested in that class.
string FileClassName(const FileDescriptor* file);

// Returns the file's ObjectiveC package name.
string FileObjectiveCPackage(const FileDescriptor* file);

// Converts the given fully-qualified name in the proto namespace to its
// fully-qualified name in the ObjectiveC namespace, given that it is in the given
// file.
string ToObjectiveCName(const string& full_name, const FileDescriptor* file);

// These return the fully-qualified class name corresponding to the given
// descriptor.
inline string ClassName(const Descriptor* descriptor) {
  return ToObjectiveCName(descriptor->name(), descriptor->file());
}
inline string ClassName(const EnumDescriptor* descriptor) {
  return ToObjectiveCName(descriptor->name(), descriptor->file());
}
inline string ClassName(const ServiceDescriptor* descriptor) {
  return ToObjectiveCName(descriptor->name(), descriptor->file());
}
string ClassName(const FileDescriptor* descriptor);


string SafeName(const string& name);

enum ObjectiveCType {
  OBJECTIVECTYPE_INT,
  OBJECTIVECTYPE_LONG,
  OBJECTIVECTYPE_FLOAT,
  OBJECTIVECTYPE_DOUBLE,
  OBJECTIVECTYPE_BOOLEAN,
  OBJECTIVECTYPE_STRING,
  OBJECTIVECTYPE_DATA,
  OBJECTIVECTYPE_ENUM,
  OBJECTIVECTYPE_MESSAGE
};

ObjectiveCType GetObjectiveCType(FieldDescriptor::Type field_type);

inline ObjectiveCType GetObjectiveCType(const FieldDescriptor* field) {
  return GetObjectiveCType(field->type());
}

// Get the fully-qualified class name for a boxed primitive type, e.g.
// "objectivec.lang.Integer" for OBJECTIVECTYPE_INT.  Returns NULL for enum and message
// types.
const char* BoxedPrimitiveTypeName(ObjectiveCType type);

bool IsPrimitiveType(ObjectiveCType type);
bool IsReferenceType(ObjectiveCType type);

}  // namespace objectivec
}  // namespace compiler
}  // namespace protobuf

}  // namespace google
#endif  // GOOGLE_PROTOBUF_COMPILER_OBJECTIVEC_HELPERS_H__
