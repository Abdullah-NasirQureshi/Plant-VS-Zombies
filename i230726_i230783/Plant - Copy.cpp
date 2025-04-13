#include "Plant.h"
#include<iostream>

// Setters
void Plant::setX_coordinate(int x) {
    X_coordinate = x;
}

void Plant::setY_coordinate(int y) {
    Y_coordinate = y;
}

void Plant::setExist(bool exist) {
    Exist = exist;
}

void Plant::setHealth(int health) {
    Health = health;
}
void Plant::setLane(int aLane) {
	this->lane = aLane;
}

// Getters
int Plant::getX_coordinate() const {
    return X_coordinate;
}

int Plant::getY_coordinate() const {
    return Y_coordinate;
}

int Plant::getLane() const {
	return this->lane;
}

int Plant::getType() const {
	return this->Type;
}

bool Plant::getExist() const {
    return Exist;
}

int Plant::getHealth() const {
    return Health;
}

void Plant::receiveDamage(int damage) {
	this->Health -= damage;
}

bool Plant::checkHealth() {
	if (this->Health <= 0) {
		this->Exist = false;
		return 0;
	}
	return 1;
}

void Plant::DrawPlant(sf::RenderWindow& window) {
	//checkHealth();
	//sstd::cout << "Drawing plantsssssssssssssssssssssssssss\n";
	if (Health < 1)
		Exist = false;

	if (Exist == true)
	{
		/*std::cout << "X " << X_coordinate << std::endl;
		std::cout << "Y " << Y_coordinate << std::endl;*/
		Plant_sprite.setPosition(X_coordinate, Y_coordinate);
		window.draw(Plant_sprite);
	}
}

bool Plant::interact(sf::RenderWindow& window)
{
	return false;
}
