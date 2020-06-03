#include "Charge.h"

BasicCharge::BasicCharge() {
	chargeTex.loadFromFile("basicCharge.png");
	icon.setTexture(chargeTex);
	icon.setScale(1, 1);

	chargeEffTex.loadFromFile("chargeEffect.png");
	chargeEffect.setTexture(chargeEffTex);

	effectTime = 1000;
}
BasicCharge::~BasicCharge() {

}
void BasicCharge::Fire(Gun* g) {
	//take row
	//fire at front enemy
	cout << "derived" << endl;
	timer = 0;
	bEffectVisible = true;
	chargeEffect.setPosition(g->icon.getPosition().x + 50, g->icon.getPosition().y);
}

void BasicCharge::StartTimer(Time t) {

}

void BasicCharge::Update(Time t) {
	if (bEffectVisible) {
		timer += t.asMilliseconds();
		if (timer >= effectTime) {
			timer = 0;
			bEffectVisible = false;
		}
		
	}
}

void BasicCharge::Draw(RenderWindow* w) {
	w->draw(icon);
	if (bEffectVisible) {
		w->draw(chargeEffect);
	}

}