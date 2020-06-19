#include "StagePath.h"

StagePath::StagePath() {

}


StagePath::~StagePath() {

}


void StagePath::GeneratePath() {

	bool bStart = true;
	bool bEnd = false;
	for (int tier = 0; tier < tiers; i++) {
		if (tier = tiers - 1) bEnd = true;
		StageType* s = new StageType(COMBAT, true, false);
		if (tier = 0) bStart = false;
		stages[tier].push_back(s);
		startStage = s;
		for (int i = 0; i < s->getPaths(); i++) {

		}
	}
}