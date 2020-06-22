#include "StagePath.h"

StagePath::StagePath(RenderWindow* window) {
	w = window;
	GeneratePath();
}


StagePath::~StagePath() {

}


void StagePath::GeneratePath() {
	for (int i = 0; i < tiers; i++) {
		if (i == 0 || i == tiers-1) {
			stageAmounts.push_back(1);
		}
		else {
			stageAmounts.push_back((rand() % 2) + 2);
		}
		
	}
	for (int tier = 0; tier < tiers; tier++) {
		vector<StageType*> st;
		StageType* s;
		if (tier == 0) {
			s = new StageType(COMBAT);
			s->icon.setPosition(60, 310);
			st.push_back(s);
		}else if (tier == tiers - 1) {
			s = new StageType(BOSS);
			s->icon.setPosition(60 + (tiers-1) * 90, 310);
			st.push_back(s);
		}
		else {
			for (int n = 0; n < stageAmounts[tier]; n++) {
				STAGE_TYPE t = (STAGE_TYPE)(rand() % 3);
				s = new StageType(t);
				if (stageAmounts[tier] == 2) {
					s->icon.setPosition(60 + tier * 90, 260 + n * 100);
				}
				else {
					s->icon.setPosition(60 + tier * 90, 300 + n * 100 - 30 * stageAmounts[tier]);
				}
				st.push_back(s);
			}
		}
		stages.push_back(st);
	}
}

void StagePath::Draw() {
	for (vector<StageType*> v : stages) {
		for (StageType* s : v) {
			w->draw(s->icon);
		}
	}
}