#include "Artefact.h"


Artefact::Artefact() {

}


Artefact::~Artefact() {

}

void Artefact::DrawOver(RenderWindow* w) {
	w->draw(icon);
}

void Artefact::setPosition(Vector2f v) {
	icon.setPosition(v);
}