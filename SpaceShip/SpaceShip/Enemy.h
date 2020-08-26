#pragma once
#include "Ship.h"
#include "Gun.h"
#include "Charge.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Ship;
class Player;
class Gun;
class Charge;
class Enemy
{
public:
	Enemy();
	virtual ~Enemy();
	void setPosition(float x, float y);
	void Draw(RenderWindow* w);
	virtual void Attack(Gun* g, Player* p,int c) {};
	static Enemy* Create() { return new Enemy(); };
	virtual void Update(Time t);
	void DrawOver(RenderWindow* w);
	Sprite icon;
	String getName();
	Sprite attackIcon;
	Sprite healthIcon;
	float getHealth();
	Text attackText;
	Text healthText;
	void Damage(int dmg);
	bool bIsDead = false;
	int getBounty() { return bounty; };
protected:
	String name;
	Sprite attackEffect;
	bool bEffectVisible;
	bool bAttackDelayed = false;
	float delayTime = 0;
	float delayTimer = 0;
	float timer = 0;
	float effectTime = 500000;
	int damage;
	int health;
	float effectVal;
	Ship* ship;
	Texture iconTex;
	Texture attackTex;
	Texture healthTex;
	Texture chargeTex;
	Font font;
	Shader effectShade;
	int bounty = 5;
};

class Dummy : public Enemy 
{
public:
	Dummy();
	~Dummy();
	void Attack(Gun* g, Player* p, int c);
	static Enemy* Create() { return new Dummy(); };

};


class OrbBot : public Enemy
{
public:
	OrbBot();
	~OrbBot();
	void Attack(Gun* g, Player* p, int c);
	static Enemy* Create() { return new OrbBot(); };

};