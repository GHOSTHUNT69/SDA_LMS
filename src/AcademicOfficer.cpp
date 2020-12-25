#pragma once
#include"AcademicOfficer.h"
#include"Registration.h"
#include"Student.h"
#include"Section.h"
#include"Course.h"
#include"Session.h"

namespace LMS {
	AcademicOfficer::AcademicOfficer()
	{
	}

	AcademicOfficer::~AcademicOfficer()
	{
	}

	bool AcademicOfficer::addCourse(Course* _course)
	{
		courses.push_back(_course);
		return true;
	}

	bool AcademicOfficer::addStudent(Student*_student)
	{
		students.push_back(_student);
		return true;
	}

	bool AcademicOfficer::registerStudent(Student*_student, Section*_section)
	{
		Registration* newreg=new Registration(_student, _section);
		_student->addRegistration(newreg);
		_section->addRegistration(newreg);
		return true;
	}

	vector<Student*> AcademicOfficer::getStudents()
	{
		return students;
	}

	bool AcademicOfficer::addTeacher(Faculty*_teacher)
	{
		teachers.push_back(_teacher);
		return true;
	}

	vector<Faculty*> AcademicOfficer::getTeachers()
	{
		return teachers;
	}

	bool AcademicOfficer::addSession(Session*_session)
	{
		sessions.push_back(_session);
		return true;
	}
}
