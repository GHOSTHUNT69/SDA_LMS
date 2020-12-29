#pragma once
#include "Person.h"
#include "Registration_fwd.h"
//#include"Registration.h"
#include"Course_fwd.h"
#include "Section_fwd.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

namespace LMS
{
	class Student : public Person
	{
	protected:
		string rollno;
		vector<Registration *> sregistrations; //student registrations
	public:
		Student();
		Student(string rollno_, string name_, string dob_, string email_, string _uname, string _password);
		Student(string rollno_, string name_, string dob_, string email_, string _uname, string _password, vector<Registration *> reg_);
		~Student();

		string get_role();
		string get_rollno();

		bool addRegistration(Registration *reg_);
		bool addRegistration(Section *reg_);

		vector<Registration*> getRegistrations();
	};
} // namespace LMS
