#pragma once
#include "Person.h"
#include "Section_fwd.h"
#include "Faculty_fwd.h"
#include "Session_fwd.h"
#include "Course_fwd.h"
#include "Student_fwd.h"
#include "Registration.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

namespace LMS
{
    class AcademicOfficer : public Person
    {
    public:
        static vector<Course *> courses;
        static vector<Student *> students;
        static vector<Faculty *> teachers;
        static vector<Session *> sessions;
        static vector<Section*> sections;
    public:
        AcademicOfficer();
        AcademicOfficer(string name_, string dob_, string email_, string _uname, string _password);
        ~AcademicOfficer();

        string get_role();

        static vector<Student *> getStudents();
        static vector<Faculty *> getTeachers();
        static vector<Course *> getCourses();
        static vector<Session*> getSessions();
        static vector<Section *> getSections();

        static bool addStudent(Student *);
        static bool addTeacher(Faculty *);
        static bool addCourse(Course *);
        static bool addSession(Session *);
        static bool addSection(Section*);

        static bool registerStudent(Student *, Section *);
    };
} // namespace LMS