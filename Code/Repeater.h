#pragma once
#include "Plant.h"
#include "Bullet.h"
class Repeater : public Plant
{
private:
	Bullet* bullet[2];
	sf::Clock fireTime;
	static int fireRate;
public:
	Repeater(int, int, int);



	/*Bullet getBullet() const;*/
	virtual int getBulletX(int x);
	virtual void setBulletExist(int x, bool s);
	virtual void Update(sf::RenderWindow& window);
	void shootBullet(sf::RenderWindow& window);
};

