#include "StageType.h"


StageType::StageType(STAGE_TYPE t) {
	type = t;
	switch (type) {
	case COMBAT:
		//generate Encounter
		tex.loadFromFile("Textures/stageSelect/combatEncounter.png");
		break;
	case SHOP:
		//generate shop contents
		tex.loadFromFile("Textures/stageSelect/shop.png");
		break;
	case TREASURE:
		//generate treasure type
		tex.loadFromFile("Textures/stageSelect/treasure.png");
		break;
	case BOSS:
		tex.loadFromFile("Textures/stageSelect/boss.png");
		break;

	}
	icon.setTexture(tex);

}

StageType::~StageType() {

}

STAGE_TYPE StageType::GetType() {
	return type;
}
