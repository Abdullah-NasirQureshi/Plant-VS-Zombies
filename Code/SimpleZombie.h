#pragma once
#include "../OOP_Pro/Zombie.h"
class SimpleZombie: public Zombie
{
public:
	SimpleZombie();
	SimpleZombie(int x, int y, bool exist, int lane);
};

