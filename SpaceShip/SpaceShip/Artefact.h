#pragma once
#include "enums.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Artefact
{
public:
	Artefact();
	~Artefact();
	virtual void DrawOver(RenderWindow* w);
	virtual void setPosition(Vector2f v);
	ARTEFACT_MODIFIER getModifier() { return modifier; }
	float getValue() { return value; }
protected:
	ARTEFACT_MODIFIER modifier;
	float value;
	Sprite icon;
	Texture iconTex;
};

class AncientHammer : public Artefact {
public:
	AncientHammer();
	~AncientHammer();
private:
};