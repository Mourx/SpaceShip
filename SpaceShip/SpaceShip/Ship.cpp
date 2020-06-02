#include "Ship.h"


Ship::Ship(int gunCap) {
	gunCapacity = gunCap;

}

Ship::Ship() {
	gunCapacity = 1;
	guns.push_back(new Gun(new BasicCharge()));
}

Ship::~Ship() {

}

void Ship::GiveGun(Gun* g) {
	guns.push_back(g);
}
