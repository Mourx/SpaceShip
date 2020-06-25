#pragma once
#include "Enemy.h"
#include "enums.h"

class EnemyFactory
{
	typedef Enemy* (*CreateEnemy)();
public:
	static Enemy* GenerateEnemy(ENEMY_RARITY rarity) {
		CreateEnemy createCommon[] =
		{
			Dummy::Create

		};
		const int countCom = sizeof(createCommon) / sizeof(*createCommon);

		CreateEnemy createUncommon[] =
		{
			Dummy::Create

		};
		const int countUnc = sizeof(createUncommon) / sizeof(*createUncommon);

		CreateEnemy createRare[] =
		{
			Dummy::Create

		};
		const int countRare = sizeof(createRare) / sizeof(*createRare);

		switch (rarity)
		{
		case COMMONE:

			return createCommon[rand() % countCom]();
			break;
		case UNCOMMONE:
			return  createUncommon[rand() % countUnc]();
			break;
		case RAREE:
			return createRare[rand() % countRare]();
			break;
		default:
			return NULL;
			break;
		}

	}
};

