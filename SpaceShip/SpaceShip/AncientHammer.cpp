#include "Artefact.h"

AncientHammer::AncientHammer() {
	iconTex.loadFromFile("Textures/Artefacts/ancientHammer.png");
	icon.setTexture(iconTex);
	modifier = DAMAGE_RAW;
	value = 2;
}


AncientHammer::~AncientHammer() {

}