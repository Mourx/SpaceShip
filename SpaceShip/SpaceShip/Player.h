#pragma once
#include <SFML/Graphics.hpp>
#include "Gun.h"
#include "Ship.h"
#include "Charge.h"
#include "Artefact.h"
#include <vector>
using namespace sf;
using namespace std;

class Ship;
class Player
{
public:
	Player();
	~Player();
	
	vector<Gun*> guns;
	void initGuns();
	void loadDeck();
	void DrawBackground(RenderWindow* w);
	void DrawDetails(RenderWindow* w);
	void discardHand();
	vector<Charge*> getHand();
	Charge* selectedCharge = NULL;
	Gun* selectedGun = NULL;
	void Update(Time t);
	void UseCharge(Charge* c);
	vector<Vector2f> gunPos;
	vector<Vector2f> handPos;
	void drawHand();
	void Damage(int dmg);
	void AddCharge(Charge* c); 
	void AddArtefact(Artefact* a);
	bool CheckAnimations();
	Sprite healthIcon;
	Text healthText;
	bool bIsDead = false;
	int getDeckSize();
	int getDiscardSize();
	int energyPerTurn = 3;
	int currentEnergy = 0;
	int getLevel() { return this->level; }
	void levelUp();
	void addMoney(int m) { money += m; };
	int getMoney() { return money; }
	vector<Artefact*> getArtefacts() { return artefacts; }
private:
	Ship* ship;
	Sprite icon;
	Texture playerTex;
	Texture healthTex;
	Text goldText;
	Font font;
	vector<Charge*> chargeDeck;
	vector<Charge*> deck;
	vector<Charge*> hand;
	vector<Charge*> discard;
	vector<Artefact*> artefacts;
	int handSize = 4;
	int health = 0;
	int level = 0;
	int money;



};

