#pragma once
#include <SFML/Graphics.hpp>
#include "Charge.h"
#include <vector>
using namespace sf;
using namespace std;
class RewardScreen
{
public: 
	RewardScreen();
	~RewardScreen();
	void Draw(RenderWindow* window);

private:
	vector<Charge*> options;
};

