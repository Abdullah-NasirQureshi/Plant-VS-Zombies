#include "SunflowerField.h"
#include "ZombieOutskirts.h"
#include "../OOP_Pro/SimpleZombie.h"
#include "../OOP_Pro/FootballZombie.h"
#include "../OOP_Pro/FlyingZombie.h"
#include "../OOP_Pro/DancingZombie.h"
#include "../OOP_Pro/Levels.h"
#include<iostream>

SunflowerField::SunflowerField()
{

}

SunflowerField::SunflowerField(sf::RenderWindow& window)
{
	currentlevel = 3;
	Button_image.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\smallbutton.jpg");
	button[0] = new Button(window, "PAUSE", 25, 10, 50, Button_image);
	button[1] = new Button(window, "SAVE & EXIT", 25, 80, 35, Button_image);
	ZombieEnteredHouse = false;

	for (int i = 0; i < 5; i++)
	{
		Mowers[i] = new LawnMower(180, (i * 100) + 80, i);
	}
}


void SunflowerField::createBack(sf::RenderWindow& window)
{
	map_image.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\f.jpeg");
	map.loadFromImage(map_image);
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
	button[0]->Draw_button(window);
	button[1]->Draw_button(window);
	for (int i = 0; i < 10; i++)
	{
		//if(factory.getZombie(i)->getX_coordinate() < 230)
	}
	for (int i = 0; i < 5; i++)
	{
		Mowers[i]->DrawMower(window);
		for (int j = 0; j < 40; j++)
		{
			if (factory.getZombie(j) != NULL) {
				if (factory.getZombie(j)->getX_coordinate() < 230 && factory.getZombie(j)->getY_coordinate() == Mowers[i]->getYCoordinate() - 40)
				{
					Mowers[i]->moveMower();
				}
			}
		}
	}
}


bool SunflowerField::MouseOnAnyButton(sf::RenderWindow& window, int x)
{
	if (button[x] != NULL && button[x]->MouseInArea(window))
	{
		//cout << "in"<<endl;
		return true;
	}

	return false;
}

void SunflowerField::Highligh_Buttons(int x)
{
	button[x]->Highlight();
}

void SunflowerField::original_Buttons(int x)
{
	button[x]->Original();
}


void SunflowerField::CreateZombies()
{
	for (int i = 0;i < 10; i++)
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

			if (factory.getZombie(i) == NULL) {
				factory.setZombie(r, s, 1, i / 2, 1, i);
			}

			r = 2500 + (800 * (i % 2 == 0)) + ((rand() % 10) * 200);
			s = ((i / 2) * 100) + 40;


			for (int j = 0; j < i; j++)
			{
				if (factory.getZombie(j) != NULL) {
					if (factory.getZombie(j)->getX_coordinate() == r)
					{
						r += 600;
					}
				}
			}

			if (factory.getZombie(i + 10) == NULL) {
				factory.setZombie(r, s, 1, i / 2, 2, i + 10);
			}

			r = 2500 + (800 * (i % 2 == 0)) + ((rand() % 10) * 200);
			s = ((i / 2) * 100) + 40;


			for (int j = 20; j < i + 20; j++)
			{
				if (factory.getZombie(j) != NULL) {
					if (factory.getZombie(j)->getX_coordinate() == r)
					{
						r += 600;
					}
				}
			}

			if (factory.getZombie(i + 20) == NULL) {
				factory.setZombie(r, s, 1, i / 2, 3, i + 20);
			}

			r = 3000 + (800 * (i % 2 == 0)) + ((rand() % 10) * 200);
			s = ((i / 2) * 100);


			for (int j = 30; j < i + 30; j++)
			{
				if (factory.getZombie(j) != NULL) {
					if (factory.getZombie(j)->getX_coordinate() == r)
					{
						r += 600;
					}
				}
			}

			if (factory.getZombie(i + 30) == NULL) {
				factory.setZombie(r, s, 1, i / 2, 4, i + 30);
			}

			r = 3000 + (800 * (i % 2 == 0)) + ((rand() % 10) * 200);
			s = ((i / 2) * 100);

			for (int j = 40; j < i + 40; j++)
			{
				if (factory.getZombie(j) != NULL) {
					if (factory.getZombie(j)->getX_coordinate() == r)
					{
						r += 600;
					}
				}
			}

			if (factory.getZombie(i + 40) == NULL) {
				factory.setZombie(r, s, 1, i / 2, 5, i + 40);
			}
		}
	}
}

