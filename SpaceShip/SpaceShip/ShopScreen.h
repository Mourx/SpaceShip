#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Shoption.h"
using namespace std;
using namespace sf;

class ShopScreen
{
public:
	ShopScreen(RenderWindow* w, Player* p);
	~ShopScreen();
	void Draw();
private:
	Sprite space;
	Texture spaceTex;
	Player* player;
	RenderWindow* window;
	int ChargeChoices = 5;
	vector<Shoption*> chargesSold;
};

