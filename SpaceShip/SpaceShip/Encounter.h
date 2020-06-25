#pragma once
#include "Enemy.h"
#include "EnemyFactory.h"
using namespace std;

class Encounter
{
public:
	Encounter();
	~Encounter();
	vector<Enemy*> GetEnemies();
private:
	vector<Enemy*> enemies;
	EnemyFactory factory;
};

