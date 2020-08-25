#include "Charge.h"

WideShield::WideShield() : Charge() {
	chargeTex.loadFromFile("Textures/charges/wideShield.png");
	icon.setTexture(chargeTex);
	icon.setScale(1, 1);
	type = SHIELD;
	damage = 7;
	cost = 2;
	effectTime = 500000;
	string s = "Provides the targeted and\nadjacent guns with shields.\nProvides a boost of " + to_string((int)damage) + ".";
	description.setString(s);
	
}

WideShield::~WideShield() {

}

void WideShield::Fire(Gun* g, vector<vector<Tile*>> grid, vector<Gun*> guns) {
	int row = g->row;
	//shield above
	if (row > 0) {
		guns[row - 1]->shield->Boost((int)damage);
	}
	//targetted gun
	g->shield->Boost((int)damage);
	//shield below
	if (row < 4) {
		guns[row + 1]->shield->Boost((int)damage);
	}
}

void WideShield::Update(Time t, vector<Artefact*> arts) {
	Charge::Update(t, arts);
	string s = "Provides the targeted and\nadjacent guns with shields.\nProvides a boost of " + to_string((int)totalDamage) + ".";
	description.setString(s);
}