#pragma once
#include"LMS.h"
#include<vector>
using std::vector;

class Student;
class Section;
class Attendance;
class EvaluationResult;

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

