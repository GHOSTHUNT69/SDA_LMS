#pragma once
#include<string>
#include<vector>
#include"Section.h"

class Section;

using std::string;
using std::vector;

class Course
{
protected:
	string cname;
	string ccode;
	vector<Section> csections;
public:
	Course();
	Course(string, string);
	~Course();

	string get_cname();
	string get_ccode();
	vector<Section> get_csections();

};

