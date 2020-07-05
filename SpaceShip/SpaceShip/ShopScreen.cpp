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
}



ShopScreen::~ShopScreen() {

}

void ShopScreen::Draw() {
	window->draw(space);
	for (Shoption* s : chargesSold) {
		s->Draw(window);
	}
}