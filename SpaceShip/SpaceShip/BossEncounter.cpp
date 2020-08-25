#include "Encounter.h"

BossEncounter::BossEncounter() {
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
	int r = 5 + rand() % 3;
	for (int i = 0; i < r; i++) {
		enemies.push_back(factory.GenerateEnemy(e));
	}
}

BossEncounter::~BossEncounter() {

}