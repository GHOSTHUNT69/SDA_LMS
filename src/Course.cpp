#pragma once
#include "Course.h"

namespace LMS {

	Course::Course()
	{
	}

	Course::Course(string _name, string _code)
		:cname(_name), ccode(_code)
	{
	}

	Course::Course(string _name, string _code, vector<Section*> _secs)
		:cname(_name),ccode(_code),csections(_secs)
	{
	}

	Course::~Course()
	{
	}

	bool Course::addSection(Section* _sec)
	{
		csections.push_back(_sec);
		return true;
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
}
