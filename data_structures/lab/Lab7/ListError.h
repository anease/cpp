#pragma once
#include <exception>
#include <string>

using namespace std;

class ListError :public exception
{
	string message;
public:
	ListError(const string& msg) : message(msg) {}
	virtual const char* what() const noexcept override
	{
		return message.c_str();
	}
	~ListError() {};
};