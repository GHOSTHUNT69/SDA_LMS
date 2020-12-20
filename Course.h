#pragma once
#include"Section_fwd.h"
#include<string>
#include<vector>
using std::string;
using std::vector;

namespace LMS {
	class Course
	{
	protected:
		string cname;
		string ccode;
		vector<Section*> csections;
	public:
		Course();
		Course(string, string);
		~Course();

		string get_cname();
		string get_ccode();
		vector<Section*> get_csections();

	};
}

