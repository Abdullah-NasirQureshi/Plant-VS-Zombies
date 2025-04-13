#include "CherryBomb.h"

CherryBomb::CherryBomb(int x, int y, int aLane) {
	this->Type = 6;
	this->lane = aLane;
	this->X_coordinate = x;
	this->Y_coordinate = y;
	this->Exist = 1;
	this->Health = 3;

	Plant_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\CherryBomb.png");
	Plant_sprite.setTexture(Plant_texture);
	Plant_sprite.setScale(0.2f, 0.2f);
}

void CherryBomb::Update(sf::RenderWindow& window) {
	return;
}

void CherryBomb::Explode() {
	this->Exist = false;
}