#include "Faculty.h"

namespace LMS {

	Faculty::Faculty()
	{
	}

	Faculty::Faculty(string name_, string dob_, string email_)
		:Person(name_, dob_, email_)
	{
	}

	Faculty::Faculty(string name_, string dob_, string email_, vector<Section*> fsections_)
		: Person(name_, dob_, email_), fsections(fsections_)
	{
	}

	Faculty::~Faculty()
	{
	}
}
