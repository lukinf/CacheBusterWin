//
//  cacheBuster
//
//  Created by Lukáš Frídl on 5.9.2025.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include "file.h"
#include "params.h"

class Directory {
public:
	Directory(const std::string& Path);
	std::string& get_path();
	std::vector<File>& get_files();
	~Directory();
private:
	std::string path;
	std::vector<File> files;
	Extension resolveOption(const std::string& input);
protected:
	void get_directory_files(const std::string& Path);
	bool check_file_extension(const std::filesystem::path& Path);
};