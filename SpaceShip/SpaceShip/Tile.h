#pragma once
#include "Enemy.h"
class Enemy;
class Tile
{
public:
	Tile(float x,float y);
	~Tile();
	void setUnit(Enemy* u);
	Enemy* getUnit();
	bool bHasUnit = false;
	Sprite icon;

private:
	Enemy* unit;
	float posX;
	float posY;
	Texture tileTex;
};

