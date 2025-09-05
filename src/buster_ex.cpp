//
//  cacheBuster
//
//  Created by Lukáš Frídl on 5.9.2025.
//

#include "buster_ex.h"

BusterEx::BusterEx(const std::string& msg){
	ErrorMessage = msg;
}

const char* BusterEx::what() const throw()
{
	return ErrorMessage.c_str();
};
