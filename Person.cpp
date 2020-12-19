#include "Person.h"

Person::Person()
{
}

Person::Person(string name_, string dob_)
	:name(name_),dob(dob_)
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
