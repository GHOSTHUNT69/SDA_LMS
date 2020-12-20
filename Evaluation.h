#pragma once
#include "Headers.h"
#include<vector>
using std::vector;

class EvaluationResult;

class Evaluation
{
protected:
	vector<EvaluationResult*> evaluationR;//evaluation results
public:
	Evaluation();
	~Evaluation();

};

