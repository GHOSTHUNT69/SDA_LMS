#pragma once
//#include"Registration_fwd.h"

namespace LMS
{
	constexpr auto ABSENT = 0;
	constexpr auto PRESENT = 1;
	constexpr auto LATE = 2;

	struct time_a
	{
		int day;
		int month;
		int year;
	};

	class Attendance
	{
		time_a atime;
		int attend;

	public:
		Attendance();
		Attendance(int _attend);
		Attendance(time_a _atime, int _attend);
		~Attendance();
		void markPresent();
		void markAbsent();
		void markLate();
		void markAttendance(int _attend);
		int getAttendance();
		time_a getTime();
		void changeTime(time_a _atime);
	};
} // namespace LMS