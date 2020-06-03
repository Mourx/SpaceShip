#pragma once
#include "Enemy.h"
#include "Charge.h"
#include <SFML/Graphics.hpp>
class Enemy;
class Charge;
using namespace sf;
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

