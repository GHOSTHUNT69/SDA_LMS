#pragma once
#include "Person.h"

namespace LMS {

	Person::Person()
	{
	}

	Person::Person(string name_, string dob_, string email_, string _uname, string _password)
		:name(name_), dob(dob_), email(email_), username(_uname),password(_password)
	{
	}

	Person::~Person() {}

	string Person::get_username()
	{
		return username;
	}

	string Person::get_name()
	{
		return name;
	}

	string Person::get_dob()
	{
		return dob;
	}

	string Person::get_email()
	{
		return email;
	}
	string Person::get_pass()
	{
		return password;
	}
	bool Person::check_login(string _uname, string _password)
	{
		return _uname==username && _password==password;
	}
	bool Person::check_pass(string pass)
	{
		return pass==password;
	}
}
