#include "Encounter.h"


Encounter::Encounter() {
	ENEMY_RARITY e;
	
	int rarity = rand() % 100;
	if (rarity < 10) {
		e = RAREE;
	}
	else if (rarity < 25) {
		e = UNCOMMONE;
	}
	else {
		e = COMMONE;
	}
	int r = 1 + rand() % 3;
	for (int i = 0; i < r; i++) {
		enemies.push_back(factory.GenerateEnemy(e));
	}
}

Encounter::~Encounter() {

}

vector<Enemy*> Encounter::GetEnemies() {
	return enemies;
}