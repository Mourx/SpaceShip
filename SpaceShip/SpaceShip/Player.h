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
	vector<Vector2f> gunPos;
	vector<Vector2f> handPos;

private:
	Ship* ship;
	Sprite icon;
	Texture playerTex;
	vector<Charge*> chargeDeck;
	vector<Charge*> deck;
	vector<Charge*> hand;
	vector<Charge*> discard;
	int handSize = 4;


};

