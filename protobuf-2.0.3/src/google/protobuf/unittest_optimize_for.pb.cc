// Generated by the protocol buffer compiler.  DO NOT EDIT!

#include "google/protobuf/unittest_optimize_for.pb.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format_inl.h>

namespace protobuf_unittest {

namespace {

const ::google::protobuf::Descriptor* TestOptimizedForSize_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  TestOptimizedForSize_reflection_ = NULL;
const ::google::protobuf::Descriptor* TestRequiredOptimizedForSize_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  TestRequiredOptimizedForSize_reflection_ = NULL;
const ::google::protobuf::Descriptor* TestOptionalOptimizedForSize_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  TestOptionalOptimizedForSize_reflection_ = NULL;

}  // namespace


void protobuf_BuildDesc_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto_AssignGlobalDescriptors(const ::google::protobuf::FileDescriptor* file) {
  TestOptimizedForSize_descriptor_ = file->message_type(0);
  TestOptimizedForSize::default_instance_ = new TestOptimizedForSize();
  static const int TestOptimizedForSize_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TestOptimizedForSize, i_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TestOptimizedForSize, msg_),
  };
  TestOptimizedForSize_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      TestOptimizedForSize_descriptor_,
      TestOptimizedForSize::default_instance_,
      TestOptimizedForSize_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TestOptimizedForSize, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TestOptimizedForSize, _unknown_fields_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TestOptimizedForSize, _extensions_),
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(TestOptimizedForSize));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    TestOptimizedForSize_descriptor_, TestOptimizedForSize::default_instance_);
  TestRequiredOptimizedForSize_descriptor_ = file->message_type(1);
  TestRequiredOptimizedForSize::default_instance_ = new TestRequiredOptimizedForSize();
  static const int TestRequiredOptimizedForSize_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TestRequiredOptimizedForSize, x_),
  };
  TestRequiredOptimizedForSize_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      TestRequiredOptimizedForSize_descriptor_,
      TestRequiredOptimizedForSize::default_instance_,
      TestRequiredOptimizedForSize_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TestRequiredOptimizedForSize, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TestRequiredOptimizedForSize, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(TestRequiredOptimizedForSize));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    TestRequiredOptimizedForSize_descriptor_, TestRequiredOptimizedForSize::default_instance_);
  TestOptionalOptimizedForSize_descriptor_ = file->message_type(2);
  TestOptionalOptimizedForSize::default_instance_ = new TestOptionalOptimizedForSize();
  static const int TestOptionalOptimizedForSize_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TestOptionalOptimizedForSize, o_),
  };
  TestOptionalOptimizedForSize_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      TestOptionalOptimizedForSize_descriptor_,
      TestOptionalOptimizedForSize::default_instance_,
      TestOptionalOptimizedForSize_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TestOptionalOptimizedForSize, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TestOptionalOptimizedForSize, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(TestOptionalOptimizedForSize));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    TestOptionalOptimizedForSize_descriptor_, TestOptionalOptimizedForSize::default_instance_);
  TestOptimizedForSize::default_instance_->InitAsDefaultInstance();
  TestRequiredOptimizedForSize::default_instance_->InitAsDefaultInstance();
  TestOptionalOptimizedForSize::default_instance_->InitAsDefaultInstance();
}

void protobuf_BuildDesc_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  ::google::protobuf::DescriptorPool* pool =
    ::google::protobuf::DescriptorPool::internal_generated_pool();

  ::protobuf_unittest::protobuf_BuildDesc_google_2fprotobuf_2funittest_2eproto();
  pool->InternalBuildGeneratedFile(
    "\n+google/protobuf/unittest_optimize_for."
    "proto\022\021protobuf_unittest\032\036google/protobu"
    "f/unittest.proto\"\222\002\n\024TestOptimizedForSiz"
    "e\022\t\n\001i\030\001 \001(\005\022.\n\003msg\030\023 \001(\0132!.protobuf_uni"
    "ttest.ForeignMessage*\t\010\350\007\020\200\200\200\200\0022@\n\016test_"
    "extension\022\'.protobuf_unittest.TestOptimi"
    "zedForSize\030\322\t \001(\0052r\n\017test_extension2\022\'.p"
    "rotobuf_unittest.TestOptimizedForSize\030\323\t"
    " \001(\0132/.protobuf_unittest.TestRequiredOpt"
    "imizedForSize\")\n\034TestRequiredOptimizedFo"
    "rSize\022\t\n\001x\030\001 \002(\005\"Z\n\034TestOptionalOptimize"
    "dForSize\022:\n\001o\030\001 \001(\0132/.protobuf_unittest."
    "TestRequiredOptimizedForSizeB\002H\002", 512,
  &protobuf_BuildDesc_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto_AssignGlobalDescriptors);
}

// Force BuildDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto {
  StaticDescriptorInitializer_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto() {
    protobuf_BuildDesc_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto();
  }
} static_descriptor_initializer_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto_;


// ===================================================================



::google::protobuf::internal::ExtensionIdentifier< ::protobuf_unittest::TestOptimizedForSize,
  ::google::protobuf::internal::PrimitiveTypeTraits< ::google::protobuf::int32 > > TestOptimizedForSize::test_extension(1234);
