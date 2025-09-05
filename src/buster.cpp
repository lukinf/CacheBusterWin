//
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#include "buster.h"

bool Buster::first_run = false;
std::vector<File> Buster::files;

void Buster::test_run(const std::vector<File>& Files) {
  files = Files;
  for(auto& fileFirstLoop : files) {
    std::string fileStr = fileFirstLoop.get_content();
    for(auto &fileSecLoop : files) {
      auto position = fileStr.find(fileSecLoop.get_name());
      if (position!=std::string::npos)
        fileSecLoop.add_reference(1);
    }
  }
  
  for(auto &fileResult : files){
    std::cout << std::setiosflags(std::ios::fixed)
    << std::setw(50)
    << std::left << fileResult.get_name();
    
    std::cout << std::setiosflags(std::ios::fixed)
    << std::setw(1)
    << std::left << "-";
    
    std::cout << std::setiosflags(std::ios::fixed)
    << std::setw(4)
    << std::right << fileResult.get_references();
    
    std::cout << std::setiosflags(std::ios::fixed)
    << std::setw(1)
    << std::left << " ";
    
    std::cout << std::setiosflags(std::ios::fixed)
    << std::setw(3)
    << std::left << "Ref" << std::endl;
  }
}

void Buster::run(const bool& FirstRun,const std::vector<File>& Files) {
  first_run = FirstRun;
  files = Files;
  generate_new_names();
  change_references();
  rename_files();
}

void Buster::generate_new_names() {
  for(auto &file : files){
    auto name = file.get_name();
    auto ext = file.get_extension();
    if (first_run == true) {
      auto uuid = file.get_new_UUID();
      auto newNameSub = name.substr(0, name.length() - ext.length());
      std::string newName = newNameSub + "_" + uuid + ext;
      file.set_new_name(newName);
    } else {
      int charsToRemove = 28 + (int)ext.length() + 1;
      auto uuid = file.get_new_UUID();
      auto newNameSub = name.substr(0, name.length() - charsToRemove);
      std::string newName = newNameSub + "_" + uuid + ext;
      file.set_new_name(newName);
    }
  }
}

void Buster::change_references() {
  for(auto &fileFirstLoop : files){
    std::string fileStr = fileFirstLoop.get_content();
    for(auto &fileSecLoop : files){
      std::string::size_type n = 0;
      while ((n = fileStr.find( fileSecLoop.get_name(), n )) != std::string::npos)
      {
        fileStr.replace(n, fileSecLoop.get_name().size(), fileSecLoop.get_new_name());
        n += fileSecLoop.get_new_name().size();
      }
    }
    fileFirstLoop.set_content(fileStr);
  }
}

void Buster::rename_files() {
  for(auto &file : files){
    auto name = file.get_name();
    if (name.substr(0, 5) != "index") {
      file.rename(file.get_new_name());
    }
  }
}
