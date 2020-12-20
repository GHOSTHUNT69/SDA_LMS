#pragma once
//#include"Person_fwd.h"
#include<string>
using std::string;

namespace LMS {
	class Person
	{
	protected:
		string name;
		string dob;
		string email;
	public:
		Person();
		Person(string name_, string dob_, string email_);
		~Person();

		string get_name();
		string get_dob();
		string get_email();
	};
}
