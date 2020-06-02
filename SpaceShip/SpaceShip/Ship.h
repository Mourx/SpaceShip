#pragma once
#include "Gun.h"
#include <vector>
using namespace std;


class Ship
{
public:
	Ship(int gunCap);
	Ship();
	~Ship();
	void GiveGun(Gun* g);
	vector<Gun*> guns;
private:
	int gunCapacity = 0;
	
};

