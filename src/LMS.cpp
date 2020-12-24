#pragma once
#include "LMS.h"
//#include "Person.h"
#include "AcademicOfficer.h"
#include "Student.h"
#include "Faculty.h"

namespace LMS
{
    //Person* LMS::slogin(string _username, string _password)
    //{
    //    /*for (auto student : students)
    //        if (student->check_login(_username, _password))
    //            return student;
    //    return nullptr;*/
    //}

    //Person* LMS::flogin(string _username, string _password)
    //{
    //    /*for (auto student : students)
    //        if (student->check_login(_username, _password))
    //            return student;
    //    return nullptr;*/
    //}

    //Person* LMS::ologin(string _username, string _password)
    //{
    //    return nullptr;
    //}

    App::App()
    {
    }

    Student* App::StudentLogin(string _username, string _password)
    {
        try
        {
            for (auto student : ((AcademicOfficer*)loggedUser)->getStudents())
                if (student->check_login(_username, _password))
                    return student;
        }
        catch (const std::exception&)
        {
            return nullptr;
        }
        return nullptr;
    }

    Faculty* App::FacultyLogin(string _username, string _password)
    {
        try 
        {
            for (auto teacher : ((AcademicOfficer*)loggedUser)->getTeachers())
                if (teacher->check_login(_username, _password))
                    return teacher;
        }
        catch (const std::exception&)
        {
            return nullptr;
        }
        return nullptr;
    }

    AcademicOfficer* App::OfficerLogin(string _username, string _password)
    {
        for (auto officer : officers)
            if (officer->check_login(_username, _password))
                return officer;
        return nullptr;
    }

    bool App::isLogged()
    {
        return islogged;
    }

    Person* App::LoggedUser()
    {
        return loggedUser;
    }
    bool App::addStudent(Student*_new)
    {
        try
        {
            ((AcademicOfficer*)loggedUser)->addStudent(_new);
            return true;
        }
        catch (const std::exception&)
        {
            //cout<<e.what();
            return false;
        }

        return false;
    }
}