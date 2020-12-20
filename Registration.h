#pragma once
#include<vector>
#include"EvaluationResult.h"
#include"Attendance.h"
using std::vector;

class Student;
class Section;

class Registration
{
protected:
	Student* student;//student
	Section* ssection;//student section
	vector<EvaluationResult*> seresults;//student evaluation results
	vector<Attendance*> sattendance;//student attendance
public:
};

