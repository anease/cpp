#pragma once
#include <exception>
#include <string>


using namespace std;

class StackError :public exception
{
	string message;
public:
	StackError(const string& msg) : message(msg) {}
	virtual const char* what() const noexcept override
	{
		return message.c_str();
	}
	~StackError() {};
};
