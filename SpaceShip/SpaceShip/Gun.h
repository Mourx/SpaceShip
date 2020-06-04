#pragma once
#include "Charge.h"
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Shield.h"
using namespace sf;
class Charge;
class Shield;
class Gun
{
public:
	Gun();
	Gun(Charge* c);
	~Gun();
	void SetPosition(Vector2f vec);
	Sprite icon;
	int row=0;
	Shield* shield;
	void Draw(RenderWindow* w);
private:
	Charge* charge;
	Texture gunTex;
};

