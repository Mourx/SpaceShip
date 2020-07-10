#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Shoption.h"
#include "Button.h"
using namespace std;
using namespace sf;

class ExitShopButton;
class ShopScreen
{
public:
	ShopScreen(RenderWindow* w, Player* p);
	~ShopScreen();
	void Draw();
	void ExitShop();
	void MouseDown(Vector2f m);
	void MouseUp(Vector2f m);
	void MoveMouse(Vector2f m);
	void Buy(ShoptionCharge* s);
	PICK_STATE GetPhase() { return phase; }
	void Update(Time t);
private:
	PICK_STATE phase = PICKING;
	Sprite space;
	Texture spaceTex;
	ExitShopButton* exit;
	Shoption* selectedShopt = NULL;
	Player* player;
	RenderWindow* window;
	int ChargeChoices = 5;
	vector<Shoption*> chargesSold;
	Vector2f mousePos;
};

