#pragma once
#include "StageType.h"
#include <vector>
using namespace std;

class StagePath
{
public:
	StagePath(RenderWindow* window);
	~StagePath();
	void GeneratePath();
	void Draw();
private:
	vector<int> stageAmounts;
	vector<vector<StageType*>> stages;
	StageType* startStage;
	int tiers = 8;
	RenderWindow* w;
};

