#include "Course.h"

Course::Course()
{
}

Course::Course(string cname_, string ccode_)
	:cname(cname_),ccode(ccode_)
{
}

Course::~Course()
{
}

string Course::get_cname()
{
	return cname;
}

string Course::get_ccode()
{
	return ccode;
}

vector<Section*> Course::get_csections()
{
	return csections;
}
