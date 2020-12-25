#pragma once
#include"Student_fwd.h"
#include"Faculty_fwd.h"
#include"AcademicOfficer_fwd.h"
#include"Person_fwd.h"
#include<vector>
#include<string>
using std::string;
using std::vector;

namespace LMS {
	constexpr auto LOG_SUCCESS = 1;
	constexpr auto LOG_FAIL = 0;
	constexpr auto ALREADY_LOGGED = 2;

	class App
	{
	private:
		bool islogged;
		Person* loggedUser;

		vector<AcademicOfficer*> officers;

		Student* StudentLogin(string _username, string _password);
		Faculty* FacultyLogin(string _username, string _password);
		AcademicOfficer* OfficerLogin(string _username, string _password);
	public:
		App();
		~App();

		Person* Login(string _username, string _password);

		bool isLogged();
		Person* LoggedUser();

		//student
		bool addStudent(Student*);
	};
}

