//
//  cacheBuster
//
//  Created by Lukáš Frídl on 5.9.2025.
//

#include "directory.h"

Directory::Directory(const std::string& Path) {
  path = Path;
  get_directory_files(path);
}

std::string& Directory::get_path() {
  return path;
}

std::vector<File>& Directory::get_files(){
  return files;
}

void Directory::get_directory_files(const std::string& Path) {
  for (const auto &entry : std::filesystem::directory_iterator(Path))
  {
    if (entry.is_directory() == true){
      auto hidden = entry.path().filename().c_str()[0];
      if (hidden != HIDDEN_DOT ){
        get_directory_files(entry.path().string());
      }
    } else {
      auto hidden = entry.path().filename().c_str()[0];
      if (hidden != HIDDEN_DOT ){
        if (entry.is_regular_file() == true && check_file_extension(entry.path()) == true){
          File file = File(entry.path().string());
          file.set_name(entry.path().filename().string());
          file.set_extension(entry.path().filename().extension().string());
          files.push_back(file);
        }
      }
    }
  }
}

bool Directory::check_file_extension(const std::filesystem::path& Path){
  switch (resolveOption(Path.filename().extension().string())) {
    case js:
      return true;
      break;
    case css:
      return true;
      break;
    case html:
      return true;
      break;
    default:
      return false;
      break;
  }
}

Extension Directory::resolveOption(const std::string& input) {
  if( input == EXT_JS ) return js;
  if( input == EXT_CSS ) return css;
  if( input == EXT_HTML ) return html;
  return invalid;
}

Directory::~Directory() {
}
