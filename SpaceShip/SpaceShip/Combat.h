#pragma once
#include "Player.h"
#include "Tile.h"
#include <vector>
#include "Charge.h"

using namespace std;
class Charge;

class Combat
{
public:
	Combat(RenderWindow* w);
	~Combat();
	void Draw();
	void MouseDown(Vector2f m);
	void MouseUp(Vector2f m);
	void MoveMouse(Vector2f m);
	void Update(Time t);
private:
	Player* player;
	float offsetX;
	float offsetY;
	Vector2f snapPos;
	Gun* highlitGun = NULL;
	RenderWindow* window;
	float gridX = 400;
	float gridY = 100;
	vector<vector<Tile*>> combatGrid;
	Sprite space;
	Texture spaceTex;

};