void SunflowerField::DrawInventory(sf::RenderWindow& window) {
	this->inventory->draw(window);
}

void SunflowerField::DrawZombies(sf::RenderWindow& window)
{
	for (int i = 0; i < 50; i++)
	{
		if (factory.getZombie(i) != NULL) {
			factory.getZombie(i)->DrawZombie(window);
		}
	}
}

void SunflowerField::moveZombies(sf::RenderWindow& window)
{
	for (int i = 0; i < 50; i++)
	{
		if (factory.getZombie(i) != NULL) {
			factory.getZombie(i)->moveZombie(window);
			if (ZombieEnteredHouse == 0)
				ZombieEnteredHouse = factory.getZombie(i)->getInvadedHouse();
			//std::cout << "receivedd : " << ZombieEnteredHouse << std::endl;
		}
	}
}


bool SunflowerField::LevelCompleted()
{
	for (int i = 0; i < 50; i++)
	{
		if (factory.getZombie(i) != NULL) {
			if (factory.getZombie(i)->getExist() == true)
				return false;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (Mowers[i]->getMove() && Mowers[i]->getExists())
			return false;
	}

	return true;  // level ended
}

void SunflowerField::handleSuns()
{

}

void SunflowerField::handleMowers(sf::RenderWindow& window)
{
	for (int i = 0; i < 5; i++)
	{

		Mowers[i]->DrawMower(window);
		for (int j = 0; j < 50; j++)
		{
			if (factory.getZombie(j) != NULL) {
				if (factory.getZombie(j)->getX_coordinate() < 230 && factory.getZombie(j)->getLane() == Mowers[i]->getLane() && Mowers[i]->getExists())
				{
					if (j > 10)
						cout << "in for the footballers\n";
					Mowers[i]->moveMower();
					Mowers[i]->setMove(1);
				}
				if (Mowers[i]->getMove())
				{
					Mowers[i]->moveMower();
					//Mowers[i]->setMove(1);
				}
				if (factory.getZombie(j)->getX_coordinate() < Mowers[i]->getXCoordinate() && factory.getZombie(j)->getLane() == Mowers[i]->getLane() && Mowers[i]->getExists())
				{
					factory.getZombie(j)->setExist(false);
				}
			}
		}

	}
}

void SunflowerField::ManageInteractions(sf::RenderWindow& window)
{
	for (int i = 0; i < 20; i++)
	{
		if (factory.getZombie(i) != NULL) {
			if (CheckCollision(i))
			{
				//cout << "Zombie " << i << " Should stop\n";
				factory.getZombie(i)->setX_coordinate(factory.getZombie(i)->getX_coordinate() + 10);

			}
			/*else if (!CheckCollision(i))
				factory.getZombie(i)->setStop(0);*/
		}
	}

	for (int j = 20; j < 30; j++)
	{
		if (factory.getZombie(j) != NULL) {
			if (CheckCollision(j))
			{
				//cout << "Zombie " << i << " Should stop\n";
				//factory.getZombie(j)->setX_coordinate(factory.getZombie(j)->getX_coordinate() + 10);
				factory.getZombie(j)->setY_coordinate(factory.getZombie(j)->getY_coordinate() - 5);
				//factory.getZombie(j)->setLane(factory.getZombie(j)->getLane() - 1);

			}
			/*else if (!CheckCollision(j) && factory.getZombie(j)->getFlyingZombieCollided())
				factory.getZombie(j)->setY_coordinate(factory.getZombie(j)->getY_coordinate() + 5);*/
		}
	}

	for (int j = 30; j < 40; j++)
	{
		if (factory.getZombie(j) != NULL) {
			if (CheckCollision(j))
			{
				//cout << "Zombie " << i << " Should stop\n";
				factory.getZombie(j)->SummonZombies();
				factory.getZombie(j)->setX_coordinate(factory.getZombie(j)->getX_coordinate() + 10);
				factory.getZombie(j)->setLane(factory.getZombie(j)->getLane() - 1);

			}
		}
	}

	for (int i = 40; i < 50; i++)
	{
		if (factory.getZombie(i) != NULL) {
			if (CheckCollision(i))
			{
				//cout << "Zombie " << i << " Should stop\n";
				factory.getZombie(i)->setX_coordinate(factory.getZombie(i)->getX_coordinate() + 10);

			}
			/*else if (!CheckCollision(i))
				factory.getZombie(i)->setStop(0);*/
		}
	}
}

bool SunflowerField::getZombieEnteredHouse()
{
	return ZombieEnteredHouse;
}