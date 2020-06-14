#pragma once
#include <SFML/Graphics.hpp>
#include "Combat.h"
#include "TitleScreen.h"
using namespace sf;
class Combat;
class TitleScreen;
class Button
{
public:
	Button();
	virtual ~Button();
	virtual void OnClick(Combat* combat) {};
	virtual void OnClick(TitleScreen* combat) {};
	virtual void Draw(RenderWindow* w);
	Sprite icon;

protected:
	Texture buttTex;
};

class EndTurnButton : public Button {
public:
	EndTurnButton();
	~EndTurnButton();
	void OnClick(Combat* combat);
};

class StartGameButton : public Button {
public:
	StartGameButton();
	~StartGameButton();
	void OnClick(TitleScreen* screen);
};