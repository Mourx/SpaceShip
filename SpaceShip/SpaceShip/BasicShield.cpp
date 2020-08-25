#include "Charge.h"


BasicShield::BasicShield() : Charge() {
	chargeTex.loadFromFile("Textures/charges/basicShield.png");
	icon.setTexture(chargeTex);
	icon.setScale(1, 1);
	type = SHIELD;
	damage = 10;
	cost = 1;
	chargeEffTex.loadFromFile("Textures/charges/chargeEffect.png");
	chargeEffect.setTexture(chargeEffTex);
	string s = "Provides a single gun \nwith a shield boost. \nProvides a boost of " + to_string((int)damage) + ".";
	description.setString(s);
}

BasicShield::~BasicShield() {

}

void BasicShield::Fire(Gun* g, vector<vector<Tile*>> grid, vector<Gun*> guns) {
	g->shield->Boost((int)damage);
}

void BasicShield::Update(Time t, vector<Artefact*> arts) {
	Charge::Update(t, arts);
	string s = "Provides a single gun \nwith a shield boost. \nProvides a boost of " + to_string((int)totalDamage) + ".";
	description.setString(s);
}