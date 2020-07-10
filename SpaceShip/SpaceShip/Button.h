#pragma once
#include <SFML/Graphics.hpp>
#include "Combat.h"
#include "TitleScreen.h"
#include "ShopScreen.h"
using namespace sf;
class Combat;
class TitleScreen;
class ShopScreen;
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
	Texture distortion;
	Shader shader;
	Shader distortionShader;
	Clock clock;
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

class ExitShopButton : public Button {
public:
	ExitShopButton();
	~ExitShopButton();
	void OnClick(ShopScreen* screen);
};