#include "Button.h"

StartGameButton::StartGameButton() {
	buttTex.loadFromFile("Textures/titleScreen/startGame.png");
	distortion.loadFromFile("Textures/shaders/distortion.png");
	distortion.setRepeated(true);
	distortion.setSmooth(true);
	icon.setTexture(buttTex);
	icon.setPosition(300, 100);
	shader.loadFromFile("Textures/shaders/wavy.vert", Shader::Vertex);
	distortionShader.loadFromFile("Textures/shaders/distort.frag", Shader::Fragment);
	distortionShader.setUniform("currentTexture", buttTex);
	distortionShader.setUniform("distortionMapTexture", distortion);
	distortionShader.setUniform("distortionFactor", .05f);
	distortionShader.setUniform("riseFactor", .2f);
	
}


StartGameButton::~StartGameButton() {

}

void StartGameButton::OnClick(TitleScreen* screen) {
	screen->startGame();
}