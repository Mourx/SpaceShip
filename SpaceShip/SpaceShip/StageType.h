#pragma once
#include "enums.h"
#include <vector>
using namespace std;

class StageType
{
public:
	StageType(STAGE_TYPE t,bool bStartNode, bool bEndNode);
	~StageType();
	STAGE_TYPE GetType();
	int getPaths();
private:
	STAGE_TYPE type;
	vector<StageType*> nextStages;
	int paths;
};

