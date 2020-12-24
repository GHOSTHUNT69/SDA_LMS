#pragma once
#include "Attendance.h"
#include <ctime>

namespace LMS
{
	Attendance::Attendance()
	{
		atime = { -1 };
		attend = -1;
	}

	Attendance::Attendance(int _attend)
	{
		struct tm tPtr;
		time_t now = time(0);
		localtime_s(&tPtr, &now);
		atime = { tPtr.tm_mday, tPtr.tm_mon + 1, tPtr.tm_year + 1990 };
		attend = _attend;
	}

	Attendance::Attendance(time_a _atime, int _attend)
	{
		atime = _atime;
		attend = _attend;
	}

	Attendance::~Attendance()
	{
	}

	void Attendance::markPresent()
	{
		attend = PRESENT;
	}
	void Attendance::markAbsent()
	{
		attend = ABSENT;
	}
	void Attendance::markLate()
	{
		attend = LATE;
	}

	void Attendance::markAttendance(int _attend)
	{
		attend = _attend;
	}

	int Attendance::getAttendance()
	{
		return attend;
	}

	time_a Attendance::getTime()
	{
		return atime;
	}
	void Attendance::changeTime(time_a _atime)
	{
		atime = _atime;
	}
}
