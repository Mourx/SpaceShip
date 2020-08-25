#include "Charge.h"

EasyBomb::EasyBomb() : Charge() {
	chargeTex.loadFromFile("Textures/charges/easyBomb.png");
	icon.setTexture(chargeTex);
	icon.setScale(1, 1);
	type = DAMAGE;
	chargeEffTex.loadFromFile("Textures/charges/bombEffect.png");
	chargeEffect.setTexture(chargeEffTex);
	chargeEffect.setScale(3, 3);
	damage = 25;
	cost = 2;
	effectTime = 500000;
	effectShade.loadFromFile("Textures/shaders/effectShade.vert", Shader::Vertex);
	string s = "Deals damage in an area\naround the first enemy in\nthe row.\nDeals " + to_string((int)damage) + " damage.";
	description.setString(s);
}
EasyBomb::~EasyBomb() {

}

void EasyBomb::Fire(Gun* g, vector<vector<Tile*>> grid, vector<Gun*> guns) {
	bool bExploded = false;
	int location = 0;
	int row = g->row;
	for (Tile* t : grid[row]) {
		if (bExploded == false) {
			if (t->bHasUnit) {
				bExploded = true;
				chargeEffect.setPosition(t->getUnit()->icon.getPosition().x - 50, t->getUnit()->icon.getPosition().y - 50);
			}
			else {
				location++;
			}
		}
	}
	if (bExploded) {
		//row above exploded;
		if (row > 0) {
			if (location > 0) {
				if (grid[row - 1][location - 1]->bHasUnit) {
					grid[row - 1][location - 1]->getUnit()->Damage(totalDamage);
				}
			}
			if (grid[row - 1][location]->bHasUnit) {
				grid[row - 1][location]->getUnit()->Damage(totalDamage);
			}
			if (location < 4) {
				if (grid[row - 1][location + 1]->bHasUnit) {
					grid[row - 1][location + 1]->getUnit()->Damage(totalDamage);
				}
			}
		}
		//row where exploded
		if (location > 0) {
			if (grid[row][location - 1]->bHasUnit) {
				grid[row][location - 1]->getUnit()->Damage(totalDamage);
			}
		}
		if (grid[row][location]->bHasUnit) {
			grid[row][location]->getUnit()->Damage(totalDamage);
		}
		if (location < 4) {
			if (grid[row][location + 1]->bHasUnit) {
				grid[row][location + 1]->getUnit()->Damage(totalDamage);
			}
		}
		//row below exploded
		if (row < 4) {
			if (location > 0) {
				if (grid[row + 1][location - 1]->bHasUnit) {
					grid[row + 1][location - 1]->getUnit()->Damage(totalDamage);
				}
			}
			if (grid[row + 1][location]->bHasUnit) {
				grid[row + 1][location]->getUnit()->Damage(totalDamage);
			}
			if (location < 4) {
				if (grid[row + 1][location + 1]->bHasUnit) {
					grid[row + 1][location + 1]->getUnit()->Damage(totalDamage);
				}
			}
		}
		
		timer = 0;
		bEffectVisible = true;
	}
}

void EasyBomb::Update(Time t, vector<Artefact*> arts) {
	Charge::Update(t, arts);
	string s = "Deals damage in an area\naround the first enemy in\nthe row.\nDeals " + to_string((int)totalDamage) + " damage.";
	description.setString(s);
}