#include "Repeater.h"
#include<iostream>

int Repeater::fireRate = 2;

Repeater::Repeater(int x, int y, int aLane) {
	this->Type = 3;
	this->lane = aLane;
	this->bullet[0] = nullptr;
	this->bullet[1] = nullptr;
	this->X_coordinate = x;
	this->Y_coordinate = y;
	this->Exist = 1;
	this->Health = 3;
	Plant_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\Repeater.png");
	Plant_sprite.setTexture(Plant_texture);
	Plant_sprite.setScale(0.07f, 0.07f);
	this->fireTime.restart();
}

//Bullet Repeater::getBullet() const { // returns the first bullet
//	for (int i = 0; i < 2; i++) {
//		if (this->bullet[i] != nullptr) {
//			return *this->bullet[i];
//		}
//	}
//}


int Repeater::getBulletX(int x)
{
	if (bullet[x] == nullptr)
	{
		//std::cout << "returning -10\n";
		return -10;
	}
	else
	{
		//std::cout << "returning "<< bullet[x]->getX()<<std::endl;
		return bullet[x]->getX();
	}
}

void Repeater::setBulletExist(int x, bool s)
{
	static sf::Clock clock;

	if(bullet[x]!=nullptr)
	bullet[x]->setExist(s);
	//bullet[1]->setExist(s);
	/*if (clock.getElapsedTime().asSeconds() >= 1)
	{
		
		bullet[1]->setExist(s);

	}
	clock.restart();*/
}

void Repeater::Update(sf::RenderWindow& window) {
	if (!this->Exist) {
		return;
	}

	bool fired = false;
	if (this->bullet[0] == nullptr && this->bullet[1] == nullptr) {
		for (int i = 0; i < 2; i++) {
			if (fireTime.getElapsedTime().asMilliseconds() < 2000) {
				return;
			}

			fired = true;
			this->bullet[i] = new Bullet(this->X_coordinate + 50 * (2 - i), this->Y_coordinate + 10, this->lane, 0);
		}
	}
	else {
		for (int i = 0; i < 2; i++) {
			this->shootBullet(window);
		}
	}

	if (fired) {
		fireTime.restart();
	}
}

void Repeater::shootBullet(sf::RenderWindow& window) {
	for (int i = 0; i < 2; i++) {
		if (this->bullet[i] != nullptr) {
			if (!this->bullet[i]->getExists()) {
				delete this->bullet[i];
				this->bullet[i] = nullptr;

				return;
			}
			this->bullet[i]->moveBullet();
			this->bullet[i]->DrawBullet(window);
		}
	}
}
