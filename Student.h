#pragma once
#include "Person.h"
#include "Registration.h"

class Student :
    protected Person
{
protected:
    vector<Registration*> sregistrations; //student registrations
public:
};

