#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Charge
{
public:
	Charge();
	~Charge();
	virtual void Fire() {}
	Sprite icon;
protected:
	float damage;
	int width;
	Texture chargeTex;

};


class BasicCharge : public Charge {
public:
	BasicCharge() {
		chargeTex.loadFromFile("basicCharge.png");
		icon.setTexture(chargeTex);
		icon.setScale(1, 1);
	}
	~BasicCharge() {

	}
	void Fire() {
		//take row
		//fire at front enemy
	}
};
