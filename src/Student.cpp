#pragma once
#include "Student.h"
#include "Registration.h"

namespace LMS
{
	Student::Student()
	{
	}

	Student::Student(string rollno_, string name_, string dob_, string email_, string _uname, string _password)
		: Person(name_, dob_, email_, _uname, _password), rollno(rollno_)
	{
	}

	Student::Student(string rollno_, string name_, string dob_, string email_, string _uname, string _password, vector<Registration *> reg_)
		: Person(name_, dob_, email_, _uname, _password), rollno(rollno_), sregistrations(reg_)
	{
	}

	Student::~Student()
	{
	}
	string Student::get_role()
	{
		return "student";
	}
	string Student::get_rollno()
	{
		return rollno;
	}
	bool Student::addRegistration(Registration *reg_)
	{
		sregistrations.push_back(reg_);
		return true;
	}
	bool Student::addRegistration(Section *sec_)
	{
		sregistrations.push_back(new Registration(this, sec_));
		return true;
	}
} // namespace LMS
