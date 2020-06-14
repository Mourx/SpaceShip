#include "Button.h"

StartGameButton::StartGameButton() {
	buttTex.loadFromFile("Textures/titleScreen/startGame.png");
	icon.setTexture(buttTex);
	icon.setPosition(300, 100);
}


StartGameButton::~StartGameButton() {

}

void StartGameButton::OnClick(TitleScreen* screen) {
	screen->startGame();
}