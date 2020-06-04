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
	void Draw(RenderWindow* w);
	Sprite icon;
	String getName();
	Sprite attackIcon;
	Sprite healthIcon;
	float getHealth();
	Text attackText;
	Text healthText;
	void Damage(int dmg);
	bool bIsDead = false;
	int bounty = 5;
protected:
	String name;
	int damage;
	int health;
	Ship* ship;
	Texture iconTex;
	Texture attackTex;
	Texture healthTex;
	Font font;
};

class Dummy : public Enemy 
{
public:
	Dummy();
	~Dummy();
};