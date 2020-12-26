#pragma once
#include "AcademicOfficer.h"
#include "Registration.h"
#include "Student.h"
#include "Section.h"
#include "Course.h"
#include "Session.h"

namespace LMS
{

	vector<Course *> AcademicOfficer::courses;
	vector<Student *> AcademicOfficer::students;
	vector<Faculty *> AcademicOfficer::teachers;
	vector<Session *> AcademicOfficer::sessions;
	vector<Section*> AcademicOfficer::sections;

	AcademicOfficer::AcademicOfficer()
	{
	}

	AcademicOfficer::AcademicOfficer(string name_, string dob_, string email_, string _uname, string _password)
		: Person(name_, dob_, email_, _uname, _password)
	{
	}

	AcademicOfficer::~AcademicOfficer()
	{
	}

	string AcademicOfficer::get_role()
	{
		return "officer";
	}

	bool AcademicOfficer::addCourse(Course *_course)
	{
		courses.push_back(_course);
		return true;
	}

	bool AcademicOfficer::addStudent(Student *_student)
	{
		students.push_back(_student);
		return true;
	}

	bool AcademicOfficer::registerStudent(Student *_student, Section *_section)
	{
		Registration *newreg = new Registration(_student, _section);
		_student->addRegistration(newreg);
		_section->addRegistration(newreg);
		return true;
	}

	vector<Student *> AcademicOfficer::getStudents()
	{
		return students;
	}

	bool AcademicOfficer::addTeacher(Faculty *_teacher)
	{
		teachers.push_back(_teacher);
		return true;
	}

	vector<Faculty *> AcademicOfficer::getTeachers()
	{
		return teachers;
	}

	vector<Course *> AcademicOfficer::getCourses()
	{
		return courses;
	}

	vector<Session *> AcademicOfficer::getSessions()
	{
		return sessions;
	}

	vector<Section*> AcademicOfficer::getSections()
	{
		return sections;
	}

	bool AcademicOfficer::addSession(Session *_session)
	{
		sessions.push_back(_session);
		return true;
	}
	bool AcademicOfficer::addSection(Section*_new)
	{
		sections.push_back(_new);
		return true;
	}
} // namespace LMS
