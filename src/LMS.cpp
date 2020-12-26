#pragma once
#include "LMS.h"
//#include "Person.h"
#include "AcademicOfficer.h"
#include "Student.h"
#include "Faculty.h"
#include "Section.h"
#include "Course.h"
#include <algorithm>//find

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
		if (loggedUser)
		{
			islogged = true;
			return true;
		}
		loggedUser = StudentLogin(_username, _password);
		if (loggedUser)
		{
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
	bool App::addTeacher(Faculty* _new)
	{
		if (islogged && loggedUser->get_role() == "officer")
		{
			AcademicOfficer::addTeacher(_new);
			return true;
		}
		return false;
	}
	bool App::addSection(Section* _new)
	{
		/*if (islogged && loggedUser->get_role() == "officer")
		{
			AcademicOfficer::addSection(_new);
			return true;
		}
		*/
		return false;
	}
	bool App::addCourse(Course* _new)
	{
		if (islogged && loggedUser->get_role() == "officer")
		{
			AcademicOfficer::addCourse(_new);
			return true;
		}
		return false;
	}
	bool App::addCourseToSection(Course* _course, Section* _section)
	{
		if (islogged && loggedUser->get_role() == "officer")
		{
			_course->addSection(_section);
			addSection(new Section(_section->get_name(), _course));
			return true;
		}
		return false;
	}
	bool App::addCourseToSection(string courseCode, string sectionName)
	{
		if (islogged && loggedUser->get_role() == "officer")
		{
			Course* _course = nullptr;
			Section* _sec = nullptr;
			for (auto i : AcademicOfficer::getCourses())
				if (i->get_ccode() == courseCode)
				{
					_course = i;
					break;
				};
			for (auto i : AcademicOfficer::getSections())
				if (i->get_name() == sectionName)
				{
					_sec = i;
					break;
				};
			if (_course == nullptr || _sec == nullptr)
				return false;
			addCourseToSection(_course, _sec);
			return true;
		}
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
	vector<Section*> App::getSections()
	{
		return AcademicOfficer::getSections();
	}
	vector<Course*> App::getCourses()
	{
		return AcademicOfficer::getCourses();
	}
} // namespace LMS