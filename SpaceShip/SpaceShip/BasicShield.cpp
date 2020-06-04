#include "Charge.h"


BasicShield::BasicShield() {
	chargeTex.loadFromFile("basicShield.png");
	icon.setTexture(chargeTex);
	icon.setScale(1, 1);
	damage = 10;
	cost = 1;
	chargeEffTex.loadFromFile("chargeEffect.png");
	chargeEffect.setTexture(chargeEffTex);
}

BasicShield::~BasicShield() {

}

void BasicShield::Fire(Gun* g, vector<vector<Tile*>> grid, vector<Gun*> guns) {
	g->shield->Boost(damage);
}