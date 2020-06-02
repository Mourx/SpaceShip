#pragma once
#include "Charge.h"
#include <SFML/Graphics.hpp>
using namespace sf;


class Gun
{
public:
	Gun();
	Gun(Charge* c);
	~Gun();

	Sprite icon;
private:
	Charge* charge;
	Texture gunTex;
};

