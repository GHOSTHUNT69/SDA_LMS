#pragma once
#include <iostream>
#include <string>
#include "LMS.h"
#include "Student.h"
using namespace std;

int main()
{
	LMS::App *ptr = new LMS::App();
	ptr->addStudent(new LMS::Student());
	cout << "Hello World";
	char arr[] = "asasd";
}