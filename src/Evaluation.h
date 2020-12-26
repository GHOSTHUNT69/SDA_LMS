#pragma once
#include "EvaluationResult_fwd.h"
#include <vector>
using std::vector;

namespace LMS
{
	class Evaluation
	{
	protected:
		vector<EvaluationResult *> evaluationR; //evaluation results
	public:
		Evaluation();
		~Evaluation();
	};
} // namespace LMS
