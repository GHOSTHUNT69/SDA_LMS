// For help:https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
// For viewing the sql data and table(you can also write queries just like Microsoft SQL)
// https://sqlitebrowser.org/dl/
#pragma once
#include"sqlite3.h"
#include<string>
using std::string;
/*
* functions to
* initialize tables
* add data
* remove data
* update data
* retrive data
* data is -Students, Teachers, Acdemic Officers, Registrations, Courses, Attendance etc
*/

namespace LMS {
	class LMSDB
	{
		sqlite3* db;
	public:
		LMSDB();
		~LMSDB();
		static int callback(void* NotUsed, int argc, char** argv, char** azColName);

	};
}

