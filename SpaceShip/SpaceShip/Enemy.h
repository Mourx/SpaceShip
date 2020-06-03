#pragma once
#include "Ship.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Ship;
class Enemy
{
public:
	Enemy();
	virtual ~Enemy();
	void setPosition(float x, float y);
	Sprite icon;
	String getName();
	float getHealth();
protected:
	String name;
	float health;
	Ship* ship;
	Texture iconTex;
};

class Dummy : public Enemy 
{
public:
	Dummy();
	~Dummy();
};