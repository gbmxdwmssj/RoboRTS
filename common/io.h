/****************************************************************************
 *  Copyright (C) 2018 RoboMaster.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of 
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#ifndef COMMON_IO_H
#define COMMON_IO_H
#include <iomanip>
#include <iostream>
#include <string>
#include <stdint.h>

#include <fcntl.h>
#include <unistd.h>

#include <google/protobuf/message.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/text_format.h>

#include "log.h"

namespace rrts {
namespace common {
const int kProtoReadBytesLimit = INT_MAX;  // Max size of 2 GB minus 1 byte.

template<class T>
bool ReadProtoFromTextFile(const char *file_name, T *proto) {
  using google::protobuf::io::FileInputStream;
  using google::protobuf::io::FileOutputStream;
  using google::protobuf::io::ZeroCopyInputStream;
  using google::protobuf::io::CodedInputStream;
  using google::protobuf::io::ZeroCopyOutputStream;
  using google::protobuf::io::CodedOutputStream;
  using google::protobuf::Message;
  
  int fd = open(file_name, O_RDONLY);
  if (fd == -1) {
    LOG_ERROR << "File not found: " << file_name;
    return false;
  }
  FileInputStream *input = new FileInputStream(fd);
  bool success = google::protobuf::TextFormat::Parse(input, proto);
  delete input;
  close(fd);
  return success;
}

template<class T>
inline bool ReadProtoFromTextFile(const std::string &file_name, T *proto) {
  return ReadProtoFromTextFile(file_name.c_str(), proto);
}

template<class T>
bool ReadProtoFromBinaryFile(const char *file_name, T *proto) {
  using google::protobuf::io::FileInputStream;
  using google::protobuf::io::FileOutputStream;
  using google::protobuf::io::ZeroCopyInputStream;
  using google::protobuf::io::CodedInputStream;
  using google::protobuf::io::ZeroCopyOutputStream;
  using google::protobuf::io::CodedOutputStream;
  using google::protobuf::Message;

  int fd = open(file_name, O_RDONLY);
  if (fd == -1) {
    proto = NULL;
    LOG_ERROR << "File not found: " << file_name;
  }

  ZeroCopyInputStream *raw_input = new FileInputStream(fd);
  CodedInputStream *coded_input = new CodedInputStream(raw_input);
  coded_input->SetTotalBytesLimit(kProtoReadBytesLimit, 536870912);

  bool success = proto->ParseFromCodedStream(coded_input);

  delete coded_input;
  delete raw_input;
  close(fd);
  return success;
}
template<class T>
inline bool ReadProtoFromBinaryFile(const std::string &file_name, T *proto) {
  return ReadProtoFromBinaryFile(file_name.c_str(), proto);
}

template<class T>
bool ReadYmlFromFile(const char *file_name, T *yml_type);
template<class T>
inline bool ReadYmlFromFile(const std::string &file_name, T *yml_type) {
  return ReadYmlFromFile(file_name.c_str(), yml_type);
}
}
}
#endif // COMMON_IO_H
