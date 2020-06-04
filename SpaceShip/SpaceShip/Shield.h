#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Shield
{
public:
	Shield();
	~Shield();
	void SetPosition(Vector2f vec);
	void Draw(RenderWindow* w);
	void Boost(int boost);
	int Damage(int dmg);
	Sprite icon;
	Text healthText;
	Sprite healthIcon;
	bool bIsActive = false;
private:
	int health = 0;
	Font font;
	Texture shieldTex;
	Texture healthTex;
};

