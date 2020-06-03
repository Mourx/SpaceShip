#pragma once
#include <SFML/Graphics.hpp>
#include "Gun.h"
#include "Tile.h"
#include <iostream>
class Gun;
class Tile;
using namespace sf;
using namespace std;
class Charge
{
public:
	Charge();
	virtual ~Charge() = default;
	virtual void Fire(Gun* g,vector<vector<Tile*>> grid) { cout << "base" << endl; }
	virtual void Update(Time t);
	virtual void StartTimer(Time t) {};
	virtual void Draw(RenderWindow* w);
	Sprite icon;
	Sprite chargeEffect;
	int handPos = 0;
protected:
	float damage;
	int width;
	Texture chargeTex;
	Texture chargeEffTex;
	float timer;
	float effectTime = 0;
	bool bEffectVisible = false;
};


class BasicCharge : public Charge {
public:
	BasicCharge();
	~BasicCharge();
	void Fire(Gun* g, vector<vector<Tile*>> grid);
	void StartTimer(Time t);
};
