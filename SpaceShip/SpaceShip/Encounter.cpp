#include "Encounter.h"


Encounter::Encounter() {
	int r = 1 + rand() % 3;
	for (int i = 0; i < r; i++) {
		enemies.push_back(factory.GenerateEnemy(COMMONE));
	}
}

Encounter::~Encounter() {

}

vector<Enemy*> Encounter::GetEnemies() {
	return enemies;
}