#pragma once
#include"Person.h"
#include"Section_fwd.h"
#include"Faculty_fwd.h"
#include"Session_fwd.h"
#include"Course_fwd.h"
#include"Student_fwd.h"
#include<vector>
#include<string>
using std::string;
using std::vector;

namespace LMS {
    class AcademicOfficer :
        protected Person
    {
    protected:
        vector<Course*> courses;
        vector<Student*> students;
        vector<Faculty*> teachers;
        vector<Session*> sessions;
    public:
        AcademicOfficer();
        ~AcademicOfficer();

        ////course
        //bool addCourse(Course*);
        //bool addCourse(string, string);

        ////student
        //bool addStudent(Student*);
        //bool addStudent();

        ////teacher
        //bool addTeacher(Faculty*);
        //bool addTeacher();

        ////session
        //bool addSession(Session*);
        //bool addSession();

    };
}

