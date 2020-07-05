#pragma once
#include "Charge.h"
#include "ChargeFactory.h"
class Shoption
{
public:
	Shoption();
	~Shoption();
	virtual void Draw(RenderWindow* w);
	virtual void SetPosition(int x, int y);
protected:
	int cost;
	ChargeFactory fact;
	Text costText;
	Font font;
};


class ShoptionCharge : public Shoption {
public:
	ShoptionCharge();
	~ShoptionCharge();
	void Draw(RenderWindow* w);
	void SetPosition(int x, int y);
	Charge* getCharge();
private:
	Charge* charge;
};


class ShoptionBonus : public Shoption {
public:
	ShoptionBonus();
	~ShoptionBonus();
};

