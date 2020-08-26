#include "Enemy.h"

OrbBot::OrbBot() {
	chargeTex.loadFromFile("Textures/charges/chargeEffect.png");
	attackEffect.setTexture(chargeTex);
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
	effectShade.loadFromFile("Textures/shaders/effectShade.vert", Shader::Vertex);
}

OrbBot::~OrbBot() {

}

void OrbBot::Attack(Gun* g, Player* p, int c) {
	bAttackDelayed = true;
	delayTime = 0 + c * 5000;
	int remainder = g->shield->Damage(damage);
	p->Damage(remainder);
}