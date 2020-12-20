#pragma once
#include"Registration_fwd.h"
#include"Evaluation_fwd.h"
#include"Faculty_fwd.h"
#include"Session_fwd.h"
#include"Course_fwd.h"
#include<vector>
#include<string>
using std::vector;
using std::string;

namespace LMS {
	class Section
	{
	protected:
		vector<Registration*> sregistrations;
		vector<Evaluation*> sevaluations;
		Session* ssession;
		Faculty* steacher;
		Course* scourse;
		string sectionname;
		//waiting list
	public:
		Section();
		Section(vector<Registration*> sregistrations_, vector<Evaluation*> sevaluations_, Session* ssession_, Faculty* steacher_, Course* scourse_, string sectionname_);
		~Section();
	};
}