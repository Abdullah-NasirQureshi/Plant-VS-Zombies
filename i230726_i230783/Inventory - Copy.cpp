#include "Inventory.h"
#include <iostream>
using namespace std;
//Inventory();
//Inventory(int currLevel);
//void draw(sf::RenderWindow& window);

Inventory::Inventory() {
	this->currLevel = 0;
}
Inventory::Inventory(sf::RenderWindow& window, int currLevel)
{
	this->X_position = 200;
	this->Y_position = 600;

	sf::Image sunflowerImage;
	sunflowerImage.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\SunflowerCard.png");

	sf::Image peaShooterImage;
	peaShooterImage.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\peaShooterCard.png");

	sf::Image walnutImage;
	walnutImage.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\walnutCard.png");

	sf::Image repeaterImage;
	repeaterImage.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\RepeaterCard.png");

	sf::Image snowPeaImage;
	snowPeaImage.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\frozen.png");

	sf::Image cherryBombImage;
	cherryBombImage.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\CherryBombCard.png");

	switch (currLevel) {
	case 1: // Beginners Garden
		this->currLevel = 1;
		PlantSelection[0] = new Item(window, this->X_position, this->Y_position + 5, sunflowerImage);
		PlantSelection[1] = new Item(window, this->X_position + 100, this->Y_position + 5, peaShooterImage);
		PlantSelection[2] = new Item(window, this->X_position + 200, this->Y_position + 5, walnutImage);
		PlantSelection[3] = new Item(window, this->X_position + 300, this->Y_position + 5, cherryBombImage);
		PlantSelection[4] = new Item(window, this->X_position + 400, this->Y_position + 5, snowPeaImage);
		PlantSelection[5] = new Item(window, this->X_position + 500, this->Y_position + 5, repeaterImage);
		break;
	case 2: // Zombie Outskirts
		this->currLevel = 2;
		PlantSelection[0] = new Item(window, this->X_position, this->Y_position + 5, sunflowerImage);
		PlantSelection[1] = new Item(window, this->X_position + 100, this->Y_position + 5, peaShooterImage);
		PlantSelection[2] = new Item(window, this->X_position + 200, this->Y_position + 5, walnutImage);
		PlantSelection[3] = new Item(window, this->X_position + 300, this->Y_position + 5, cherryBombImage);
		PlantSelection[4] = new Item(window, this->X_position + 400, this->Y_position + 5, snowPeaImage);
		PlantSelection[5] = new Item(window, this->X_position + 500, this->Y_position + 5, repeaterImage);
		break;
	case 3:
		this->currLevel = 3;
		PlantSelection[0] = new Item(window, this->X_position, this->Y_position + 5, sunflowerImage);
		PlantSelection[1] = new Item(window, this->X_position + 100, this->Y_position + 5, peaShooterImage);
		PlantSelection[2] = new Item(window, this->X_position + 200, this->Y_position + 5, walnutImage);
		PlantSelection[3] = new Item(window, this->X_position + 300, this->Y_position + 5, cherryBombImage);
		PlantSelection[4] = new Item(window, this->X_position + 400, this->Y_position + 5, snowPeaImage);
		PlantSelection[5] = new Item(window, this->X_position + 500, this->Y_position + 5, repeaterImage);
		break;
	case 4:
		this->currLevel = 4;
		PlantSelection[0] = new Item(window, this->X_position, this->Y_position + 5, sunflowerImage);
		PlantSelection[1] = new Item(window, this->X_position + 100, this->Y_position + 5, peaShooterImage);
		PlantSelection[2] = new Item(window, this->X_position + 200, this->Y_position + 5, walnutImage);
		PlantSelection[3] = new Item(window, this->X_position + 300, this->Y_position + 5, cherryBombImage);
		PlantSelection[4] = new Item(window, this->X_position + 400, this->Y_position + 5, snowPeaImage);
		PlantSelection[5] = new Item(window, this->X_position + 500, this->Y_position + 5, repeaterImage);
		break;
	case 5:
		this->currLevel = 5;
		PlantSelection[0] = new Item(window, this->X_position, this->Y_position + 5, sunflowerImage);
		PlantSelection[1] = new Item(window, this->X_position + 100, this->Y_position + 5, peaShooterImage);
		PlantSelection[2] = new Item(window, this->X_position + 200, this->Y_position + 5, walnutImage);
		PlantSelection[3] = new Item(window, this->X_position + 300, this->Y_position + 5, cherryBombImage);
		PlantSelection[4] = new Item(window, this->X_position + 400, this->Y_position + 5, snowPeaImage);
		PlantSelection[5] = new Item(window, this->X_position + 500, this->Y_position + 5, repeaterImage);
		break;
	case 6:
		this->currLevel = 6;
		PlantSelection[0] = new Item(window, this->X_position, this->Y_position + 5, sunflowerImage);
		PlantSelection[1] = new Item(window, this->X_position + 100, this->Y_position + 5, peaShooterImage);
		PlantSelection[2] = new Item(window, this->X_position + 200, this->Y_position + 5, walnutImage);
		PlantSelection[3] = new Item(window, this->X_position + 300, this->Y_position + 5, cherryBombImage);
		PlantSelection[4] = new Item(window, this->X_position + 400, this->Y_position + 5, snowPeaImage);
		PlantSelection[5] = new Item(window, this->X_position + 500, this->Y_position + 5, repeaterImage);
		break;
	}
}

int Inventory::MouseOnAnyItem(sf::RenderWindow& window) {
	switch (currLevel) {
	case 1:
		for (int i = 0; i < 2; i++) {
			if (PlantSelection[i]->MouseInArea(window))
			{
				//cout << "in" << endl;
				return i + 1;
			}
		}
		break;
	case 2:
		for (int i = 0; i < 4; i++) {
			if (PlantSelection[i]->MouseInArea(window))
			{
				//cout << "in" << endl;
				return i + 1;
			}
		}
		break;
	case 3:
		for (int i = 0; i < 6; i++) {
			if (PlantSelection[i]->MouseInArea(window))
			{
				//cout << "in" << endl;
				return i + 1;
			}
		}
		break;
	}
	

	return 0;
}

void Inventory::draw(sf::RenderWindow& window)
{
	switch (currLevel) {
	case 1:
		for (int i = 0; i < 2; i++)
		{
			if(PlantSelection[i] != NULL)
			PlantSelection[i]->Draw_item(window);
		}
		break;
	case 2:
		for (int i = 0; i < 4; i++)
		{
			if(PlantSelection[i] != NULL)
			PlantSelection[i]->Draw_item(window);
		}
		break;
	case 3:
		for (int i = 0; i < 6; i++)
		{
			if(PlantSelection[i] != NULL)
			PlantSelection[i]->Draw_item(window);
		}
		break;
	}
	
}
