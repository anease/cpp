#pragma once
#include <exception>
#include <string>

using namespace std;

class EntertainmentError :public exception
{
	string message;
public:
	EntertainmentError(const string& msg) : message(msg) {}
	virtual const char* what() const noexcept override
	{
		return message.c_str();
	}
	~EntertainmentError() {};
};
