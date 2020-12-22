#pragma once
#include"Student_fwd.h"
#include"Faculty_fwd.h"
#include"AcademicOfficer_fwd.h"
#include"Person.h"
#include<vector>
#include<string>
using std::string;
using std::vector;

namespace LMS {
	constexpr auto LOG_SUCCESS = 1;
	constexpr auto LOG_FAIL = 0;
	constexpr auto ALREADY_LOGGED = 2;

	class LMS
	{
	private:
		bool islogged;
		Person* loggedUser;
		vector<Student*> students;
		vector<Faculty*>teachers;
		vector<AcademicOfficer*> officers;

		bool slogin(string _username, string _password);
		bool flogin(string _username, string _password);
		bool ologin(string _username, string _password);
	public:
		int StudentLogin(string _username, string _password);
		int FacultyLogin(string _username, string _password);
		int OfficerLogin(string _username, string _password);
		bool islogged();
		Person* LoggedUser();
	};
}

