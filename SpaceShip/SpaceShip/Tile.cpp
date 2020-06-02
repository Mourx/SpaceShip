#include "Tile.h"


Tile::Tile(float x, float y) {
	posX = x;
	posY = y;
	tileTex.loadFromFile("tile.png");
	icon.setTexture(tileTex);
	icon.setPosition(posX, posY);
}

Tile::~Tile() {

}


void Tile::setUnit(Enemy* u) {
	unit = u;
	unit->setPosition(posX, posY);
	bHasUnit = true;
}

Enemy* Tile::getUnit() {
	return unit;
}