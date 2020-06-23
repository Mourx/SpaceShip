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
private:
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
	int currentTier = 3;
};

