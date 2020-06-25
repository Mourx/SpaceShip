#include "Charge.h"

EasyBomb::EasyBomb() {
	chargeTex.loadFromFile("Textures/charges/easyBomb.png");
	icon.setTexture(chargeTex);
	icon.setScale(1, 1);

	chargeEffTex.loadFromFile("Textures/charges/bombEffect.png");
	chargeEffect.setTexture(chargeEffTex);
	chargeEffect.setScale(3, 3);
	damage = 10;
	cost = 2;
	effectTime = 500000;
	effectShade.loadFromFile("Textures/shaders/effectShade.vert", Shader::Vertex);
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
					grid[row - 1][location - 1]->getUnit()->Damage(damage);
				}
			}
			if (grid[row - 1][location]->bHasUnit) {
				grid[row - 1][location]->getUnit()->Damage(damage);
			}
			if (location < 4) {
				if (grid[row - 1][location + 1]->bHasUnit) {
					grid[row - 1][location + 1]->getUnit()->Damage(damage);
				}
			}
		}
		//row where exploded
		if (location > 0) {
			if (grid[row][location - 1]->bHasUnit) {
				grid[row][location - 1]->getUnit()->Damage(damage);
			}
		}
		if (grid[row][location]->bHasUnit) {
			grid[row][location]->getUnit()->Damage(damage);
		}
		if (location < 4) {
			if (grid[row][location + 1]->bHasUnit) {
				grid[row][location + 1]->getUnit()->Damage(damage);
			}
		}
		//row below exploded
		if (row < 4) {
			if (location > 0) {
				if (grid[row + 1][location - 1]->bHasUnit) {
					grid[row + 1][location - 1]->getUnit()->Damage(damage);
				}
			}
			if (grid[row + 1][location]->bHasUnit) {
				grid[row + 1][location]->getUnit()->Damage(damage);
			}
			if (location < 4) {
				if (grid[row + 1][location + 1]->bHasUnit) {
					grid[row + 1][location + 1]->getUnit()->Damage(damage);
				}
			}
		}
		
		timer = 0;
		bEffectVisible = true;
	}
}