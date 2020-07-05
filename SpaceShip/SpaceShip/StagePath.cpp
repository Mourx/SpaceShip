#include "StagePath.h"

StagePath::StagePath(RenderWindow* window, Player* p) {
	w = window;
	player = p;
	GeneratePath();
	spaceTex.loadFromFile("Textures/general/space.png");
	space.setTexture(spaceTex);
	space.setPosition(0, 0);
	if (completed.loadFromFile("Textures/shaders/completed.vert", Shader::Vertex)) {
		
		cout << "Shading!" << endl;
	}
	available.loadFromFile("Textures/shaders/available.vert", Shader::Vertex);
	unavailable.loadFromFile("Textures/shaders/unavailable.vert", Shader::Vertex);
	mouseOver.loadFromFile("Textures/shaders/mouseOver.vert", Shader::Vertex);

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
	w->draw(space);
	for (int i = 0; i < stages.size();i++) {
		for (StageType* s : stages[i]) {
			if (s == hoverStage) {
				w->draw(s->icon, &mouseOver);
			}
			else if (i < currentTier) {
				w->draw(s->icon, &completed);
			}
			else if (i == currentTier) {
				w->draw(s->icon,&available);
			}
			else {
				w->draw(s->icon,&unavailable);
			}
		}
	}
}


void StagePath::MouseDown(Vector2f m) {
	selectedStage = NULL;
	for (StageType* s : stages[currentTier]) {
		FloatRect bounds = s->icon.getGlobalBounds();
		if (bounds.contains(m)) {
			selectedStage = s;
		}
	}
}

void StagePath::MouseUp(Vector2f m) {
	if (selectedStage != NULL) {
		FloatRect bounds = selectedStage->icon.getGlobalBounds();
		if (bounds.contains(m)) {
			phase = PICKED;
			hoverStage = NULL;
		}
		else {
			selectedStage = NULL;
		}
	}
}

void StagePath::GenerateEncounter() {

}

void StagePath::MoveMouse(Vector2f m) {
	hoverStage = NULL;
	for (int i = 0; i < stages.size(); i++) {
		for (StageType* s : stages[i]) {
			FloatRect bounds = s->icon.getGlobalBounds();
			if (bounds.contains(m)) {
				hoverStage = s;
			}
		}
	}
}

void StagePath::Update(Time t) {
	available.setUniform("time", clock.getElapsedTime().asSeconds());
}

void StagePath::UpdatePathing() {
	selectedStage = NULL;
	currentTier = player->getLevel() % tiers;
	phase = PICKING;
}
