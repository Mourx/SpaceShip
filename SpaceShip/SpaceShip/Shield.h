#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Shield
{
public:
	Shield();
	~Shield();
	Sprite icon;

private:
	int health;
	Texture shieldTex;
};

