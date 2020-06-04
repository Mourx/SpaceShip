#pragma once
#include <SFML/Graphics.hpp>
#include "values.h"
#include "Combat.h"

int main() {
	GAME_SCREEN gameScreen = COMBAT;
	GAME_RESULT result;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	Player* player = new Player();
	Combat* combat = new Combat(&window,player);
	sf::Clock clock;
	while (window.isOpen()) {
		sf::Time elapsed = clock.restart();
		combat->Update(elapsed);
		sf::Event event;
		
		window.clear(sf::Color::Blue);
		if (gameScreen == MAIN_MENU) {
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) window.close();
			}
		}
		if (gameScreen == REWARD_SCREEN) {
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) window.close();
			}
		}
		if (gameScreen == LOSS_SCREEN) {
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) window.close();
			}
		}
		if (gameScreen == COMBAT) {
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) window.close();
				if (event.type == sf::Event::MouseButtonPressed) {
					Vector2f m = window.mapPixelToCoords(sf::Mouse::getPosition(window));
					combat->MouseDown(m);
				}
				if (event.type == sf::Event::MouseMoved) {
					Vector2f m = window.mapPixelToCoords(sf::Mouse::getPosition(window));
					combat->MoveMouse(m);
				}
				if (event.type == sf::Event::MouseButtonReleased) {
					Vector2f m = window.mapPixelToCoords(sf::Mouse::getPosition(window));
					combat->MouseUp(m);
				}
			}
			
			// add images here
			combat->Draw();
			result = combat->CheckGameOver();
			switch (result) {
			case ACTIVE:
				break;
			case WIN:
				gameScreen = REWARD_SCREEN;
				//make new reward
				break;
			case LOSS:
				gameScreen = LOSS_SCREEN;
				break;
			}
		}
		window.display();
	}

	return 0;
}