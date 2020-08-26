#include "Enemy.h"


Dummy::Dummy() : Enemy(){
	chargeTex.loadFromFile("Textures/charges/chargeEffect.png");
	attackEffect.setTexture(chargeTex);
	name = "Dummy";
	health = 10;
	damage = 10;
	ship = new Ship();
	iconTex.loadFromFile("Textures/combat/enemyA.png");
	icon.setTexture(iconTex);
	font.loadFromFile("arial.ttf");
	String attack = std::to_string(damage);
	attackText.setString(attack);
	String hp = std::to_string(health);
	healthText.setString(hp);
	effectShade.loadFromFile("Textures/shaders/effectShade.vert", Shader::Vertex);
	attackEffect.setPosition(this->icon.getPosition());
	attackEffect.setScale(-1, 1);
}

Dummy::~Dummy(){

}

void Dummy::Attack(Gun* g, Player* p, int c) {
	bAttackDelayed = true;
	delayTime = 0 + c * 90000;
	int remainder = g->shield->Damage(damage);
	p->Damage(remainder);
}