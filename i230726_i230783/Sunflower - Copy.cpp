#include "Sunflower.h"
#include <iostream>

using namespace std;

int Sunflower::ProductionRate = 5;

Sunflower::Sunflower(int x, int y, int aLane) {
	//std::cout << "Constructor of Sunflower!\n";
	this->X_coordinate = x;
	this->Y_coordinate = y;
	this->lane = aLane;
	this->sunlight = nullptr;
	this->Type = 1;
	this->Exist = 1;
	this->Health = 3;
	Plant_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\SunFlower.png");
	Plant_sprite.setTexture(Plant_texture);
	Plant_sprite.setScale(0.1f, 0.1f);
	this->ProductionTime.restart();
}

int Sunflower::getProductionRate() const {
	return this->ProductionRate;
}

void Sunflower::Update(sf::RenderWindow& window) {
	if (sunlight == nullptr) {
		GenerateSunlight();
	}
	else {
		sunlight->drawSun(window);
		//cout << "SUN DRAWN" << endl;
	}
}

void Sunflower::GenerateSunlight() {
	if (ProductionTime.getElapsedTime().asSeconds() < ProductionRate) {
		return;
	}
	ProductionTime.restart();
	
	
	if (sunlight == nullptr) {
		sunlight = new Sunlight(this->X_coordinate + 20, this->Y_coordinate + 50);
		sunlight->setCurrency(sunlight->getCurrency() + 50);
		sunlight->setExist(true);
		cout << "SUN PRODUCED" << endl;
	}
}

bool Sunflower::interact(sf::RenderWindow& window) {
	if (sunlight->mouseOverSun(window)) {
		return true;
		delete sunlight;
		sunlight = nullptr;
	}

	return false;
}