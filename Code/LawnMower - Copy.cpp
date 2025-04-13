#include "LawnMower.h"
#include<iostream>


LawnMower::LawnMower()
{
	LawnMower_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\lawnMover.png");
	LawnMower_sprite.setTexture(LawnMower_texture);
	LawnMower_sprite.setScale(0.3f, 0.3f);
	exists = true;
	move = false;
	X_Coordinate = 200;
	Y_Coordinate = 80;
}
LawnMower::LawnMower(int x, int y, int i)
{
	LawnMower_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\lawnMover.png");
	LawnMower_sprite.setTexture(LawnMower_texture);
	LawnMower_sprite.setScale(0.3f, 0.3f);
	move = false;
	lane = i;
	exists = true;
	X_Coordinate = x;
	Y_Coordinate = y;
}

void LawnMower::setXCoordinate(int x) {
	X_Coordinate = x;
}

int LawnMower::getXCoordinate() const {
	return X_Coordinate;
}

void LawnMower::setYCoordinate(int y) {
	Y_Coordinate = y;
}

int LawnMower::getYCoordinate() const {
	return Y_Coordinate;
}

int LawnMower::getLane() {
	return lane;
}

void LawnMower::setExists(bool e) {
	exists = e;
}

bool LawnMower::getExists() const {
	return exists;

}

void LawnMower::setMove(bool e) {
	move = e;
}

bool LawnMower::getMove() const {
	return move;

}

void LawnMower::moveMower()
{
	//std::cout<<"moving mower"<<std::endl;
	if (Mower_clock.getElapsedTime().asMilliseconds() < 5 && exists)
		return;

	Mower_clock.restart();


	if (X_Coordinate < 1200)
		X_Coordinate += 8;
	else
		exists = false;
}
void LawnMower::DrawMower(sf::RenderWindow& window)
{
	if (exists == true)
	{
		/*std::cout << "X " << X_coordinate << std::endl;
		std::cout << "Y " << Y_coordinate << std::endl;*/
		LawnMower_sprite.setPosition(X_Coordinate, Y_Coordinate);
		window.draw(LawnMower_sprite);
	}
}