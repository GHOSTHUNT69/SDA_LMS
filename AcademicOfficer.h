#pragma once
#include"Person_fwd.h"
#include"Section_fwd.h"
#include"Faculty.h"
#include"Session.h"
#include"Course.h"
#include"Student.h"
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

