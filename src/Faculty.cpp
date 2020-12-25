#pragma once
#include "Faculty.h"

namespace LMS {

	Faculty::Faculty()
	{
	}

	Faculty::Faculty(string name_, string dob_, string email_, string _uname, string _password)
		:Person(name_, dob_, email_,  _uname, _password)
	{
	}

	Faculty::Faculty(string name_, string dob_, string email_, string _uname, string _password ,vector<Section*> fsections_)
		:Person(name_, dob_, email_, _uname, _password), fsections(fsections_)
	{
	}

	string Faculty::get_role()
	{
		return "teacher";
	}

	Faculty::~Faculty()
	{
	}
}
