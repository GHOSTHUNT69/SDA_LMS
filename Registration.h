#pragma once
#include"Student_fwd.h"
#include"Section_fwd.h"
#include"Attendance_fwd.h"
#include"EvaluationResult_fwd.h"
#include<vector>
using std::vector;

namespace LMS {
	class Registration
	{
	protected:
		Student* student;//student
		Section* ssection;//student section
		vector<EvaluationResult*> seresults;//student evaluation results
		vector<Attendance*> sattendance;//student attendance
	public:
		Registration();
		Registration(Student* student_, Section* ssection_, vector<EvaluationResult*> seresults_, vector<Attendance*> sattendance_);
		~Registration();
	};
}

