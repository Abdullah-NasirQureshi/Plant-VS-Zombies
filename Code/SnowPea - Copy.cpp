#include "SnowPea.h"

int SnowPea::fireRate = 2;

SnowPea::SnowPea(int x, int y, int aLane) {
	this->Type = 5;
	this->lane = aLane;
	this->bullet = nullptr;
	this->X_coordinate = x;
	this->Y_coordinate = y;
	this->Exist = 1;
	this->Health = 3;

	Plant_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\FreezingPlant.png");
	Plant_sprite.setTexture(Plant_texture);
	Plant_sprite.setScale(0.45f, 0.45f);
	this->fireTime.restart();
}

//Bullet SnowPea::getBullet() const {
//	return *this->bullet;
//}

int SnowPea::getBulletX(int x)
{
	if (bullet == nullptr)
	{
		return -100;
	}
	return bullet->getX();
}

void SnowPea::setBulletExist(int x,bool s)
{
	bullet->setExist(s);
}
void SnowPea::Update(sf::RenderWindow& window) {
	if (!this->Exist) {
		return;
	}

	if (this->bullet == nullptr) {
		if (fireTime.getElapsedTime().asMilliseconds() < 2000) {
			return;
		}
		fireTime.restart();

		this->bullet = new Bullet(this->X_coordinate + 50, this->Y_coordinate + 10, this->lane, 1);
	}
	else {
		this->shootBullet(window);
	}
}

void SnowPea::shootBullet(sf::RenderWindow& window) {
	if (!this->bullet->getExists()) {
		delete this->bullet;
		this->bullet = nullptr;

		return;
	}
	this->bullet->moveBullet();
	this->bullet->DrawBullet(window);
}
