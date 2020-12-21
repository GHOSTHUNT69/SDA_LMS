#include "Section.h"

namespace LMS {

	Section::Section()
		:steacher(nullptr),ssession(nullptr),scourse(nullptr)
	{
	}

	Section::Section(string _name, Course* _course, Faculty* _teacher, Session* _session)
		:sname(_name),scourse(_course),steacher(_teacher),ssession(_session)
	{
	}

	Section::Section(string _name, Course* _course, Faculty* _teacher, Session* _session, vector<Registration*> _regs, vector<Evaluation*> _evals)
		:sregistrations(_regs), sevaluations(_evals), ssession(_session), steacher(_teacher), scourse(_course), sname(_name)
	{
	}

	Section::~Section()
	{
	}
	bool Section::addRegistration(Registration*_reg)
	{
		sregistrations.push_back(_reg);
		return true;
	}
}
