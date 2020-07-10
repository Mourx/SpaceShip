#include "ShopScreen.h"


ShopScreen::ShopScreen(RenderWindow* w, Player* p) {
	window = w;
	player = p;
	spaceTex.loadFromFile("Textures/general/space.png");
	space.setTexture(spaceTex);
	space.setPosition(0, 0);

	for (int i = 0; i < ChargeChoices; i++) {
		ShoptionCharge* shopt = new ShoptionCharge();
		shopt->SetPosition(40 + i * 120, 100);
		shopt->getCharge()->icon.setScale(2, 2);
		chargesSold.push_back(shopt);
		
	}
	exit = new ExitShopButton();

}



ShopScreen::~ShopScreen() {

}

void ShopScreen::Draw() {
	window->draw(space);
	window->draw(exit->icon);
	for (Shoption* s : chargesSold) {
		s->Draw(window);
	}
	for (Shoption* s : chargesSold) {
		s->DrawOver(window);
	}
}

void ShopScreen::ExitShop() {
	phase = PICKED;
}


void ShopScreen::MouseDown(Vector2f m) {
	selectedShopt = NULL;
	for (Shoption* s : chargesSold) {
		FloatRect bounds = s->icon->getGlobalBounds();
		if (bounds.contains(m)) {
			selectedShopt = s;
		}
	}
}


void ShopScreen::MouseUp(Vector2f m) {
	Shoption* bought = NULL;
	if (selectedShopt != NULL) {
		for (Shoption* s : chargesSold) {
			if (s == selectedShopt) {
				FloatRect bounds = s->icon->getGlobalBounds();
				if (bounds.contains(m)) {
					Buy((ShoptionCharge*)s);
					bought = s;
				}
			}
		}
		if (bought != NULL) {
			chargesSold.erase(remove(chargesSold.begin(),chargesSold.end(),bought),chargesSold.end());
		}
	}
	else {
		FloatRect bounds = exit->icon.getGlobalBounds();
		if (bounds.contains(m)) {
			exit->OnClick(this);
		}
	}
	
	
}


void ShopScreen::MoveMouse(Vector2f m) {
	mousePos = m;
	for (Shoption* s : chargesSold) {
		ShoptionCharge* c = (ShoptionCharge*)s;
		FloatRect bounds = c->icon->getGlobalBounds();
		if (bounds.contains(m)) {
			c->getCharge()->setHover(true);
		}
		else {
			c->getCharge()->setHover(false);
		}
	}
}

void ShopScreen::Buy(ShoptionCharge* s) {
	if (player->getMoney() >= s->getCost()) {
		player->addMoney(-s->getCost());
		player->AddCharge(s->getCharge());
	}
}

void ShopScreen::Update(Time t) {
	player->Update(t);
	for (Shoption* s : chargesSold) {
		s->Update(t);
	}
}