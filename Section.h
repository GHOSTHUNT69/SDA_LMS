#pragma once
#include"LMS.h"

class Registration;
class Evaluation;
class Faculty;
class Session;
class Course;


class Section
{
protected:
	vector<Registration*> sregistrations;
	vector<Evaluation*> sevaluations;
	Session* ssession;
	Faculty* steacher;
	Course* scourse;
	//waiting list
public:
	Section();
	Section(vector<Registration*> sregistrations_, vector<Evaluation*> sevaluations_, Session* ssession_, Faculty* steacher_, Course* scourse_);
	~Section();
};

