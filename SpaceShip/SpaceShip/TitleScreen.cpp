#include "TitleScreen.h"


TitleScreen::TitleScreen(RenderWindow* w, Player* p) {
	window = w;
	player = p;
	startButton = new StartGameButton();
	spaceTex.loadFromFile("Textures/general/space.png");
	space.setTexture(spaceTex);
	space.setPosition(0, 0);
}
TitleScreen::~TitleScreen() {

}

void TitleScreen::Draw() {
	window->draw(space);
	startButton->Draw(window);
}
void TitleScreen::MouseDown(Vector2f m) {
	if (startButton->icon.getGlobalBounds().contains(m)) {
		startButton->OnClick(this);
	}
}
void TitleScreen::MouseUp(Vector2f m) {

}
void TitleScreen::MoveMouse(Vector2f m) {

}

MENU_STATE TitleScreen::getState() {
	return state;
}

void TitleScreen::startGame() {
	state = START;
}