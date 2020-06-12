#include "TitleScreen.h"


TitleScreen::TitleScreen(RenderWindow* w, Player* p) {
	window = w;
	player = p;

	spaceTex.loadFromFile("space.png");
	space.setTexture(spaceTex);
	space.setPosition(0, 0);
}
TitleScreen::~TitleScreen() {

}

void TitleScreen::Draw() {
	window->draw(space);
}
void TitleScreen::MouseDown(Vector2f m) {

}
void TitleScreen::MouseUp(Vector2f m) {

}
void TitleScreen::MoveMouse(Vector2f m) {

}
