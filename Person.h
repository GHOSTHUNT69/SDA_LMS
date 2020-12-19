#pragma once
#include<string>
using std::string;

class Person
{
protected:
	string name;
	string dob;
public:
	Person();
	Person(string, string);
	~Person();

	string get_name();
	string get_dob();
};

