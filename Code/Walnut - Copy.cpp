#include "Walnut.h"

Walnut::Walnut(int x, int y, int aLane) {
	this->Type = 4;
	this->lane = aLane;
	this->X_coordinate = x;
	this->Y_coordinate = y;
	this->Exist = 1;
	this->Health = 5;
	this->isRolling = true;

	Plant_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\Walnut.png");
	Plant_sprite.setTexture(Plant_texture);
	Plant_sprite.setScale(0.02f, 0.02f);
}

bool Walnut::getRoll() const {
	return this->isRolling;
}

void Walnut::setRoll(bool Roll) {
	this->isRolling = Roll;
}

void Walnut::Update(sf::RenderWindow& window) {
	if (isRolling) {
		rollWalnut();
	}
}

void Walnut::rollWalnut()
{
	if (this->X_coordinate < 1200)
		this->X_coordinate += 20;
	else
		this->Exist = false;
}
