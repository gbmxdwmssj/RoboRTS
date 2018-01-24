// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: serial_comm_config.proto

#ifndef PROTOBUF_serial_5fcomm_5fconfig_2eproto__INCLUDED
#define PROTOBUF_serial_5fcomm_5fconfig_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace rrts {
namespace driver {
namespace serial {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_serial_5fcomm_5fconfig_2eproto();
void protobuf_AssignDesc_serial_5fcomm_5fconfig_2eproto();
void protobuf_ShutdownFile_serial_5fcomm_5fconfig_2eproto();

class SerialPortConfig;

// ===================================================================

class SerialPortConfig : public ::google::protobuf::Message {
 public:
  SerialPortConfig();
  virtual ~SerialPortConfig();

  SerialPortConfig(const SerialPortConfig& from);

  inline SerialPortConfig& operator=(const SerialPortConfig& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SerialPortConfig& default_instance();

  void Swap(SerialPortConfig* other);

  // implements Message ----------------------------------------------

  SerialPortConfig* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SerialPortConfig& from);
  void MergeFrom(const SerialPortConfig& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string serial_port = 1;
  inline bool has_serial_port() const;
  inline void clear_serial_port();
  static const int kSerialPortFieldNumber = 1;
  inline const ::std::string& serial_port() const;
  inline void set_serial_port(const ::std::string& value);
  inline void set_serial_port(const char* value);
  inline void set_serial_port(const char* value, size_t size);
  inline ::std::string* mutable_serial_port();
  inline ::std::string* release_serial_port();
  inline void set_allocated_serial_port(::std::string* serial_port);

  // required int32 serial_boudrate = 2;
  inline bool has_serial_boudrate() const;
  inline void clear_serial_boudrate();
  static const int kSerialBoudrateFieldNumber = 2;
  inline ::google::protobuf::int32 serial_boudrate() const;
  inline void set_serial_boudrate(::google::protobuf::int32 value);

  // optional int32 flow_control = 3 [default = 0];
  inline bool has_flow_control() const;
  inline void clear_flow_control();
  static const int kFlowControlFieldNumber = 3;
  inline ::google::protobuf::int32 flow_control() const;
  inline void set_flow_control(::google::protobuf::int32 value);

  // optional int32 databits = 4 [default = 8];
  inline bool has_databits() const;
  inline void clear_databits();
  static const int kDatabitsFieldNumber = 4;
  inline ::google::protobuf::int32 databits() const;
  inline void set_databits(::google::protobuf::int32 value);

  // optional int32 stopbits = 5 [default = 1];
  inline bool has_stopbits() const;
  inline void clear_stopbits();
  static const int kStopbitsFieldNumber = 5;
  inline ::google::protobuf::int32 stopbits() const;
  inline void set_stopbits(::google::protobuf::int32 value);

  // optional string parity = 6 [default = "N"];
  inline bool has_parity() const;
  inline void clear_parity();
  static const int kParityFieldNumber = 6;
  inline const ::std::string& parity() const;
  inline void set_parity(const ::std::string& value);
  inline void set_parity(const char* value);
  inline void set_parity(const char* value, size_t size);
  inline ::std::string* mutable_parity();
  inline ::std::string* release_parity();
  inline void set_allocated_parity(::std::string* parity);

  // optional bool is_debug = 7 [default = true];
  inline bool has_is_debug() const;
  inline void clear_is_debug();
  static const int kIsDebugFieldNumber = 7;
  inline bool is_debug() const;
  inline void set_is_debug(bool value);

  // @@protoc_insertion_point(class_scope:rrts.driver.serial.SerialPortConfig)
 private:
  inline void set_has_serial_port();
  inline void clear_has_serial_port();
  inline void set_has_serial_boudrate();
  inline void clear_has_serial_boudrate();
  inline void set_has_flow_control();
  inline void clear_has_flow_control();
  inline void set_has_databits();
  inline void clear_has_databits();
  inline void set_has_stopbits();
  inline void clear_has_stopbits();
  inline void set_has_parity();
  inline void clear_has_parity();
  inline void set_has_is_debug();
  inline void clear_has_is_debug();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* serial_port_;
  ::google::protobuf::int32 serial_boudrate_;
  ::google::protobuf::int32 flow_control_;
  ::google::protobuf::int32 databits_;
  ::google::protobuf::int32 stopbits_;
  static ::std::string* _default_parity_;
  ::std::string* parity_;
  bool is_debug_;
  friend void  protobuf_AddDesc_serial_5fcomm_5fconfig_2eproto();
  friend void protobuf_AssignDesc_serial_5fcomm_5fconfig_2eproto();
  friend void protobuf_ShutdownFile_serial_5fcomm_5fconfig_2eproto();

  void InitAsDefaultInstance();
  static SerialPortConfig* default_instance_;
};
// ===================================================================


// ===================================================================

// SerialPortConfig

// required string serial_port = 1;
inline bool SerialPortConfig::has_serial_port() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SerialPortConfig::set_has_serial_port() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SerialPortConfig::clear_has_serial_port() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SerialPortConfig::clear_serial_port() {
  if (serial_port_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    serial_port_->clear();
  }
  clear_has_serial_port();
}
inline const ::std::string& SerialPortConfig::serial_port() const {
  // @@protoc_insertion_point(field_get:rrts.driver.serial.SerialPortConfig.serial_port)
  return *serial_port_;
}
inline void SerialPortConfig::set_serial_port(const ::std::string& value) {
  set_has_serial_port();
  if (serial_port_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    serial_port_ = new ::std::string;
  }
  serial_port_->assign(value);
  // @@protoc_insertion_point(field_set:rrts.driver.serial.SerialPortConfig.serial_port)
}
inline void SerialPortConfig::set_serial_port(const char* value) {
  set_has_serial_port();
  if (serial_port_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    serial_port_ = new ::std::string;
  }
  serial_port_->assign(value);
  // @@protoc_insertion_point(field_set_char:rrts.driver.serial.SerialPortConfig.serial_port)
}
inline void SerialPortConfig::set_serial_port(const char* value, size_t size) {
  set_has_serial_port();
  if (serial_port_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    serial_port_ = new ::std::string;
  }
  serial_port_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:rrts.driver.serial.SerialPortConfig.serial_port)
}
inline ::std::string* SerialPortConfig::mutable_serial_port() {
  set_has_serial_port();
  if (serial_port_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    serial_port_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:rrts.driver.serial.SerialPortConfig.serial_port)
  return serial_port_;
}
inline ::std::string* SerialPortConfig::release_serial_port() {
  clear_has_serial_port();
  if (serial_port_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = serial_port_;
    serial_port_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void SerialPortConfig::set_allocated_serial_port(::std::string* serial_port) {
  if (serial_port_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete serial_port_;
  }
  if (serial_port) {
    set_has_serial_port();
    serial_port_ = serial_port;
  } else {
    clear_has_serial_port();
    serial_port_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:rrts.driver.serial.SerialPortConfig.serial_port)
}

// required int32 serial_boudrate = 2;
inline bool SerialPortConfig::has_serial_boudrate() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SerialPortConfig::set_has_serial_boudrate() {
  _has_bits_[0] |= 0x00000002u;
}
inline void SerialPortConfig::clear_has_serial_boudrate() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void SerialPortConfig::clear_serial_boudrate() {
  serial_boudrate_ = 0;
  clear_has_serial_boudrate();
}
inline ::google::protobuf::int32 SerialPortConfig::serial_boudrate() const {
  // @@protoc_insertion_point(field_get:rrts.driver.serial.SerialPortConfig.serial_boudrate)
  return serial_boudrate_;
}
inline void SerialPortConfig::set_serial_boudrate(::google::protobuf::int32 value) {
  set_has_serial_boudrate();
  serial_boudrate_ = value;
  // @@protoc_insertion_point(field_set:rrts.driver.serial.SerialPortConfig.serial_boudrate)
}

// optional int32 flow_control = 3 [default = 0];
inline bool SerialPortConfig::has_flow_control() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void SerialPortConfig::set_has_flow_control() {
  _has_bits_[0] |= 0x00000004u;
}
inline void SerialPortConfig::clear_has_flow_control() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void SerialPortConfig::clear_flow_control() {
  flow_control_ = 0;
  clear_has_flow_control();
}
inline ::google::protobuf::int32 SerialPortConfig::flow_control() const {
  // @@protoc_insertion_point(field_get:rrts.driver.serial.SerialPortConfig.flow_control)
  return flow_control_;
}
inline void SerialPortConfig::set_flow_control(::google::protobuf::int32 value) {
  set_has_flow_control();
  flow_control_ = value;
  // @@protoc_insertion_point(field_set:rrts.driver.serial.SerialPortConfig.flow_control)
}

// optional int32 databits = 4 [default = 8];
inline bool SerialPortConfig::has_databits() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void SerialPortConfig::set_has_databits() {
  _has_bits_[0] |= 0x00000008u;
}
inline void SerialPortConfig::clear_has_databits() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void SerialPortConfig::clear_databits() {
  databits_ = 8;
  clear_has_databits();
}
inline ::google::protobuf::int32 SerialPortConfig::databits() const {
  // @@protoc_insertion_point(field_get:rrts.driver.serial.SerialPortConfig.databits)
  return databits_;
}
inline void SerialPortConfig::set_databits(::google::protobuf::int32 value) {
  set_has_databits();
  databits_ = value;
  // @@protoc_insertion_point(field_set:rrts.driver.serial.SerialPortConfig.databits)
}

// optional int32 stopbits = 5 [default = 1];
inline bool SerialPortConfig::has_stopbits() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void SerialPortConfig::set_has_stopbits() {
  _has_bits_[0] |= 0x00000010u;
}
inline void SerialPortConfig::clear_has_stopbits() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void SerialPortConfig::clear_stopbits() {
  stopbits_ = 1;
  clear_has_stopbits();
}
inline ::google::protobuf::int32 SerialPortConfig::stopbits() const {
  // @@protoc_insertion_point(field_get:rrts.driver.serial.SerialPortConfig.stopbits)
  return stopbits_;
}
inline void SerialPortConfig::set_stopbits(::google::protobuf::int32 value) {
  set_has_stopbits();
  stopbits_ = value;
  // @@protoc_insertion_point(field_set:rrts.driver.serial.SerialPortConfig.stopbits)
}

// optional string parity = 6 [default = "N"];
inline bool SerialPortConfig::has_parity() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void SerialPortConfig::set_has_parity() {
  _has_bits_[0] |= 0x00000020u;
}
inline void SerialPortConfig::clear_has_parity() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void SerialPortConfig::clear_parity() {
  if (parity_ != _default_parity_) {
    parity_->assign(*_default_parity_);
  }
  clear_has_parity();
}
inline const ::std::string& SerialPortConfig::parity() const {
  // @@protoc_insertion_point(field_get:rrts.driver.serial.SerialPortConfig.parity)
  return *parity_;
}
inline void SerialPortConfig::set_parity(const ::std::string& value) {
  set_has_parity();
  if (parity_ == _default_parity_) {
    parity_ = new ::std::string;
  }
  parity_->assign(value);
  // @@protoc_insertion_point(field_set:rrts.driver.serial.SerialPortConfig.parity)
}
inline void SerialPortConfig::set_parity(const char* value) {
  set_has_parity();
  if (parity_ == _default_parity_) {
    parity_ = new ::std::string;
  }
  parity_->assign(value);
  // @@protoc_insertion_point(field_set_char:rrts.driver.serial.SerialPortConfig.parity)
}
inline void SerialPortConfig::set_parity(const char* value, size_t size) {
  set_has_parity();
  if (parity_ == _default_parity_) {
    parity_ = new ::std::string;
  }
  parity_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:rrts.driver.serial.SerialPortConfig.parity)
}
inline ::std::string* SerialPortConfig::mutable_parity() {
  set_has_parity();
  if (parity_ == _default_parity_) {
    parity_ = new ::std::string(*_default_parity_);
  }
  // @@protoc_insertion_point(field_mutable:rrts.driver.serial.SerialPortConfig.parity)
  return parity_;
}
inline ::std::string* SerialPortConfig::release_parity() {
  clear_has_parity();
  if (parity_ == _default_parity_) {
    return NULL;
  } else {
    ::std::string* temp = parity_;
    parity_ = const_cast< ::std::string*>(_default_parity_);
    return temp;
  }
}
inline void SerialPortConfig::set_allocated_parity(::std::string* parity) {
  if (parity_ != _default_parity_) {
    delete parity_;
  }
  if (parity) {
    set_has_parity();
    parity_ = parity;
  } else {
    clear_has_parity();
    parity_ = const_cast< ::std::string*>(_default_parity_);
  }
  // @@protoc_insertion_point(field_set_allocated:rrts.driver.serial.SerialPortConfig.parity)
}

// optional bool is_debug = 7 [default = true];
inline bool SerialPortConfig::has_is_debug() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void SerialPortConfig::set_has_is_debug() {
  _has_bits_[0] |= 0x00000040u;
}
inline void SerialPortConfig::clear_has_is_debug() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void SerialPortConfig::clear_is_debug() {
  is_debug_ = true;
  clear_has_is_debug();
}
inline bool SerialPortConfig::is_debug() const {
  // @@protoc_insertion_point(field_get:rrts.driver.serial.SerialPortConfig.is_debug)
  return is_debug_;
}
inline void SerialPortConfig::set_is_debug(bool value) {
  set_has_is_debug();
  is_debug_ = value;
  // @@protoc_insertion_point(field_set:rrts.driver.serial.SerialPortConfig.is_debug)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace serial
}  // namespace driver
}  // namespace rrts

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_serial_5fcomm_5fconfig_2eproto__INCLUDED
