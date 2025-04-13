#pragma once
#include "../OOP_Pro/Zombie.h"

class DancingZombie : public Zombie
{
public:

	DancingZombie();
	DancingZombie(int x, int y, bool exist, int lane);
	Zombie* dancers[4];
	virtual void moveZombie(sf::RenderWindow& window);  // moves the zombie
	virtual void SummonZombies();

};

