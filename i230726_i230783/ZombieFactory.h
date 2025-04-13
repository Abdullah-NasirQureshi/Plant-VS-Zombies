#pragma once
#include "../OOP_Pro/Zombie.h"
#include "../OOP_Pro/Sunlight.h"
class ZombieFactory
{
private:
	Zombie* zombies[50];
public:
	ZombieFactory();
	//~ZombieFactory();

	Zombie* getZombie(int) const;
	void setZombie(int, int, bool, int, int, int);
};

