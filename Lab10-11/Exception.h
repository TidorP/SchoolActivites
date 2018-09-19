#pragma once
#include <string>
class Exception
{
private:
	std::string msg;
public:
	Exception(std::string message);
	std::string getMsg() const;
};

