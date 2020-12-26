#pragma once
#include "LMS.h"
//#include "Person.h"
#include "AcademicOfficer.h"
#include "Student.h"
#include "Faculty.h"
#include "Section.h"
#include "Course.h"

namespace LMS
{

	App::App()
	{
		islogged = false;
		loggedUser = nullptr;
		//loggedUser = new AcademicOfficer();
		officers.push_back(new AcademicOfficer("admin", "", "admin@example.com", "admin", "admin"));
	}

	App::~App()
	{
	}

	bool App::Login(string _username, string _password)
	{
		if (islogged)
			return false;
		loggedUser = OfficerLogin(_username, _password);
		if (loggedUser)
		{
			islogged = true;

			return true;
		}
		loggedUser = FacultyLogin(_username, _password);
		if (loggedUser) {
			islogged = true;
			return true;
		}
		loggedUser = StudentLogin(_username, _password);
		if (loggedUser) {
			islogged = true;
			return true;
		}
		return false;
	}

	bool App::Logout()
	{
		if (islogged)
		{
			islogged = false;
			loggedUser = nullptr;
			return true;
		}
		return false;
	}

	Student* App::StudentLogin(string _username, string _password)
	{
		for (auto x : AcademicOfficer::getStudents())
			if (x->check_login(_username, _password))
				return x;
		return nullptr;
	}

	Faculty* App::FacultyLogin(string _username, string _password)
	{
		for (auto x : AcademicOfficer::getTeachers())
			if (x->check_login(_username, _password))
				return x;
		return nullptr;
	}

	AcademicOfficer* App::OfficerLogin(string _username, string _password)
	{
		for (auto officer : officers)
			if (officer->check_login(_username, _password))
				return officer;
		return nullptr;
	}

	bool App::isLogged()
	{
		return islogged;
	}

	Person* App::LoggedUser()
	{
		return loggedUser;
	}
	bool App::addStudent(Student* _new)
	{
		if (islogged && loggedUser->get_role() == "officer")
		{
			AcademicOfficer::addStudent(_new);
			return true;
		}
		return false;
	}
	bool App::addTeacher(Faculty*_new)
	{
		if (islogged && loggedUser->get_role() == "officer")
		{
			AcademicOfficer::addTeacher(_new);
			return true;
		}
		return false;
	}
	bool App::addSection(Section*_new)
	{
		/*if (islogged && loggedUser->get_role() == "officer")
		{
			AcademicOfficer::addSection(_new);
			return true;
		}
		*/
		return false;
	}
	vector<Student*> App::getStudents()
	{
		return AcademicOfficer::getStudents();
	}
	vector<Faculty*> App::getTeachers()
	{
		return AcademicOfficer::getTeachers();
	}
}