#include "Enemy.h"


Enemy::Enemy() {
	name = "Base Enemy Class";
	health = 0;
	ship = new Ship();
	iconTex.loadFromFile("enemyA.png");
	icon.setTexture(iconTex);
}

Enemy::~Enemy() {

}

void Enemy::setPosition(float x, float y) {
	icon.setPosition(x, y);
}

String Enemy::getName() {
	return name;
}

float Enemy::getHealth() {
	return health;
}