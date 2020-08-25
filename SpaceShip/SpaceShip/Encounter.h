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
protected:
	vector<Enemy*> enemies;
	EnemyFactory factory;
};

class BossEncounter : public Encounter
{
public:
	BossEncounter();
	~BossEncounter();
};