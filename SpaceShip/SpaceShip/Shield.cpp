#include "Shield.h"


Shield::Shield() {
	shieldTex.loadFromFile("shield.png");
	icon.setTexture(shieldTex);
	icon.setScale(1.5, 1.5);
}

Shield::~Shield() {

}