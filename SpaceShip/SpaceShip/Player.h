#pragma once
#include "Ship.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Player
{
public:
	Player();
	~Player();
	
	vector<Gun*> guns;
	void initGuns();
	void loadDeck();
	void Draw(RenderWindow* w);
	vector<Charge*> getHand();
	Charge* selectedCharge = NULL;
	Gun* selectedGun = NULL;
	void Update(Time t);
	void UseCharge(Charge* c);
private:
	Ship* ship;
	Sprite icon;
	Texture playerTex;
	vector<Charge*> chargeDeck;
	vector<Charge*> deck;
	vector<Charge*> hand;
	vector<Charge*> discard;
	float gunAX = 295;
	float gunAY = 95;
	float gunBX = 295;
	float gunBY = 176;
	float gunCX = 295;
	float gunCY = 257;
	float gunDX = 295;
	float gunDY = 338;
	float gunEX = 295;
	float gunEY = 419;

};

