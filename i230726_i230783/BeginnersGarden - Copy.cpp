#include "BeginnersGarden.h"
#include "../OOP_Pro/SimpleZombie.h"
#include "../OOP_Pro/LawnMower.h"

#include<iostream>
//#include "../OOP_Pro/Levels.h"
//#include "../OOP_Pro/Inventory.h"
//#include "../OOP_Pro/ZombieFactory.h"

BeginnersGarden::BeginnersGarden()
{

}
BeginnersGarden::BeginnersGarden(sf::RenderWindow& window)
{
	currentlevel = 1;
	Button_image.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\smallbutton.jpg");
	button[0] = new Button(window, "PAUSE", 25, 10, 50, Button_image);
	button[1] = new Button(window, "SAVE & EXIT", 25, 80, 35, Button_image);
	this->inventory = new Inventory(window, 1);
	ZombieEnteredHouse = false;

	for (int i = 0; i < 5; i++)
	{
		Mowers[i] = new LawnMower(180, (i * 100) + 80, i);
	}
}

void BeginnersGarden::createBack(sf::RenderWindow& window)
{
	map_image.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\f.jpeg");
	map.loadFromImage(map_image);
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
	button[0]->Draw_button(window);
	button[1]->Draw_button(window);
	
	
}

bool BeginnersGarden::MouseOnAnyButton(sf::RenderWindow& window, int x)
{
	if (button[x] != NULL && button[x]->MouseInArea(window))
	{
		
		
		return true;
	}

	return false;
}

void BeginnersGarden::Highligh_Buttons(int x)
{
	//cout << "karlooo  bahi!!!!\n";
	button[x]->Highlight();
}

void BeginnersGarden::original_Buttons(int x)
{
	button[x]->Original();
}


void BeginnersGarden::DrawInventory(sf::RenderWindow& window) {
	this->inventory->draw(window);
}

void BeginnersGarden::CreateZombies()
{
	int r; // x position temp for zombies
	int s;  // y position temp
	//bool sameLine = 0;  // temp bool for zombies in each row

	
		
	for (int i = 0; i < 10; i++)
	{
		int r;
		int s;

		for (int i = 0; i < 10; i++)
		{
			r = 1200 + (500 * (i % 2 == 0)) + ((rand() % 5) * 200);
			s = ((i / 2) * 100) + 40;


			for (int j = 0; j < i; j++)
			{
				if (factory.getZombie(j) != NULL) {
					if (factory.getZombie(j)->getX_coordinate() == r)
					{
						r += 500;
					}
				}
			}
			factory.setZombie(r, s, 1, i / 2, 1, i);
		}
	}
}

void BeginnersGarden::DrawZombies(sf::RenderWindow& window)
{
	//cout << "drawing zombies\n";
	for (int i = 0; i < 10; i++)
	{
		if (factory.getZombie(i) != NULL) {
			factory.getZombie(i)->DrawZombie(window);
		}
	}
}

void BeginnersGarden::moveZombies(sf::RenderWindow& window)
{
	for (int i = 0; i < 10; i++)
	{
		if (factory.getZombie(i) != NULL) {
			//cout << "Moving zombies!\n";
			factory.getZombie(i)->moveZombie(window);
			ZombieEnteredHouse = factory.getZombie(i)->getInvadedHouse();
		}
	}
}

bool BeginnersGarden::LevelCompleted()
{
	for (int i = 0; i < 10; i++)
	{
		if (factory.getZombie(i) != NULL) {
			if (factory.getZombie(i)->getExist() == true)
				return false;
		}
	}
	for(int i = 0; i < 5; i++)
	{
		if (Mowers[i]->getMove() && Mowers[i]->getExists())
			return false;
	}

	return true;  // level ended
}

void BeginnersGarden::handleSuns()
{

}

void BeginnersGarden::handleMowers(sf::RenderWindow& window)
{
	for (int i = 0; i < 5; i++)
	{
		
		Mowers[i]->DrawMower(window);
		for (int j = 0; j < 10; j++)
		{
			if (factory.getZombie(j) != NULL) {
				if (factory.getZombie(j)->getX_coordinate() < 230 && factory.getZombie(j)->getY_coordinate() == Mowers[i]->getYCoordinate() - 40 && Mowers[i]->getExists())
				{
					Mowers[i]->moveMower();
					Mowers[i]->setMove(1);
				}
				if (factory.getZombie(j)->getX_coordinate() < Mowers[i]->getXCoordinate() && factory.getZombie(j)->getY_coordinate() == Mowers[i]->getYCoordinate() - 40 && Mowers[i]->getExists())
				{
					factory.getZombie(j)->setExist(false);
				}
			}
		}

	}
}

void BeginnersGarden::ManageInteractions(sf::RenderWindow& window)
{
	for (int i = 0; i < 10; i++)
	{
		if (factory.getZombie(i) != NULL) {
			if (CheckCollision(i))
			{
				//cout << "Zombie " << i << " Should stop\n";
				factory.getZombie(i)->setX_coordinate(factory.getZombie(i)->getX_coordinate() + 10);

			}
			//else if (!CheckCollision(i))
			//{
			//	factory.getZombie(i)->setStop(0);
			//	//cout << "Zombie " << i << " Should not stop\n";
			//}
		}
	}
}

bool BeginnersGarden::getZombieEnteredHouse()
{
	return ZombieEnteredHouse;
}