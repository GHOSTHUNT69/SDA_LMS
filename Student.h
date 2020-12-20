#pragma once
#include"Headers.h"
#include<vector>
#include<string>
using std::string;
using std::vector;

//using classes
class Person;
class Registration;
//class Section;

class Student :
    protected Person
{
protected:
    string rollno;
    vector<Registration*> sregistrations; //student registrations
public:
    Student();
    Student(string rollno_, string name_, string dob_, string email_);
    Student(string rollno_, string name_, string dob_, string email_, vector<Registration*> reg_);
    ~Student();
};

