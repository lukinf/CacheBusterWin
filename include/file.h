//
//  cacheBuster
//
//  Created by Lukáš Frídl on 5.9.2025.
//

#include <stdio.h>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
#include "utils.h"
#include "params.h"

#pragma once

class File {
public:
  File(const std::string& Path);
  std::string& get_name();
  void set_name(const std::string& NewName);
  std::string& get_new_name();
  void set_new_name(const std::string& NewName);
  std::string& get_path();
  std::string& get_extension();
  void set_extension(const std::string& Extension);
  void add_reference(const int& Reference);
  int& get_references();
  std::string& get_content();
  void set_content(const std::string& File);
  void rename(const std::string& NewName);
  std::string& get_new_UUID();
  void set_new_UUID(const std::string& NewUUID);
  ~File();
private:
  std::string path;
  std::string name;
  std::string new_name;
  std::string new_UUID;
  std::string extension;
  std::string file_content;
  int references = 0;
protected:
  std::string convert_to_string(char* a, int size);
};
