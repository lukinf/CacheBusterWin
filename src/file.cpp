//
//  cacheBuster
//
//  Created by Lukáš Frídl on 5.9.2025.
//

#include "file.h"

File::File(const std::string& Path) {
  path = Path;
}

std::string& File::get_name(){
  return name;
}

void File::set_name(const std::string& Name) {
  name = Name;
}

std::string& File::get_new_name(){
  return new_name;
}

void File::set_new_name(const std::string& NewName) {
  new_name = NewName;
}

std::string& File::get_extension(){
  return extension;
}

void File::set_extension(const std::string& Extension) {
  extension = Extension;
}

void File::add_reference(const int& Reference){
  references = references + 1;
}

int& File::get_references(){
  return references;
}

std::string& File::get_path(){
  return path;
}

std::string& File::get_new_UUID() {
    new_UUID = Utils::get_uuid();
    new_UUID.erase(std::remove(new_UUID.begin(), new_UUID.end(), '-'), new_UUID.end());
  return new_UUID;
}

void File::set_new_UUID(const std::string& NewUUID) {
  new_UUID = NewUUID;
}

void File::rename(const std::string& NewName) {
  auto newPath = path;
  newPath = newPath.substr(0, newPath.size()-name.length());
  newPath = newPath + NewName;
  std::filesystem::rename(path, newPath);
}

std::string& File::get_content() {
  std::string fileValue;
  std::ifstream inFile;
  inFile.open(path);
  std::stringstream strStream;
  strStream << inFile.rdbuf();
  file_content = strStream.str();
  return file_content;
}

void File::set_content(const std::string& File) {
  file_content = File;
  std::ofstream out(path);
  out << file_content;
  out.close();
}

std::string File::convert_to_string(char a[32], int size) {
  std::string s;
  for (int i = 0; i < size; i++) {
    s = s + a[i];
  }
  return s;
}

File::~File() {
}
