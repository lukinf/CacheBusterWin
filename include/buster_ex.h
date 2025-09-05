//
//  cacheBuster
//
//  Created by Lukáš Frídl on 5.9.2025.
//

#include <stdio.h>
#include <string>
#include <exception>

class BusterEx : virtual public std::exception
{
public:
	explicit
	BusterEx(const std::string& msg);
	virtual const char* what() const throw();
protected:
	std::string ErrorMessage;
};