#pragma once
#include "../OOP_Pro/Zombie.h"
class FootballZombie: public Zombie
{
public:

	FootballZombie();
	FootballZombie(int x, int y, bool exist, int lane);
	virtual void moveZombie(sf::RenderWindow& window);  // moves the zombie

};

