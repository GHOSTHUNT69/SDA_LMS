#pragma once
#include "Registration.h"
#include "Attendance.h"
#include "Section.h"
#include "Course.h"

namespace LMS
{

	Registration::Registration()
		: student(nullptr), ssection(nullptr)
	{
	}

	Registration::Registration(Student *_student, Section *_ssection)
		: student(_student), ssection(_ssection)
	{
	}

	Registration::Registration(Student *_student, Section *_ssection, vector<EvaluationResult *> _seresults, vector<Attendance *> _sattendance)
		: student(_student), ssection(_ssection), seresults(_seresults), sattendance(_sattendance)
	{
	}

	Registration::~Registration()
	{
	}
	Course* Registration::getCourse()
	{
		return ssection->getCourse();
	}
	Section* Registration::getSection()
	{
		return ssection;
	}
	Student* Registration::getStudent()
	{
		return student;
	}
	Faculty* Registration::getTeacher()
	{
		return ssection->getTeacher();
	}
	void Registration::markAttendance(int _attend)
	{
		sattendance.push_back(new Attendance(_attend));
	}
} // namespace LMS
