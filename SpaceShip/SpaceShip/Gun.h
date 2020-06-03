#pragma once
#include "Charge.h"
#include <SFML/Graphics.hpp>
#include "Tile.h"
using namespace sf;
class Charge;

class Gun
{
public:
	Gun();
	Gun(Charge* c);
	~Gun();

	Sprite icon;
	int row=0;
private:
	Charge* charge;
	Texture gunTex;
};

