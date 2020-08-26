#include "Enemy.h"


Enemy::Enemy() {
	name = "Base Enemy Class";
	health = 0;
	damage = 0;
	ship = new Ship();
	iconTex.loadFromFile("Textures/combat/enemyA.png");
	icon.setTexture(iconTex);
	font.loadFromFile("arial.ttf");

	attackText.setFont(font);
	attackText.setCharacterSize(12);

	healthText.setFont(font);
	healthText.setCharacterSize(12);

	attackTex.loadFromFile("Textures/combat/attack.png");
	healthTex.loadFromFile("Textures/combat/health.png");
	attackIcon.setTexture(attackTex);
	healthIcon.setTexture(healthTex);
	attackIcon.setScale(0.5, 0.5);
	healthIcon.setScale(0.5, 0.5);
	effectShade.loadFromFile("Textures/shaders/effectShade.vert", Shader::Vertex);

}

Enemy::~Enemy() {

}

void Enemy::setPosition(float x, float y) {
	icon.setPosition(x, y);
	attackText.setPosition(x     , y + 50);
	attackIcon.setPosition(x + 15, y + 52);
	healthText.setPosition(x + 25, y + 50);
	healthIcon.setPosition(x + 40, y + 52);
}

String Enemy::getName() {
	return name;
}

float Enemy::getHealth() {
	return health;
}

void Enemy::Draw(RenderWindow* w) {

	w->draw(icon);
	w->draw(attackText);
	w->draw(attackIcon);
	w->draw(healthText);
	w->draw(healthIcon);
	
	
}
void Enemy::DrawOver(RenderWindow* w) {
	
    if (bEffectVisible) {
		w->draw(attackEffect, &effectShade);
	}
}

void Enemy::Damage(int dmg) {
	health -= dmg;
	if (health <= 0) {
		health = 0;
		bIsDead = true;
	}
	String hp = to_string(health);
	healthText.setString(hp);
}

void Enemy::Update(Time t) {
	if (bAttackDelayed) {
		float time = (float)(t.asMicroseconds());
		delayTimer += time;
		if (delayTimer >= delayTime) {
			bEffectVisible = true;
			bAttackDelayed = false;
			delayTimer = 0;
		}
	}
	if (bEffectVisible) {
		float time = (float)(t.asMicroseconds());
		timer += time;
		effectVal = (effectTime - timer) / effectTime;
		effectShade.setUniform("time", effectVal);
		if (timer >= effectTime) {
			timer = 0;
			bEffectVisible = false;
		}

	}
	attackEffect.setScale(-1, 1);
	attackEffect.setPosition(this->icon.getPosition());

}