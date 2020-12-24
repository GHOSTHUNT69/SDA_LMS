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
		string sname;
		//waiting list
	public:
		Section();
		Section(string _name, Course* _course = nullptr, Faculty* _teacher = nullptr, Session* _session = nullptr);
		Section(string _name, Course* _course, Faculty* _teacher, Session* _session, vector<Registration*> _regs, vector<Evaluation*>_evals);
		~Section();

		void markAttendance()
		{

		}

		void getAttendance()
		{

		}

		bool addRegistration(Registration*);
	};
}