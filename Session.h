#pragma once
#include"Section_fwd.h"
#include<vector>
#include<string>
using std::vector;
using std::string;

namespace LMS {
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
}