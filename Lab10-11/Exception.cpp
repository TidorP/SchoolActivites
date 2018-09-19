#include "Exception.h"



Exception::Exception(std::string message)
{
	this->msg = message;
}
std::string Exception::getMsg()const {
	return this->msg;
}


