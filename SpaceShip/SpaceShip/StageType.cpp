#include "StageType.h"


StageType::StageType(STAGE_TYPE t,bool bStartNode,bool bEndNode) {
	type = t;
	switch (type) {
	case COMBAT:
		//generate Encounter

		break;
	case SHOP:
		//generate shop contents

		break;
	case TREASURE:
		//generate treasure type

		break;
	}
	if (bStartNode) {
		paths = 2;
	}
	else if (!bEndNode) {
		paths = rand() % 2 + 1;
	}
	else {
		paths = 0;
	}
}

StageType::~StageType() {

}

STAGE_TYPE StageType::GetType() {
	return type;
}

int StageType::getPaths() {
	return paths;
}