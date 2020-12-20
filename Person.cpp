#include "Person.h"

Person::Person()
{
}

Person::Person(string name_, string dob_, string email_)
	:name(name_),dob(dob_),email(email_)
{
}

Person::~Person() {}

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
