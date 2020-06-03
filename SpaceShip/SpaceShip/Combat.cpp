#include "Combat.h"


Combat::Combat(RenderWindow* w) {
	window = w;
	gridX = 20 + window->getSize().x / 2;
	for (int i = 0; i < 5; i++) {
		vector<Tile*> r;
		for (int j = 0; j < 5; j++) {
			r.push_back(new Tile(gridX+75*j,gridY + 80*i));
		}
		combatGrid.push_back(r);
	}
	combatGrid[2][0]->setUnit(new Dummy());
	spaceTex.loadFromFile("space.png");
	space.setTexture(spaceTex);
	space.setPosition(0, 0);

	player = new Player();
}

Combat::~Combat() {

}

void Combat::Draw() {
	window->draw(space);
	for (vector<Tile*> v : combatGrid) {
		for (Tile* t : v) {
			window->draw(t->icon);
			if (t->bHasUnit) {
				window->draw(t->getUnit()->icon);
			}
		}
	}
	player->Draw(window);
	for (Gun* g : player->guns) {
		window->draw(g->icon);
	}
	
}

void Combat::MouseDown(Vector2f m) {
	for (Charge* c : player->getHand()) {
		FloatRect bounds = c->icon.getGlobalBounds();
		if (bounds.contains(m)) {
			player->selectedCharge = c;
			offsetX = m.x - c->icon.getPosition().x;
			offsetY = m.y - c->icon.getPosition().y;
			snapPos = c->icon.getPosition();
		}
	}
}

void Combat::MoveMouse(Vector2f m) {
	if (!player->selectedCharge == NULL) {
		player->selectedCharge->icon.setPosition(m.x-offsetX,m.y-offsetY);
		bool bGun = false;
		for (Gun* g : player->guns) {
			FloatRect bounds = g->icon.getGlobalBounds();
			if (bounds.contains(m)) {
				highlitGun = g;
				bGun = true;
			}
		}
		if (!bGun) {
			highlitGun = NULL;
		}
	}
}

void Combat::MouseUp(Vector2f m) {
	if (player->selectedCharge != NULL) {
		if (highlitGun == NULL) {
			player->selectedCharge->icon.setPosition(player->handPos[player->selectedCharge->handPos]);
		}
		else {
			player->selectedCharge->Fire(highlitGun,combatGrid);
			player->UseCharge(player->selectedCharge);
		}
		player->selectedCharge = NULL;
	}
}

void Combat::Update(Time t) {
	player->Update(t);
}