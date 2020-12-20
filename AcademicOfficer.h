#pragma once
#include"LMS.h"
#include<vector>
#include<string>
using std::string;
using std::vector;

//using these classes
class Person;
class Student;
class Faculty;
class Session;

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

    //course
    bool addCourse(Course*);
    bool addCourse(string, string);
   
    //student
    bool addStudent(Student*);
    bool addStudent();
    
    //teacher
    bool addTeacher(Faculty*);
    bool addTeacher();
    
    //session
    bool addSession(Session*);
    bool addSession();

};

