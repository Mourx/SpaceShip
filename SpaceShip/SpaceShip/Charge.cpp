#include "Charge.h"


Charge::Charge() {

}


void Charge::Draw(RenderWindow* w) {
	
	if (bEffectVisible) {
		w->draw(chargeEffect,&effectShade);
	}
	else {
		w->draw(icon);
	}

}

void Charge::Update(Time t) {
	if (bEffectVisible) {
		float time = t.asMicroseconds();
		timer += time;
		effectShade.setUniform("time", (effectTime - timer) / effectTime);
		if (timer >= effectTime) {
			timer = 0;
			bEffectVisible = false;
		}

	}
}
