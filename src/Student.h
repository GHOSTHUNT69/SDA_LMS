#pragma once
#include"Person.h"
#include"Registration_fwd.h"
//#include"Registration.h"
#include"Section_fwd.h"
#include<vector>
#include<string>
using std::string;
using std::vector;

namespace LMS {
	class Student :
		public Person
	{
	protected:
		string rollno;
		vector<Registration*> sregistrations; //student registrations
	public:
		Student();
		/*Student(int a)
			:Person(3)
		{
			int j = a;
		}*/
		Student(string rollno_, string name_, string dob_, string email_, string _uname, string _password);
		Student(string rollno_, string name_, string dob_, string email_, string _uname, string _password, vector<Registration*> reg_);
		~Student();
		
		string get_role();
		bool addRegistration(Registration*  reg_);
		bool addRegistration(Section*  reg_);
	};
}

