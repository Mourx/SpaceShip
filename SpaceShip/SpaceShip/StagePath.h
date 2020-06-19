#pragma once
#include "StageType.h"
#include <vector>
using namespace std;

class StagePath
{
public:
	StagePath();
	~StagePath();
	void GeneratePath();
private:
	vector<vector<StageType*>> stages;
	StageType* startStage;
	int tiers = 8;
};

