#pragma once
#include "Player.h"
#include "Tile.h"
#include <vector>

using namespace std;

class Combat
{
public:
	Combat(RenderWindow* w);
	~Combat();
	void Draw();
	bool CheckMouse(Vector2f m);
private:
	Player* player;
	RenderWindow* window;
	float gridX = 400;
	float gridY = 100;
	vector<vector<Tile*>> combatGrid;
	Sprite space;
	Texture spaceTex;
};

