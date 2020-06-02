#pragma once
#include <SFML/Graphics.hpp>
#include "values.h"
#include "Combat.h"

int main() {

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	Combat* combat = new Combat(&window);
	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::MouseButtonPressed) {
				Vector2f m = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				combat->CheckMouse(m);
			}
			if (event.type == sf::Event::MouseMoved) {

			}
			if (event.type == sf::Event::MouseButtonReleased) {

			}
		}
		window.clear(sf::Color::Blue);
		// add images here
		combat->Draw();
		window.display();
	}

	return 0;
}