#include "Section.h"

namespace LMS {

	Section::Section()
	{
	}

	Section::Section(vector<Registration*> sregistrations_, vector<Evaluation*> sevaluations_, Session* ssession_, Faculty* steacher_, Course* scourse_, string sectionname_)
		:sregistrations(sregistrations_), sevaluations(sevaluations_), ssession(ssession_), steacher(steacher_), scourse(scourse_), sectionname(sectionname_)
	{
	}

	Section::~Section()
	{
	}
}
