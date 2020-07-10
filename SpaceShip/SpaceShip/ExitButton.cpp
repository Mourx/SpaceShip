#include "Button.h"

ExitShopButton::ExitShopButton() {
	buttTex.loadFromFile("Textures/shop/shopExit.png");
	icon.setTexture(buttTex);
	icon.setPosition(550, 650);
}

ExitShopButton::~ExitShopButton() {

}

void ExitShopButton::OnClick(ShopScreen* screen) {
	screen->ExitShop();
}