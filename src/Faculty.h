#pragma once
#include"Person.h"
#include"Section_fwd.h"
#include<string>
#include<vector>
using std::string;
using std::vector;

namespace LMS {
	//teacher
	class Faculty :
		public Person
	{
	protected:
		vector<Section*> fsections;
	public:
		Faculty();
		Faculty(string name_, string dob_, string email_, string _uname, string _password);
		Faculty(string name_, string dob_, string email_, string _uname, string _password, vector<Section*>fsections_);
		
		void markAttendance();
		string get_role();
		~Faculty();

		//bool addSection();
	};
}

