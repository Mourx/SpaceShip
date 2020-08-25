#include "Charge.h"


Charge::Charge() {
	toolTipTex.loadFromFile("Textures/charges/toolTip.png");
	toolTipBox.setTexture(toolTipTex);
	description.setCharacterSize(20);
	description.setPosition(toolTipBox.getPosition() + Vector2f(40, 40));
	description.setString("hello");
	font.loadFromFile("arial.ttf");
	description.setFont(font);
}


void Charge::DrawUnder(RenderWindow* w) {
	
	if (bEffectVisible) {
		w->draw(chargeEffect,&effectShade);
	}
	else {
		w->draw(icon);
	}
	
}

void Charge::DrawOver(RenderWindow* w) {
	if (bHover) {
		w->draw(toolTipBox);
		w->draw(description);
	}
}

void Charge::Update(Time t, vector<Artefact*> arts) {
	bonusRAW = 0;
	bonusBOOST = 1;
	for (Artefact* a : arts) {
		switch (a->getModifier()) {
		case DAMAGE_BOOST:
			if (type == DAMAGE) {
				bonusBOOST *= a->getValue();
			}
			break;
		case DAMAGE_RAW:
			if (type == DAMAGE) {
				bonusRAW += a->getValue();
			}
		}
	}
	totalDamage = damage;
	
	totalDamage += bonusRAW;
	totalDamage *= bonusBOOST;
	toolTipBox.setPosition(icon.getPosition() - Vector2f(0, 200));
	if (toolTipBox.getPosition().y < 0) {
		toolTipBox.setPosition(toolTipBox.getPosition().x,0);
	}
	if (toolTipBox.getPosition().x > values.WINDOW_WIDTH-300) {
		toolTipBox.setPosition((float)(values.WINDOW_WIDTH - 300), toolTipBox.getPosition().y);
	}
	description.setPosition(toolTipBox.getPosition() + Vector2f(40, 40));
	if (bEffectVisible) {
		float time = (float)(t.asMicroseconds());
		timer += time;
		effectShade.setUniform("time", (effectTime - timer) / effectTime);
		if (timer >= effectTime) {
			timer = 0;
			bEffectVisible = false;
		}

	}
}
