#include "Button.h"

Button::Button() {


}

Button::~Button() {

}

void OnClick() {

}

void Button::Draw(RenderWindow* w) {
	shader.setUniform("time", clock.getElapsedTime().asSeconds());
	distortionShader.setUniform("time", clock.getElapsedTime().asSeconds());
	w->draw(icon,&distortionShader);
}