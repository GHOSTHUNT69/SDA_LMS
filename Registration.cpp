#include "Registration.h"

namespace LMS {

	Registration::Registration()
	{
	}

	Registration::Registration(Student* student_, Section* ssection_, vector<EvaluationResult*> seresults_, vector<Attendance*> sattendance_)
		:student(student_), ssection(ssection_), seresults(seresults_), sattendance(sattendance_)
	{
	}

	Registration::~Registration()
	{
	}
}
