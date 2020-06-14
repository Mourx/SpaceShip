#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <vector>
#include "enums.h"
#include "Button.h"
using namespace sf;
using namespace std;
class Button;
class TitleScreen
{
public:
	TitleScreen(RenderWindow* w, Player* p);
	~TitleScreen();

	void Draw();
	void MouseDown(Vector2f m);
	void MouseUp(Vector2f m);
	void MoveMouse(Vector2f m);
	MENU_STATE getState();
	void startGame();
private:
	Player* player;
	RenderWindow* window;
	Sprite space;
	Texture spaceTex;
	Button* startButton;
	MENU_STATE state = WAITING;

};

