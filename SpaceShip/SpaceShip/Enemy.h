#pragma once
#include "Ship.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Ship;
class Enemy
{
public:
	Enemy();
	~Enemy();
	void setPosition(float x, float y);
	Sprite icon;
private:
	Ship* ship;
	Texture iconTex;
};

