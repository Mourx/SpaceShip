#pragma once
#include "enums.h"
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class StageType
{
public:
	StageType(STAGE_TYPE t);
	~StageType();
	STAGE_TYPE GetType();
	Sprite icon;
private:
	STAGE_TYPE type;
	Texture tex;
};

