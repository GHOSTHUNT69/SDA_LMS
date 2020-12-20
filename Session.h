#pragma once
#include"LMS.h"

class Section;

class Session
{
protected:
	string sessionD;//session detail e.g Fall 2020
	vector<Section*> sesection;//session sections
	bool regOpen;
	//sections vector
public:
	//registration close or open function
	Session();
	Session(string sessionD_, vector<Section*> sesection_, bool regOpen_);
	~Session();
};

