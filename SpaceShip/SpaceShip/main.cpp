#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "values.h"
#include "Combat.h"
#include "RewardScreen.h"
#include "TitleScreen.h"
#include "StagePath.h"

int main() {
	srand(std::time(nullptr));
	GAME_SCREEN gameScreen = MAIN_MENU;
	GAME_RESULT result;
	PICK_STATE picking;
	
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SpaceShip Adventures in SPACE! But NOT in time >:( ");
	window.setIcon(icon_ship.width,icon_ship.height,icon_ship.pixel_data);
	Player* player = new Player();
	TitleScreen* mainMenu = new TitleScreen(&window,player);
	Combat* combat = new Combat(&window, player, new Encounter());
	RewardScreen* reward = new RewardScreen(&window,player,false);
	StagePath* path = new StagePath(&window,player);
	sf::Clock clock;
	while (window.isOpen()) {
		sf::Time elapsed = clock.restart();
		combat->Update(elapsed);
		path->Update(elapsed);

		sf::Event event;
		
		window.clear(sf::Color::Blue);
		if (gameScreen == MAIN_MENU) {
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) window.close();
				if (event.type == sf::Event::MouseButtonPressed) {
					Vector2f m = window.mapPixelToCoords(sf::Mouse::getPosition(window));
					mainMenu->MouseDown(m);
				}
			}
			switch (mainMenu->getState()) {
			case WAITING:
				break;
			case START:
				combat = new Combat(&window, player, new Encounter());
				gameScreen = COMBAT_SCREEN;
				break;
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
				gameScreen = STAGE_SELECT;
				path->UpdatePathing();
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
		if (gameScreen == COMBAT_SCREEN) {
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
		if (gameScreen == STAGE_SELECT) {
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) window.close();
				if (event.type == sf::Event::MouseButtonPressed) {
					Vector2f m = window.mapPixelToCoords(sf::Mouse::getPosition(window));
					path->MouseDown(m);
				}
				if (event.type == sf::Event::MouseButtonReleased) {
					Vector2f m = window.mapPixelToCoords(sf::Mouse::getPosition(window));
					path->MouseUp(m);
				}
				if (event.type == sf::Event::MouseMoved) {
					Vector2f m = window.mapPixelToCoords(sf::Mouse::getPosition(window));
					path->MoveMouse(m);
				}
			}
			switch (path->getState()) {
			case PICKING:
				break;
			case PICKED:
				gameScreen = COMBAT_SCREEN;
				combat = new Combat(&window, player, new Encounter());
				break;
			}
			path->Draw();
		}
		window.display();
	}

	return 0;
}