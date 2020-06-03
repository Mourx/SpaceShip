#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	playerTex.loadFromFile("playerA.png");
	icon.setTexture(playerTex);
	icon.setPosition(-10, 60);
	icon.setScale(7, 9);
	ship = new Ship();

	gunPos.push_back(Vector2f(295, 95));
	gunPos.push_back(Vector2f(295, 176));
	gunPos.push_back(Vector2f(295, 257));
	gunPos.push_back(Vector2f(295, 338));
	gunPos.push_back(Vector2f(295, 419));



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
	g->icon.setPosition(gunPos[0]);
	g->row = 0;
	guns.push_back(g);
	ship->GiveGun(g);

	g = new Gun();
	g->icon.setPosition(gunPos[1]);
	g->row = 1;
	guns.push_back(g);
	ship->GiveGun(g);

	g = new Gun();
	g->icon.setPosition(gunPos[2]);
	g->row = 2;
	guns.push_back(g);
	ship->GiveGun(g);

	g = new Gun();
	g->icon.setPosition(gunPos[3]);
	g->row = 3;
	guns.push_back(g);
	ship->GiveGun(g);

	g = new Gun();
	g->icon.setPosition(gunPos[4]);
	g->row = 4;
	guns.push_back(g);
	ship->GiveGun(g);
}

void Player::loadDeck() {
	deck = chargeDeck;
	int cardCount = 0;
	while (cardCount < handSize) {
		if (deck.size() == 0) {
			deck = discard;
			discard.clear();
			std::random_shuffle(deck.begin(), deck.end());
		}
		Charge* c = deck[0];
		handPos.push_back(Vector2f(150+cardCount*60, 680));
		c->icon.setPosition(handPos[cardCount]);
		c->handPos = hand.size();
		hand.push_back(c);
		deck.erase(deck.begin());
		cardCount++;
	}
}

void Player::Draw(RenderWindow* w) {
	w->draw(icon);
	for (Charge* c : hand) {
		c->Draw(w);
	}
	for (Charge* c : discard) {
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
	for (Charge* c : discard) {
		c->Update(t);
	}
}

void Player::UseCharge(Charge* c) {
	discard.push_back(c);
	hand.erase(std::remove(hand.begin(), hand.end(), c),hand.end());
	discard[discard.size()-1]->icon.setPosition(-150, -150);
}