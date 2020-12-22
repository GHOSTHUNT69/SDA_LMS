#pragma once
#include "LMS.h"
//#include "Person.h"
#include "AcademicOfficer.h"
#include "Student.h"
#include "Faculty.h"

namespace LMS
{

    Person* LMS::slogin(string _username, string _password)
    {
        for (auto student : students)
            if (student->check_login(_username, _password))
                return student;
        return nullptr;
    }

    Person* LMS::flogin(string _username, string _password)
    {
        for (auto student : students)
            if (student->check_login(_username, _password))
                return student;
        return nullptr;
    }

    Person* LMS::ologin(string _username, string _password)
    {
        return nullptr;
    }

    Student* LMS::StudentLogin(string _username, string _password)
    {

        for (auto student : students)
            if (student->check_login(_username, _password))
                return student;
        return nullptr;
    }

    Faculty* LMS::FacultyLogin(string _username, string _password)
    {
        for (auto teacher : teachers)
            if (teacher->check_login(_username, _password))
                return teacher;
        return nullptr;
    }

    AcademicOfficer* LMS::OfficerLogin(string _username, string _password)
    {
        for (auto officer : officers)
            if (officer->check_login(_username, _password))
                return officer;
        return nullptr;
    }

    bool LMS::isLogged()
    {
        return islogged;
    }

    Person* LMS::LoggedUser()
    {
        return loggedUser;
    }
}