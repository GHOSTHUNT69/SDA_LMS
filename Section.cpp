#include "Section.h"

namespace LMS {

	Section::Section()
		:steacher(nullptr),ssession(nullptr),scourse(nullptr)
	{
	}

	Section::Section(string _name, Course* _course, Faculty* _teacher, Session* _session)
	{
	}

	Section::Section(vector<Registration*> sregistrations_, vector<Evaluation*> sevaluations_, Session* ssession_, Faculty* steacher_, Course* scourse_, string sectionname_)
		:sregistrations(sregistrations_), sevaluations(sevaluations_), ssession(ssession_), steacher(steacher_), scourse(scourse_), sname(sectionname_)
	{
	}

	Section::~Section()
	{
	}
}
