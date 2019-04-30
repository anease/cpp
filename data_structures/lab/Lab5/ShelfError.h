#pragma once
#include <exception>
#include <string>

using namespace std;

class ShelfError :public exception
{
	string message;
public:
	ShelfError(const string& msg) : message(msg) {}
	virtual const char* what() const noexcept override
	{
		return message.c_str();
	}
	~ShelfError() {};
};
