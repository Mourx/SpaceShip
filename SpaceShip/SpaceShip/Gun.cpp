#include "Gun.h"


Gun::Gun() {
	gunTex.loadFromFile("gunA.png");
	icon.setTexture(gunTex);
	icon.setScale(1.1, 1.1);
}

Gun::Gun(Charge* c) {
	charge = c;

}

Gun::~Gun() {


}