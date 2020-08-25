#include "Charge.h"

BasicCharge::BasicCharge() : Charge() {
	chargeTex.loadFromFile("Textures/charges/basicCharge.png");
	icon.setTexture(chargeTex);
	icon.setScale(1, 1);
	type = DAMAGE;
	chargeEffTex.loadFromFile("Textures/charges/chargeEffect.png");
	chargeEffect.setTexture(chargeEffTex);

	damage = 10;
	cost = 1;
	effectTime = 500000;
	effectShade.loadFromFile("Textures/shaders/effectShade.vert",Shader::Vertex);
	string s = "Fires a charge across \nasingle row. \nDeals " + to_string((int)damage) + " damage to \nunits in that row.";
	description.setString(s);
}
BasicCharge::~BasicCharge() {

}
void BasicCharge::Fire(Gun* g, vector<vector<Tile*>> grid, vector<Gun*> guns) {
	//take row
	//fire at front enemy
	cout << "derived" << endl;
	timer = 0;
	bEffectVisible = true;
	chargeEffect.setPosition(g->icon.getPosition().x + 50, g->icon.getPosition().y);
	for (Tile* t : grid[g->row]) {
		if (t->bHasUnit) {
			Enemy* e = t->getUnit();
			std::string s = e->getName();
			cout << "Name: " << s << ", Health: " << e->getHealth() << endl;
			e->Damage((int)totalDamage);
			//deal damage
		}
	}
}

void BasicCharge::Update(Time t, vector<Artefact*> arts) {
	Charge::Update(t, arts);
	string s = "Fires a charge across \nasingle row. \nDeals " + to_string((int)totalDamage) + " damage to \nunits in that row.";
	description.setString(s);
}