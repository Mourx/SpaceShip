#include "Enemy.h"


Dummy::Dummy() : Enemy(){
	
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

}

Dummy::~Dummy(){

}

void Dummy::Attack(Gun* g, Player* p) {
	int remainder = g->shield->Damage(damage);
	p->Damage(remainder);
}