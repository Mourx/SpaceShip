#include "Shield.h"


Shield::Shield() {
	shieldTex.loadFromFile("Textures/combat/shield.png");
	icon.setTexture(shieldTex);
	icon.setScale(1.5, 1.5);

	health = 0;

	font.loadFromFile("arial.ttf");
	healthTex.loadFromFile("Textures/combat/health.png");
	healthIcon.setTexture(healthTex);
	healthIcon.setPosition(icon.getPosition().x - 50, icon.getPosition().y+20);
	String hp = std::to_string(health);
	healthText.setString(hp);
	healthText.setFont(font);
	healthText.setPosition(healthIcon.getPosition().x-50, healthIcon.getPosition().y);
	healthText.setCharacterSize(24);
}

Shield::~Shield() {

}

void Shield::SetPosition(Vector2f vec) {
	icon.setPosition(vec);
	healthIcon.setPosition(icon.getPosition().x - 50, icon.getPosition().y + 20);
	healthText.setPosition(healthIcon.getPosition().x - 50, healthIcon.getPosition().y);
}

void Shield::Draw(RenderWindow* w) {
	if (bIsActive) {
		w->draw(icon);
	}
	w->draw(healthIcon);
	w->draw(healthText);
}

int Shield::Damage(int dmg) {
	int remainder = 0;
	if (bIsActive) {
		health -= dmg;
		if (health <= 0) {
			remainder = abs(0 - health);
			health = 0;
			bIsActive = false;
		}
	}
	else {
		remainder = dmg;
	}
	String hp = std::to_string(health);
	healthText.setString(hp);
	return remainder;
}

void Shield::Boost(int boost) {
	health += boost;
	bIsActive = true;
	String hp = std::to_string(health);
	healthText.setString(hp);
}