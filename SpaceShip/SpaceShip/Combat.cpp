#include "Combat.h"


Combat::Combat(RenderWindow* w,Player* p,Encounter* e) {
	window = w;
	player = p;
	encounter = e;
	player->loadDeck();
	gridX = 20 + window->getSize().x / 2;
	for (int i = 0; i < 5; i++) {
		vector<Tile*> r;
		for (int j = 0; j < 5; j++) {
			r.push_back(new Tile(gridX+75*j,gridY + 80*i));
		}
		combatGrid.push_back(r);
	}
	for (Enemy* e : encounter->GetEnemies()) {
		int x = rand() % 5;
		int y = rand() % 5;
		while (combatGrid[y][x]->bHasUnit) {
			x = rand() % 5;
			y = rand() % 5;
		}
		combatGrid[y][x]->setUnit(e);
	}
	totalEnemies = encounter->GetEnemies().size();
	spaceTex.loadFromFile("Textures/general/space.png");
	space.setTexture(spaceTex);
	space.setPosition(0, 0);

	font.loadFromFile("arial.ttf");

	backTex.loadFromFile("Textures/combat/backGUI.png");
	backGUI.setTexture(backTex);
	backGUI.setPosition(0, 500);

	deckTex.loadFromFile("Textures/combat/deck.png");
	deck.setTexture(deckTex);
	deck.setPosition(30, 630);
	deckSize.setPosition(deck.getPosition().x+15,deck.getPosition().y+8);

	discardTex.loadFromFile("Textures/combat/discard.png");
	discard.setTexture(discardTex);
	discard.setPosition(720, 630);
	discardSize.setPosition(discard.getPosition().x + 15, discard.getPosition().y + 8);

	deckSize.setFont(font);
	deckSize.setCharacterSize(18);
	discardSize.setFont(font);
	discardSize.setCharacterSize(18);

	deckSize.setString(to_string(player->getDeckSize()));
	discardSize.setString(to_string(player->getDiscardSize()));

	energyTex.loadFromFile("Textures/combat/energy.png");
	energy.setTexture(energyTex);
	energy.setPosition(15, 680);
	energy.setScale(2, 2);
	energyText.setPosition(energy.getPosition().x + 45, energy.getPosition().y + 37);
	energyText.setCharacterSize(18);
	energyText.setFont(font);
	energyText.setString(to_string(player->currentEnergy));

	endTurn = new EndTurnButton();
	player->currentEnergy = player->energyPerTurn;
	UpdateStrings();
}

Combat::~Combat() {

}

void Combat::Draw() {
	window->draw(space);
	window->draw(backGUI);
	player->DrawBackground(window);
	window->draw(deck);
	window->draw(discard);
	window->draw(deckSize);
	window->draw(discardSize);
	window->draw(energy);
	window->draw(energyText);
	for (Gun* g : player->guns) {
		g->Draw(window);
	}
	for (vector<Tile*> v : combatGrid) {
		for (Tile* t : v) {
			window->draw(t->icon);
			if (t->bHasUnit) {
				t->getUnit()->Draw(window);
			}
		}
	}
	player->DrawDetails(window);
	
	endTurn->Draw(window);
	
}

void Combat::MouseDown(Vector2f m) {
	for (Charge* c : player->getHand()) {
		FloatRect bounds = c->icon.getGlobalBounds();
		if (bounds.contains(m)) {
			player->selectedCharge = c;
			offsetX = m.x - c->icon.getPosition().x;
			offsetY = m.y - c->icon.getPosition().y;
			snapPos = c->restPos;
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
		if (highlitGun == NULL || player->currentEnergy < player->selectedCharge->getCost()) {
			player->selectedCharge->icon.setPosition(snapPos);
		}
		else {
			player->selectedCharge->Fire(highlitGun,combatGrid,player->guns);
			player->UseCharge(player->selectedCharge);
			CheckDeaths();
			UpdateStrings();
		}
		player->selectedCharge = NULL;
	}
	FloatRect bounds = endTurn->icon.getGlobalBounds();
	if (bounds.contains(m)) {
		endTurn->OnClick(this);
	}
}

void Combat::UpdateStrings() {
	deckSize.setString(to_string(player->getDeckSize()));
	discardSize.setString(to_string(player->getDiscardSize()));
	energyText.setString(to_string(player->currentEnergy));
}

void Combat::Update(Time t) {
	player->Update(t);
}

void Combat::AdvanceTurn() {
	switch (phase) {
	case PLAYER_SETUP:
		
		phase = PLAYER_TURN;
		player->currentEnergy = player->energyPerTurn;
		UpdateStrings();
		break;
	case PLAYER_TURN:
		phase = AI_TURN;
		player->discardHand();
		UpdateStrings();
		DoAITurn();
		break;
	case AI_TURN:
		phase = PLAYER_TURN;
		player->drawHand();
		player->currentEnergy = player->energyPerTurn;
		UpdateStrings();
		break;
	}
}

void Combat::DoAITurn() {
	int row = 0;
	for (vector<Tile*> v : combatGrid) {
		for (Tile* t : v) {
			if (t->bHasUnit) {
				Enemy* e = t->getUnit();
				e->Attack(player->guns[row],player);
			}
		}
		row++;
	}
	CheckDeaths();
	AdvanceTurn();
}

void Combat::CheckDeaths() {
	for (vector<Tile*> v : combatGrid) {
		for (Tile* t : v) {
			if (t->bHasUnit) {
				Enemy* e = t->getUnit();
				if (e->bIsDead) {
					player->money += e->bounty;
					e->setPosition(-150, -150);
					deadEnemies.push_back(e);
					t->setUnit(NULL);

				}
			}
		}
	}
	if (player->bIsDead) {
		result = LOSS;
		cout << "Player LOSES" << endl;
	}
	else if (deadEnemies.size() == totalEnemies) {
		bCombatOver = true;
		result = WIN;
		player->levelUp();
		cout << "PLAYER WINS" << endl;
	}
}

GAME_RESULT Combat::CheckGameOver() {
	if (player->CheckAnimations()) {
		return ACTIVE;
	}
	else {
		return result;
	}
}