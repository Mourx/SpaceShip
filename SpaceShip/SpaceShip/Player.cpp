#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	playerTex.loadFromFile("Textures/combat/playerA.png");
	icon.setTexture(playerTex);
	icon.setPosition(-10, 60);
	icon.setScale(7, 9);
	ship = new Ship();
	health = 100;
	money = 200;
	gunPos.push_back(Vector2f(295, 95));
	gunPos.push_back(Vector2f(295, 176));
	gunPos.push_back(Vector2f(295, 257));
	gunPos.push_back(Vector2f(295, 338));
	gunPos.push_back(Vector2f(295, 419));

	font.loadFromFile("arial.ttf");
	healthTex.loadFromFile("Textures/combat/health.png");
	healthIcon.setTexture(healthTex);
	healthIcon.setPosition(150, 530);
	String hp = std::to_string(health);
	healthText.setString(hp);
	healthText.setFont(font);
	healthText.setPosition(100, 525);
	healthText.setCharacterSize(24);

	initGuns();
	chargeDeck.push_back(new BasicCharge());
	chargeDeck.push_back(new BasicCharge());
	chargeDeck.push_back(new EasyBomb());
	chargeDeck.push_back(new BasicShield());
	chargeDeck.push_back(new BasicShield());
	std::random_shuffle(deck.begin(), deck.end());

	goldText.setFont(font);
	goldText.setPosition(300, 20);
	goldText.setCharacterSize(12);
	
}

Player::~Player() {

}

void Player::initGuns() {
	Gun* g = new Gun();
	g->SetPosition(gunPos[0]);
	g->row = 0;
	guns.push_back(g);
	ship->GiveGun(g);

	g = new Gun();
	g->SetPosition(gunPos[1]);
	g->row = 1;
	guns.push_back(g);
	ship->GiveGun(g);

	g = new Gun();
	g->SetPosition(gunPos[2]);
	g->row = 2;
	guns.push_back(g);
	ship->GiveGun(g);

	g = new Gun();
	g->SetPosition(gunPos[3]);
	g->row = 3;
	guns.push_back(g);
	ship->GiveGun(g);

	g = new Gun();
	g->SetPosition(gunPos[4]);
	g->row = 4;
	guns.push_back(g);
	ship->GiveGun(g);
}

void Player::loadDeck() {
	for (Gun* g : guns) {
		g->shield->Reset();
	}
	discard.clear();
	deck.clear();
	hand.clear();
	deck = chargeDeck;
	std::random_shuffle(deck.begin(), deck.end());
	drawHand();
}

void Player::DrawBackground(RenderWindow* w) {
	w->draw(icon);
	
	w->draw(healthIcon);
	w->draw(healthText);
}

void Player::DrawDetails(RenderWindow* w) {
	for (Charge* c : hand) {
		c->DrawUnder(w);
	}
	for (Charge* c : discard) {
		c->DrawUnder(w);
	}
	w->draw(goldText);
	if (selectedCharge == NULL) {
		for (Charge* c : hand) {
			c->DrawOver(w);
		}
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
	goldText.setString(to_string(money));
}

void Player::UseCharge(Charge* c) {
	currentEnergy -= c->getCost();
	discard.push_back(c);
	hand.erase(std::remove(hand.begin(), hand.end(), c),hand.end());
	discard[discard.size()-1]->icon.setPosition(-150, -150);
	int count = 0;
	for (Charge* c : hand) {
		if (handPos.size() == count) {
			handPos.push_back(Vector2f(150 + count * 60, 680));
		}
		Vector2f pos = handPos[count];
		c->icon.setPosition(pos);
		c->restPos = pos;
		count++;
	}
	
}

void Player::drawHand() {
	int cardCount = hand.size();;
	while (cardCount < handSize) {
		if (deck.size() == 0) {
			deck = discard;
			discard.clear();
			std::random_shuffle(deck.begin(), deck.end());
		}
		Charge* c = deck[0];
		if (handPos.size() == cardCount) {
			handPos.push_back(Vector2f(150 + cardCount * 60, 680));
		}
		c->icon.setPosition(handPos[cardCount]);
		c->handPos = hand.size();
		c->restPos = handPos[cardCount];
		hand.push_back(c);
		deck.erase(deck.begin());
		cardCount++;
	}
	cout << "Hand Drawn" << endl;
}

void Player::Damage(int dmg) {
	health -= dmg;
	if (health <= 0) {
		health = 0;
		bIsDead = true;
	}
	String hp = std::to_string(health);
	healthText.setString(hp);
}

int Player::getDeckSize() {
	return deck.size();
}

int Player::getDiscardSize() {
	return discard.size();
}

void Player::AddCharge(Charge* c) {
	c->icon.setScale(1, 1);
	chargeDeck.push_back(c);
}

void Player::discardHand() {
	for (Charge* c : hand) {
		c->icon.setPosition(-150, -150);
		discard.push_back(c);
	}
	hand.clear();
}

bool Player::CheckAnimations() {
	bool bAnimations = false;
	for (Charge* c : chargeDeck) {
		if (c->CheckAnimation()) {
			bAnimations = true;
		}
	}
	return bAnimations;
}

void Player::levelUp() {
	level++;
}
