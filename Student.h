#pragma once
#include"Headers.h"

class Person;
class Registration;

class Student :
    protected Person
{
protected:
    vector<Registration*> sregistrations; //student registrations
public:
};

