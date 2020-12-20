#pragma once
#include "Course.h"
#include "Registration.h"
#include "Evaluation.h"
#include "Session.h"
#include "Faculty.h"


class Section :
	protected Course
{
protected:
	vector<Registration> sregistrations;
	vector<Evaluation> sevaluations;
	Session ssession;
	Faculty steacher;
	Course scourse;
	//waiting list
public:
};

