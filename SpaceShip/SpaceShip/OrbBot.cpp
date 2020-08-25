#include "Enemy.h"

OrbBot::OrbBot() {
	name = "OrbBot";
	health = 30;
	damage = 2;
	ship = new Ship();
	iconTex.loadFromFile("Textures/combat/orbBotA.png");
	icon.setTexture(iconTex);
	font.loadFromFile("arial.ttf");
	String attack = std::to_string(damage);
	attackText.setString(attack);
	String hp = std::to_string(health);
	healthText.setString(hp);
}

OrbBot::~OrbBot() {

}

void OrbBot::Attack(Gun* g, Player* p) {
	int remainder = g->shield->Damage(damage);
	p->Damage(remainder);
}