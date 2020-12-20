#include "Student.h"

Student::Student()
{
}

Student::Student(string rollno_, string name_, string dob_,string email_)
	:Person(name_,dob_,email_),rollno(rollno_)
{
}

Student::Student(string rollno_, string name_, string dob_, string email_, vector<Registration*> reg_)
	: Person(name_, dob_, email_), rollno(rollno_),sregistrations(reg_)
{
}

Student::~Student()
{
}
