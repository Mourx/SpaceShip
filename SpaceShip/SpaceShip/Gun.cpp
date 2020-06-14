#include "Gun.h"


Gun::Gun() {
	gunTex.loadFromFile("Textures/combat/gunA.png");
	icon.setTexture(gunTex);
	icon.setScale(1.1, 1.1);
	shield = new Shield();
}

Gun::Gun(Charge* c) {
	charge = c;

}

Gun::~Gun() {


}

void Gun::SetPosition(Vector2f vec) {
	icon.setPosition(vec);
	shield->SetPosition(Vector2f(vec.x-5,vec.y-10));
}

void Gun::Draw(RenderWindow* w) {
	w->draw(icon);
	shield->Draw(w);
	
}