::google::protobuf::internal::ExtensionIdentifier< ::protobuf_unittest::TestOptimizedForSize,
  ::google::protobuf::internal::MessageTypeTraits< ::protobuf_unittest::TestRequiredOptimizedForSize > > TestOptimizedForSize::test_extension2(1235);
TestOptimizedForSize::TestOptimizedForSize()
  : ::google::protobuf::Message(),
    _extensions_(&TestOptimizedForSize_descriptor_,
                 ::google::protobuf::DescriptorPool::generated_pool(),
                 ::google::protobuf::MessageFactory::generated_factory()),
    _cached_size_(0),
    i_(0),
    msg_(NULL) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void TestOptimizedForSize::InitAsDefaultInstance() {  msg_ = const_cast< ::protobuf_unittest::ForeignMessage*>(&::protobuf_unittest::ForeignMessage::default_instance());
}

TestOptimizedForSize::TestOptimizedForSize(const TestOptimizedForSize& from)
  : ::google::protobuf::Message(),
    _extensions_(&TestOptimizedForSize_descriptor_,
                 ::google::protobuf::DescriptorPool::generated_pool(),
                 ::google::protobuf::MessageFactory::generated_factory()),
    _cached_size_(0),
    i_(0),
    msg_(NULL) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

TestOptimizedForSize::~TestOptimizedForSize() {
  if (this != default_instance_) {
    delete msg_;
  }
}

const ::google::protobuf::Descriptor* TestOptimizedForSize::descriptor() {
  if (TestOptimizedForSize_descriptor_ == NULL) protobuf_BuildDesc_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto();
  return TestOptimizedForSize_descriptor_;
}

const TestOptimizedForSize& TestOptimizedForSize::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto();
  return *default_instance_;
}

TestOptimizedForSize* TestOptimizedForSize::default_instance_ = NULL;

TestOptimizedForSize* TestOptimizedForSize::New() const {
  return new TestOptimizedForSize;
}

const ::google::protobuf::Descriptor* TestOptimizedForSize::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* TestOptimizedForSize::GetReflection() const {
  if (TestOptimizedForSize_reflection_ == NULL) protobuf_BuildDesc_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto();
  return TestOptimizedForSize_reflection_;
}

// ===================================================================


TestRequiredOptimizedForSize::TestRequiredOptimizedForSize()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    x_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void TestRequiredOptimizedForSize::InitAsDefaultInstance() {}

TestRequiredOptimizedForSize::TestRequiredOptimizedForSize(const TestRequiredOptimizedForSize& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    x_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

TestRequiredOptimizedForSize::~TestRequiredOptimizedForSize() {
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* TestRequiredOptimizedForSize::descriptor() {
  if (TestRequiredOptimizedForSize_descriptor_ == NULL) protobuf_BuildDesc_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto();
  return TestRequiredOptimizedForSize_descriptor_;
}

const TestRequiredOptimizedForSize& TestRequiredOptimizedForSize::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto();
  return *default_instance_;
}

TestRequiredOptimizedForSize* TestRequiredOptimizedForSize::default_instance_ = NULL;

TestRequiredOptimizedForSize* TestRequiredOptimizedForSize::New() const {
  return new TestRequiredOptimizedForSize;
}

const ::google::protobuf::Descriptor* TestRequiredOptimizedForSize::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* TestRequiredOptimizedForSize::GetReflection() const {
  if (TestRequiredOptimizedForSize_reflection_ == NULL) protobuf_BuildDesc_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto();
  return TestRequiredOptimizedForSize_reflection_;
}

// ===================================================================


TestOptionalOptimizedForSize::TestOptionalOptimizedForSize()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    o_(NULL) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void TestOptionalOptimizedForSize::InitAsDefaultInstance() {  o_ = const_cast< ::protobuf_unittest::TestRequiredOptimizedForSize*>(&::protobuf_unittest::TestRequiredOptimizedForSize::default_instance());
}

TestOptionalOptimizedForSize::TestOptionalOptimizedForSize(const TestOptionalOptimizedForSize& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    o_(NULL) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

TestOptionalOptimizedForSize::~TestOptionalOptimizedForSize() {
  if (this != default_instance_) {
    delete o_;
  }
}

const ::google::protobuf::Descriptor* TestOptionalOptimizedForSize::descriptor() {
  if (TestOptionalOptimizedForSize_descriptor_ == NULL) protobuf_BuildDesc_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto();
  return TestOptionalOptimizedForSize_descriptor_;
}

const TestOptionalOptimizedForSize& TestOptionalOptimizedForSize::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto();
  return *default_instance_;
}

TestOptionalOptimizedForSize* TestOptionalOptimizedForSize::default_instance_ = NULL;

TestOptionalOptimizedForSize* TestOptionalOptimizedForSize::New() const {
  return new TestOptionalOptimizedForSize;
}

const ::google::protobuf::Descriptor* TestOptionalOptimizedForSize::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* TestOptionalOptimizedForSize::GetReflection() const {
  if (TestOptionalOptimizedForSize_reflection_ == NULL) protobuf_BuildDesc_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto();
  return TestOptionalOptimizedForSize_reflection_;
}

}  // namespace protobuf_unittest