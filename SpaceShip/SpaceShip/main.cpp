#pragma once
#include <SFML/Graphics.hpp>
#include "values.h"
#include "Combat.h"
#include "RewardScreen.h"
#include "TitleScreen.h"

int main() {
	srand(std::time(nullptr));
	GAME_SCREEN gameScreen = MAIN_MENU;
	GAME_RESULT result;
	REWARD_STATE picking;
	
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	Player* player = new Player();
	TitleScreen* mainMenu = new TitleScreen(&window,player);
	Combat* combat = new Combat(&window,player);
	RewardScreen* reward = new RewardScreen(&window,player,false);
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
			mainMenu->Draw();
		}
		if (gameScreen == REWARD_SCREEN) {
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) window.close();
				if (event.type == sf::Event::MouseButtonPressed) {
					Vector2f m = window.mapPixelToCoords(sf::Mouse::getPosition(window));
					reward->MouseDown(m);
				}
				if (event.type == sf::Event::MouseButtonReleased) {
					Vector2f m = window.mapPixelToCoords(sf::Mouse::getPosition(window));
					reward->MouseUp(m);
				}
				if (event.type == sf::Event::MouseMoved) {
					Vector2f m = window.mapPixelToCoords(sf::Mouse::getPosition(window));
					reward->MoveMouse(m);
				}
			}
			reward->Draw();
			picking = reward->CheckState();
			switch (picking) {
			case PICKING:
				break;
			case PICKED:
				gameScreen = COMBAT;
				picking = PICKING;
				combat = new Combat(&window, player);
				//make new reward
				break;
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
				result = ACTIVE;
				reward = new RewardScreen(&window,player, false);
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