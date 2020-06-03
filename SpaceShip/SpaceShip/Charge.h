#pragma once
#include <SFML/Graphics.hpp>
#include "Gun.h"
#include <iostream>
class Gun;

using namespace sf;
using namespace std;
class Charge
{
public:
	Charge();
	virtual ~Charge() = default;
	virtual void Fire(Gun* g) { cout << "base" << endl; }
	virtual void Update(Time t) {};
	virtual void StartTimer(Time t) {};
	virtual void Draw(RenderWindow* w) {};
	Sprite icon;
	Sprite chargeEffect;
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
	void Fire(Gun* g);
	void Update(Time t);
	void StartTimer(Time t);
	void Draw(RenderWindow* w);
};
