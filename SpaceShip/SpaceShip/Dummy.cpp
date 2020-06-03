#include "Enemy.h"


Dummy::Dummy() {
	name = "Dummy";
	health = 10;
	ship = new Ship();
	iconTex.loadFromFile("enemyA.png");
	icon.setTexture(iconTex);
}

Dummy::~Dummy(){

}
