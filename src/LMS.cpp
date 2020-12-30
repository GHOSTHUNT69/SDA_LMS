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

	Section* App::getSection(string sectionName)
	{
		for (auto i : AcademicOfficer::getSections())
			if (i->get_name() == sectionName)
				return i;
		return nullptr;
	}

	Section* App::getSection(string courseCode, string sectionName)
	{
		if (courseCode == "null") return getSection(sectionName);
		for (auto i : AcademicOfficer::getSections())
			if (i->get_name() == sectionName && i->getCourse()->get_ccode() == courseCode)
				return i;
		return nullptr;
	}

	Course* App::getCourse(string courseCode)
	{
		for (auto i : AcademicOfficer::getCourses())
			if (i->get_ccode() == courseCode)
				return i;
		return nullptr;
	}

	Student* App::getStudent(string _rollno)
	{
		for (auto i : AcademicOfficer::getStudents())
			if (i->get_rollno() == _rollno)
				return i;
		return nullptr;
	}

	Faculty* App::getTeacher(string name)
	{
		for (auto i : AcademicOfficer::getTeachers())
			if (i->get_name() == name)
				return i;
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
	string App::get_role()
	{
		if (islogged)
			return loggedUser->get_role();
		return "null";
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
		if (islogged && loggedUser->get_role() == "officer")
		{
			AcademicOfficer::addSection(_new);
			return true;
		}
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
	bool App::linkCourseSection(Course* _course, Section* _section)
	{
		if (islogged && loggedUser->get_role() == "officer")
		{
			_course->addSection(_section);
			_section->updateCourse(_course);
			return true;
		}
		return false;
	}
	bool App::linkStudentSection(string _rollno, string courseCode, string sectionName)
	{
		if (islogged && (loggedUser->get_role() == "officer" || loggedUser->get_role() == "student"))
		{
			Student* _stu = getStudent(_rollno);
			Section* _sec = getSection(courseCode, sectionName);
			linkStudentSection(_stu, _sec);
			return true;
		}
		return false;
	}
	bool App::linkStudentSection(Student* _student, Section* _section)
	{
		if (islogged && (loggedUser->get_role() == "officer" || loggedUser->get_role() == "student"))
		{
			Registration* _new = new Registration(_student, _section);
			_student->addRegistration(_new);
			_section->addRegistration(_new);
			return true;
		}
		return false;
	}
	bool App::linkTeacherSection(Faculty* _teacher, Section* _section)
	{
		if (islogged && loggedUser->get_role() == "officer")
		{
			_section->updateTeacher(_teacher);
			return true;
		}
		return false;
	}
	bool App::linkTeacherSection(string tname, string courseCode, string sectionName)
	{
		if (islogged && loggedUser->get_role() == "officer")
		{
			Faculty* _tea = getTeacher(tname);
			Section* _sec = getSection(courseCode, sectionName);
			if (_tea == nullptr || _sec == nullptr)
				return false;
			return linkTeacherSection(_tea, _sec);
		}
		return false;
	}
	vector<Registration*> App::getRegistrations()
	{
		if (islogged && loggedUser->get_role() == "student")
		{
			return ((Student*)loggedUser)->getRegistrations();
		}
		return vector<Registration*>();
	}
	bool App::addRegistration(string courseCode, string sectionName)
	{
		if (islogged && loggedUser->get_role() == "student" /*&& reg open or not*/)
		{
			Section* sec = getSection(courseCode, sectionName);
			if (sec == nullptr)
				return false;
			return linkStudentSection((Student*)loggedUser, sec);
		}
		return false;
	}
	bool App::dropRegistration(string courseCode, string sectionName)
	{
		if (islogged && loggedUser->get_role() == "student" /*&& reg open or not*/)
		{
			auto lst = ((Student*)loggedUser)->getRegistrations();
			int count = 0;
			for (unsigned int i = 0; i < lst.size();)
				if (lst[i]->getCourse()->get_ccode() == courseCode &&
					lst[i]->getSection()->get_name() == sectionName)
					lst.erase(lst.begin() + i);
				else ++i;
		}
		return false;
	}
	bool App::linkCourseSection(string courseCode, string sectionName)
	{
		if (islogged && loggedUser->get_role() == "officer")
		{
			Course* _course = getCourse(courseCode);
			Section* _sec = getSection(sectionName);
			if (_course == nullptr || _sec == nullptr)
				return false;
			linkCourseSection(_course, _sec);
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