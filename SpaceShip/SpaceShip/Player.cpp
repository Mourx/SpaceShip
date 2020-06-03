#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	playerTex.loadFromFile("playerA.png");
	icon.setTexture(playerTex);
	icon.setPosition(-10, 60);
	icon.setScale(7, 9);
	ship = new Ship();
	initGuns();
	chargeDeck.push_back(new BasicCharge());
	chargeDeck.push_back(new BasicCharge());
	chargeDeck.push_back(new BasicCharge());
	chargeDeck.push_back(new BasicCharge());
	loadDeck();
}

Player::~Player() {

}

void Player::initGuns() {
	Gun* g = new Gun();
	g->icon.setPosition(gunAX, gunAY);
	g->row = 0;
	guns.push_back(g);
	ship->GiveGun(g);

	g = new Gun();
	g->icon.setPosition(gunBX, gunBY);
	g->row = 1;
	guns.push_back(g);
	ship->GiveGun(g);

	g = new Gun();
	g->icon.setPosition(gunCX, gunCY);
	g->row = 2;
	guns.push_back(g);
	ship->GiveGun(g);

	g = new Gun();
	g->icon.setPosition(gunDX, gunDY);
	g->row = 3;
	guns.push_back(g);
	ship->GiveGun(g);

	g = new Gun();
	g->icon.setPosition(gunEX, gunEY);
	g->row = 4;
	guns.push_back(g);
	ship->GiveGun(g);
}

void Player::loadDeck() {
	deck = chargeDeck;
	while (deck.size() > 0) {
		Charge* c = deck[0];
		c->icon.setPosition(150 + hand.size()* 60,680);
		hand.push_back(c);
		deck.erase(deck.begin());
	}
}

void Player::Draw(RenderWindow* w) {
	w->draw(icon);
	for (Charge* c : hand) {
		c->Draw(w);
	}
}

vector<Charge*> Player::getHand() {

	return hand;
}

void Player::Update(Time t) {
	for (Charge* c : hand) {
		c->Update(t);
	}
}

void Player::UseCharge(Charge* c) {

}