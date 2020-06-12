#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <vector>
using namespace sf;
using namespace std;
class TitleScreen
{
public:
	TitleScreen(RenderWindow* w, Player* p);
	~TitleScreen();

	void Draw();
	void MouseDown(Vector2f m);
	void MouseUp(Vector2f m);
	void MoveMouse(Vector2f m);

private:
	Player* player;
	RenderWindow* window;
	Sprite space;
	Texture spaceTex;
};

