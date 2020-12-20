#pragma once
#include"Headers.h"

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
};

