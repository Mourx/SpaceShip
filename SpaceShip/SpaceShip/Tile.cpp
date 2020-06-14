#include "Tile.h"


Tile::Tile(float x, float y) {
	posX = x;
	posY = y;
	tileTex.loadFromFile("Textures/combat/tile.png");
	icon.setTexture(tileTex);
	icon.setPosition(posX, posY);
}

Tile::~Tile() {

}


void Tile::setUnit(Enemy* u) {
	if (u != NULL) {
		unit = u;
		unit->setPosition(posX, posY);
		bHasUnit = true;
	}
	else {
		unit = NULL;
		bHasUnit = false;
	}
}

Enemy* Tile::getUnit() {
	return unit;
}