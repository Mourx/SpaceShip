#include "RewardScreen.h"

RewardScreen::RewardScreen(RenderWindow* w,Player* p, bool bBoss) {
	window = w;
	player = p;
	for (int i = 0; i < optCount; i++) {
		int r = rand() % 100;
		Charge* opt;
		if (r < 10) {
			opt = fact.GenerateCharge(COMMON);
		}
		else if (r < 20) {
			opt = fact.GenerateCharge(UNCOMMON);
		}
		else {
			opt = fact.GenerateCharge(RARE);
		}
		opt->icon.setPosition(250 + 120 * i, 200);
		opt->icon.setScale(2, 2);
		options.push_back(opt);
	}
	spaceTex.loadFromFile("space.png");
	space.setTexture(spaceTex);
	space.setPosition(0, 0);

	promptTex.loadFromFile("rewardPrompt.png");
	prompt.setTexture(promptTex);
	prompt.setPosition(300, 50);
}

RewardScreen::~RewardScreen() {

}


void RewardScreen::Draw() {
	window->draw(space);
	window->draw(prompt);
	for (Charge* c : options) {
		c->Draw(window);
	}

}


void RewardScreen::MouseDown(Vector2f m) {
	for (Charge* c : options) {
		FloatRect bounds = c->icon.getGlobalBounds();
		if (bounds.contains(m)) {
			player->selectedCharge = c;
		}
	}
}

void RewardScreen::MouseUp(Vector2f m) {
	if (player->selectedCharge != NULL) {
		FloatRect bounds = player->selectedCharge->icon.getGlobalBounds();
		if (bounds.contains(m)) {
			player->AddCharge(player->selectedCharge);
			player->selectedCharge = NULL;
			phase = PICKED;
		}
	}
	
	
	
}

void RewardScreen::MoveMouse(Vector2f m) {

}

REWARD_STATE RewardScreen::CheckState() {
	return phase;
}