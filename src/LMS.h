#pragma once
#include "Student_fwd.h"
#include "Faculty_fwd.h"
#include "AcademicOfficer_fwd.h"
#include "Person_fwd.h"
#include "Section_fwd.h"
#include "Course_fwd.h"
#include "Registration_fwd.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

namespace LMS
{
	constexpr auto LOG_SUCCESS = 1;
	constexpr auto LOG_FAIL = 0;
	constexpr auto ALREADY_LOGGED = 2;

	class App
	{
	private:
		bool islogged;
		Person *loggedUser;

		vector<AcademicOfficer *> officers;

		Student *StudentLogin(string _username, string _password);
		Faculty *FacultyLogin(string _username, string _password);
		AcademicOfficer *OfficerLogin(string _username, string _password);

		Section* getSection(string sectionName);
		Section* getSection(string courseCode, string sectionName);
		Course* getCourse(string courseCode);
		Student* getStudent(string _rollno);

	public:
		App();
		~App();

		bool Login(string _username, string _password);
		bool Logout();

		bool isLogged();
		Person *LoggedUser();
		string get_role();

		vector<Student*> getStudents();
		vector<Faculty*> getTeachers();
		vector<Section*> getSections();
		vector<Course*> getCourses();

		//Officer Functionaliteies
		bool addStudent(Student *);
		bool addTeacher(Faculty *);
		bool addSection(Section *);
		bool addCourse(Course *);
		bool linkCourseSection(string courseCode, string sectionName);
		bool linkCourseSection(Course*, Section*);
		bool linkStudentSection(string _rollno,string courseCode, string sectionName);
		bool linkStudentSection(Student*, Section*);
		//bool linkTeacherSection()
		/*Acadamic Oficer :
		-set deadline for add / drop / withdraw course
			- can add students / teachers / courses / sections
			- can link course / section
			- can link student / registration / course*/

		//Student
		vector<Registration*> getRegistrations();
		bool addRegistration(string courseCode, string sectionName);
		bool dropRegistration(string courseCode, string sectionName);
		/*	
			- can view courses and sections
			- can add / drop / withdraw course during registration period
			- can view transcript
		*/

		//Teacher
		/*
			- can record attendence
			- set marks evaluation
			- can add grade
		*/

		
	};
} // namespace LMS
