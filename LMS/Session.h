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
		Session(string _sessionD, vector<Section*> _sesection, bool _regOpen=true);
		~Session();

		bool addSection(Section*_sec);
		void closeReg();
		bool isRegOpen();

	};
}