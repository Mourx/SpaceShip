#pragma once
#include "Tile.h"
#include "Player.h"
#include "Button.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "enums.h"
using namespace std;
using namespace sf;
class Charge;
class Button;
class Player;
class Gun;
class Combat
{
public:
	Combat(RenderWindow* w,Player* p);
	~Combat();
	void Draw();
	void MouseDown(Vector2f m);
	void MouseUp(Vector2f m);
	void MoveMouse(Vector2f m);
	void Update(Time t);
	void AdvanceTurn();
	void DoAITurn();
	void CheckDeaths();
	void UpdateStrings();
	GAME_RESULT CheckGameOver();
private:
	Button* endTurn;
	Player* player;
	float offsetX;
	float offsetY;
	Vector2f snapPos;
	Gun* highlitGun = NULL;
	RenderWindow* window;
	float gridX = 400;
	float gridY = 100;
	vector<vector<Tile*>> combatGrid;
	Font font;
	Sprite space;
	Texture spaceTex;
	Sprite backGUI;
	Texture backTex;
	Sprite deck;
	Sprite discard;
	Texture deckTex;
	Texture discardTex;
	Text deckSize;
	Text discardSize;
	Sprite energy;
	Texture energyTex;
	Text energyText;
	COMBAT_STEP phase = PLAYER_TURN;
	vector<Enemy*> deadEnemies;
	int totalEnemies;
	bool bCombatOver = false;
	GAME_RESULT result = ACTIVE;

};

