#pragma once
#include"LMS.h"
#include<string>
#include<vector>
using std::string;
using std::vector;

//classes used
class Person;
class Section;

//teacher
class Faculty :
	protected Person
{
protected:
	vector<Section*> fsections;
public:
	Faculty();
	Faculty(string name_, string dob_, string email_);
	Faculty(string name_, string dob_, string email_,vector<Section*>fsections_);
	~Faculty();
	
	bool addSection();
};

