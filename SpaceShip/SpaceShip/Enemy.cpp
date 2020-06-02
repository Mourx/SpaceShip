#include "Enemy.h"


Enemy::Enemy() {
	ship = new Ship();
	iconTex.loadFromFile("enemyA.png");
	icon.setTexture(iconTex);
}

Enemy::~Enemy() {

}

void Enemy::setPosition(float x, float y) {
	icon.setPosition(x, y);
}