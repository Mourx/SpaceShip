#pragma once
#include "Player.h"
#include "Tile.h"
#include <vector>
#include "Charge.h"
#include "Button.h"
#include "enums.h"
using namespace std;
class Charge;
class Button;
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
	Sprite space;
	Texture spaceTex;
	Sprite backGUI;
	Texture backTex;
	COMBAT_STEP phase = PLAYER_TURN;
	vector<Enemy*> deadEnemies;
	int totalEnemies;
	bool bCombatOver = false;
	GAME_RESULT result = ACTIVE;
};

