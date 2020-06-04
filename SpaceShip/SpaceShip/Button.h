#pragma once
#include <SFML/Graphics.hpp>
#include "Combat.h"
using namespace sf;
class Combat;
class Button
{
public:
	Button();
	virtual ~Button();
	virtual void OnClick(Combat* combat) {};
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