#pragma once
#include "../OOP_Pro/Zombie.h"
class FlyingZombie : public Zombie
{

public:

	FlyingZombie();
	FlyingZombie(int x, int y, bool exist, int lane);
	virtual void moveZombie(sf::RenderWindow& window);  // moves the zombie

};

