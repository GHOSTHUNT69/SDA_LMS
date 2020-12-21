#include "Student.h"
#include "Registration.h"

namespace LMS {
	Student::Student()
	{
	}

	Student::Student(string rollno_, string name_, string dob_, string email_)
		:Person(name_, dob_, email_), rollno(rollno_)
	{
	}

	Student::Student(string rollno_, string name_, string dob_, string email_, vector<Registration*> reg_)
		: Person(name_, dob_, email_), rollno(rollno_), sregistrations(reg_)
	{
	}

	Student::~Student()
	{
	}
	bool Student::addRegistration(Registration* reg_)
	{
		sregistrations.push_back(reg_);
		return true;
	}
	bool Student::addRegistration(Section* sec_)
	{
		sregistrations.push_back(new Registration(this,sec_));
		return true;
	}
}
