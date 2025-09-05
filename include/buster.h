//
//  cacheBuster
//
//  Created by Lukáš Frídl on 5.9.2025.
//

#include <stdio.h>
#include <vector>
#include "file.h"

class Buster {
public:
  static void test_run(const std::vector<File>& Files);
  static void run(const bool& FirstRun,const std::vector<File>& Files);
private:
  static bool first_run;
  static std::vector<File> files;
  static void generate_new_names();
  static void change_references();
  static void rename_files();
};

