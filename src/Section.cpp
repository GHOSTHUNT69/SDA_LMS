#pragma once
#include "Section.h"

namespace LMS
{

	Section::Section()
		: steacher(nullptr), ssession(nullptr), scourse(nullptr)
	{
	}

	Section::Section(string _name, Course *_course, Faculty *_teacher, Session *_session)
		: sname(_name), scourse(_course), steacher(_teacher), ssession(_session)
	{
	}

	Section::Section(string _name, Course *_course, Faculty *_teacher, Session *_session, vector<Registration *> _regs, vector<Evaluation *> _evals)
		: sregistrations(_regs), sevaluations(_evals), ssession(_session), steacher(_teacher), scourse(_course), sname(_name)
	{
	}

	Section::~Section()
	{
	}
	/*bool Section::set_course(Course*)
	{
		return ;
	}*/
	string Section::get_name()
	{
		return sname;
	}
	Course* Section::getCourse()
	{
		return scourse;
	}
	Faculty* Section::getTeacher()
	{
		return steacher;
	}
	int Section::getStudentCount()
	{
		return sregistrations.size();
	}
	bool Section::updateCourse(Course* _new)
	{
		scourse = _new;
		return true;
	}
	bool Section::updateTeacher(Faculty* _new)
	{
		steacher = _new;
		return true;
	}
	bool Section::addRegistration(Registration *_reg)
	{
		sregistrations.push_back(_reg);
		return true;
	}
} // namespace LMS
