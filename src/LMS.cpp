#include "LMS.h"
#include "AcademicOfficer.h"
#include "Student.h"
#include "Faculty.h"

bool LMS::LMS::StudentLogin(string _username, string _password)
{
    for(auto student:students)
        if(student->check_login(_username))
    return false;
}

bool LMS::LMS::FacultyLogin(string _username, string _password)
{
    return false;
}

bool LMS::LMS::OfficerLogin(string _username, string _password)
{
    return false;
}
