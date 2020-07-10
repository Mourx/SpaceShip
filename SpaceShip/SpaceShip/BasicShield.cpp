#include "Charge.h"


BasicShield::BasicShield() : Charge() {
	chargeTex.loadFromFile("Textures/charges/basicShield.png");
	icon.setTexture(chargeTex);
	icon.setScale(1, 1);
	damage = 10;
	cost = 1;
	chargeEffTex.loadFromFile("Textures/charges/chargeEffect.png");
	chargeEffect.setTexture(chargeEffTex);

	description.setString("Provides a single gun \n\twith a shield boost. \nProvides a boost of 10.");
}

BasicShield::~BasicShield() {

}

void BasicShield::Fire(Gun* g, vector<vector<Tile*>> grid, vector<Gun*> guns) {
	g->shield->Boost(damage);
}

