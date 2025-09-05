//
//  cacheBuster
//
//  Created by Lukáš Frídl on 5.9.2025.

#include <iostream>
#include <cctype>
#include "buster.h"
#include "directory.h"
#include "file.h"

int main(int argc, const char * argv[]) {
	std::string path;
	bool firstRun = false;
	char qa;

	std::cout << Utils::get_uuid();

first_run:
	qa = NULL;
	std::cout << "First run? Y/N:";
	std::cin >> qa;
	qa = toupper(qa);
	if (qa == 'Y') {
		qa = true;
	} else if (qa == 'N') {
		qa = false;
	} else {
		goto first_run;
	}

enter_path:
	std::cout << "Enter absolute path:";
	std::cin >> path;
	if (path.empty() == true){
		goto enter_path;
	}
	
	std::cout << std::endl;
	Directory directory = Directory(path);
	Buster::test_run(directory.get_files());
	std::cout << std::endl;
	
write_changes:
	qa = NULL;
	std::cout << "Test run done, write changes? Y/N:";
	std::cin >> qa;
	qa = toupper(qa);
	if (qa == 'Y') {
		Buster::run(firstRun, directory.get_files());
	} else if (qa == 'N') {
		std::cout << "No changes has been written..." << std::endl;
	} else {
		goto write_changes;
	}
	
	std::cout << "Buster run done..." << std::endl;
	return 0;
}
