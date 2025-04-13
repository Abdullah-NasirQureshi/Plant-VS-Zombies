#pragma once
#include "Plant.h"
#include "Bullet.h"
class PeaShooter : public Plant 
{
private:
	Bullet* bullet;
	sf::Clock fireTime;
	static int fireRate;
public:
	PeaShooter(int, int, int);

	virtual int getBulletX(int x);
	virtual void setBulletExist(int x, bool s);
	virtual void Update(sf::RenderWindow& window);
	void shootBullet(sf::RenderWindow& window);
};

