#pragma once
#include "../OOP_Pro/Zombie.h"
class DolphinZombie:public Zombie
{
public:
	DolphinZombie();
	DolphinZombie(int x, int y, bool exist, int lane);
	virtual void moveZombie(sf::RenderWindow& window);  // moves the zombie

};

