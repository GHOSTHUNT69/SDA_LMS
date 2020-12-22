#pragma once
//#include"Person_fwd.h"
#include<string>
using std::string;

namespace LMS {
	class Person
	{
	private:
		string password;
	protected:
		string username;
		string name;
		string dob;
		string email;
	public:
		Person();
		Person(string name_, string dob_, string email_, string _uname,string _passwrod);
		~Person();

		string get_username();
		string get_name();
		string get_dob();
		string get_email();
		bool check_login(string _uname, string _password);
		bool check_pass(string pass);
	};
}
