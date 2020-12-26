#pragma once
#include "Student_fwd.h"
#include "Section_fwd.h"
#include "Attendance_fwd.h"
#include "EvaluationResult_fwd.h"
#include <vector>
using std::vector;

namespace LMS
{
	class Registration
	{
	protected:
		Student *student;					  //student
		Section *ssection;					  //student section
		vector<EvaluationResult *> seresults; //student evaluation results
		vector<Attendance *> sattendance;	  //student attendance
	public:
		Registration();
		Registration(Student *_student, Section *_ssection);
		Registration(Student *_student, Section *_ssection, vector<EvaluationResult *> _seresults, vector<Attendance *> _sattendance);
		~Registration();

		void markAttendance(int _attend);
		vector<Attendance *> getAttendance();
	};
} // namespace LMS
