#pragma once
#include "StageType.h"
#include "Player.h"
#include <vector>
#include <iostream>
using namespace std;

class StagePath
{
public:
	StagePath(RenderWindow* window,Player* p);
	~StagePath();
	void GeneratePath();
	void Draw();
	void MouseDown(Vector2f m);
	void MouseUp(Vector2f m);
	void MoveMouse(Vector2f m);
	void Update(Time t);
	void GenerateEncounter();
	void UpdatePathing();
	PICK_STATE getState() { return phase; }
	STAGE_TYPE getStageType() { 
		if (selectedStage->GetType() != TREASURE) {
			return selectedStage->GetType();
		}
		//Debug code -- To be taken out when treasures ready
		else {
			return COMBAT;
		}
	}
private:
	Clock clock;
	vector<int> stageAmounts;
	vector<vector<StageType*>> stages;
	StageType* startStage;
	int tiers = 8;
	RenderWindow* w;
	Player* player;
	Sprite space;
	Texture spaceTex;
	Shader completed;
	Shader available;
	Shader unavailable;
	Shader mouseOver;
	StageType* hoverStage;
	int currentTier = 0;
	StageType* selectedStage = NULL;
	PICK_STATE phase = PICKING;
};

