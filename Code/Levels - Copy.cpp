#include "Levels.h"
#include<iostream>
//#include "../OOP_Pro/Sunlight.h"
#include "Sunflower.h"
#include "PeaShooter.h"
#include "Repeater.h"
#include "SnowPea.h"
#include "Walnut.h"
#include "CherryBomb.h"

//void Levels::setupLevel(sf::RenderWindow& window)
//{
//	CreateZombies();
//	DrawZombies(window);
//	moveZombies();
//	
//}

PlantFactory Levels::getPlantFactory()
{
	return plantFactory;
}

void Levels::setPlantFactory(PlantFactory p)
{
	plantFactory = p;
}

ZombieFactory Levels::getZombieFactory()
{
	return factory;
}


void Levels::createButton(sf::RenderWindow& window)
{
	
	Button_image.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\smallbutton.jpg");
	/*Button_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\smallbutton.jpg");
	Button_sprite.setTexture(Button_texture);*/
	//Button_sprite.setScale(0.5f, 0.5f);
	button[0] = new Button(window, "PAUSE", 1030, 10, 50, Button_image);
	button[1] = new Button(window, "SAVE & EXIT", 15, 30, 50, Button_image);
	button[2] = new Button(window, "level", 15, 30, 50, Button_image);

	/*Button_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\smallbutton.jpg");
	button = new Button(window, "PAUSE", 1030, 10, 50, Button_image);*/
	//button->Draw_button(window);
}

void Levels::handleSuns(sf::RenderWindow& window, sf::Event event)
{
	sun->drawSun(window);
	sun->dropSun();
	sun->UpdateCurrency(window, event);
	//collect sunflower sunlight
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (plantFactory.getPlant(i, j)->getType() == 1) {
				if (plantFactory.getPlant(i, j)->interact(window)) {
					sun->UpdateCurrency(window, event);
				}
			}
		}
	}
}

void Levels::InformationStrip(sf::RenderWindow& window, int lives, int score)
{

	font.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Fonts\\Jersey10-Regular.ttf");
	Sun_currency.setString(std::to_string(Sunlight::currency));
	Sun_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\sun.png");
	Sun_sprite.setTexture(Sun_texture);
	Sun_sprite.setScale(0.5f, 0.5f);
	Sun_sprite.setPosition(20, 580);
	Sun_currency.setPosition(20, 640);
	Sun_currency.setFont(font);
	Sun_currency.setFillColor(sf::Color::Black);
	Sun_currency.setCharacterSize(50);
	window.draw(Sun_sprite);
	window.draw(Sun_currency);


	lev.setString("LEVEL" + std::to_string(currentlevel));
	
	lev.setPosition(1000, 600);
	lev.setFont(font);
	lev.setFillColor(sf::Color::Black);
	lev.setCharacterSize(50);
	window.draw(lev);
	
}

void Levels::DamagePlant(int i , int j)
{
	plantFactory.getPlant(i,j)->setHealth(plantFactory.getPlant(i,j)->getHealth() - 1);
}

bool Levels::PlacePlant(int selectedPlant, float mouseX, float mouseY) {
	int gridX = ((int)mouseX - 250) / 100; //100 is the average tile width
	int gridY = ((int)mouseY - 80) / 100; //100 is the average tile height
	//subtracting 250 and 80 because the grid starts at (250,80)

	if (gridX >= 0 && gridX <= 8 && gridY >= 0 && gridY <= 4 && plantFactory.getPlant(gridY, gridX) == NULL) {
		plantFactory.setPlant(gridY, gridX, selectedPlant);
		PlantCount++;
		return true;
	}

	return false;
}

void Levels::DrawPlants(sf::RenderWindow& window)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (plantFactory.getPlant(i,j) != NULL) {
				plantFactory.getPlant(i,j)->DrawPlant(window);
			}
		}
	}
}

void Levels::UpdatePlants(sf::RenderWindow& window)
{
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (plantFactory.getPlant(i,j) != NULL) {
				if (plantFactory.getPlant(i,j)->getExist() == false) {
					//delete plantFactory.getPlant(i,j);
					plantFactory.getPlant(i,j) == NULL;
				}
				else {
					//cout << "Plant is being updated!\n";
					switch (plantFactory.getPlant(i,j)->getType()) {
					case 1: // sunflower case
						plantFactory.getPlant(i,j)->Update(window);
						break;
					case 2: // shooters case: only shoot when zombie in lane
						for (int k = 0; k < 50; k++) {
							if (factory.getZombie(k) != NULL) {
								if (factory.getZombie(k)->getExist() && plantFactory.getPlant(i,j)->getLane() == factory.getZombie(k)->getLane() && factory.getZombie(k)->getX_coordinate() < 1100) {
									plantFactory.getPlant(i,j)->Update(window);
								}
							}
						}
						break;
					case 3: // walnut case: roll then stop when zombie met
						for (int k = 0; k < 50; k++) {
							if (factory.getZombie(k) != NULL) {
								if (factory.getZombie(k)->getExist() && plantFactory.getPlant(i,j)->getLane() == factory.getZombie(k)->getLane() && factory.getZombie(k)->getX_coordinate() < 1100) {
									plantFactory.getPlant(i,j)->Update(window);
								}
							}
						}
						break;
					case 4: // cherrybomb case: BOOM
						plantFactory.getPlant(i,j)->Update(window);
						break;
					case 5: // repeater case:
						for (int k = 0; k < 50; k++) {
							if (factory.getZombie(k) != NULL) {
								if (factory.getZombie(k)->getExist() && plantFactory.getPlant(i,j)->getLane() == factory.getZombie(k)->getLane() && factory.getZombie(k)->getX_coordinate() < 1100) {
									plantFactory.getPlant(i,j)->Update(window);
								}
							}
						}
						break;
					case 6: // cherrybomb case: BOOM
						plantFactory.getPlant(i,j)->Update(window);
						break;
					}
				}
			}
		}
	}
}

bool Levels::CheckCollision(int p) {
	static sf::Clock clock; // Static clock to keep track of elapsed time
	static bool check = 1;
	
	/*if (!check)
	{
		return false;
	}*/
	// Check if 3 seconds have passed since the last call to DamagePlant
	/*if (clock.getElapsedTime().asSeconds() >= 3) 
	{*/
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {

				if (plantFactory.getPlant(i,j) != NULL && plantFactory.getPlant(i,j)->getType()==2  && plantFactory.getPlant(i,j)->getExist() && factory.getZombie(p)->getExist() && plantFactory.getPlant(i,j)->getBulletX(-1)> factory.getZombie(p)->getX_coordinate() && plantFactory.getPlant(i,j)->getLane() == factory.getZombie(p)->getLane())
				{
					factory.getZombie(p)->setHealth(factory.getZombie(p)->getHealth() - 1);
					std::cout<<"zombie health "<<factory.getZombie(p)->getHealth() << endl;
					plantFactory.getPlant(i,j)->setBulletExist(-1,0);
					return false;
				}

				if (plantFactory.getPlant(i,j) != NULL && plantFactory.getPlant(i,j)->getType() == 5 && plantFactory.getPlant(i,j)->getExist() && factory.getZombie(p)->getExist() && plantFactory.getPlant(i,j)->getBulletX(-1) > factory.getZombie(p)->getX_coordinate() && plantFactory.getPlant(i,j)->getLane() == factory.getZombie(p)->getLane())
				{
					factory.getZombie(p)->setHealth(factory.getZombie(p)->getHealth() - 1);
					std::cout << "zombie health " << factory.getZombie(p)->getHealth() << endl;
					factory.getZombie(p)->setStop(1);
					plantFactory.getPlant(i,j)->setBulletExist(-1, 0);
					return false;
				}

				if (plantFactory.getPlant(i,j) != NULL && plantFactory.getPlant(i,j)->getType() == 6 && plantFactory.getPlant(i,j)->getExist() && factory.getZombie(p)->getExist() && plantFactory.getPlant(i,j)->getLane() == factory.getZombie(p)->getLane() && factory.getZombie(p)->getX_coordinate()< plantFactory.getPlant(i,j)->getX_coordinate()+80 && factory.getZombie(p)->getX_coordinate() > plantFactory.getPlant(i, j)->getX_coordinate() -80)
				{
					factory.getZombie(p)->setHealth(0);
					factory.getZombie(p)->setExist(0);
					
					for (int k = 0; k < 50; k++)
					{
						if (factory.getZombie(k) != nullptr && (factory.getZombie(k)->getLane() == factory.getZombie(p)->getLane() || factory.getZombie(k)->getLane() == factory.getZombie(p)->getLane() + 1 || factory.getZombie(k)->getLane() == factory.getZombie(p)->getLane() - 1) && (factory.getZombie(k)->getX_coordinate() > factory.getZombie(p)->getX_coordinate() - 100 && factory.getZombie(k)->getX_coordinate() < factory.getZombie(p)->getX_coordinate() + 100))
						{
							factory.getZombie(k)->setHealth(0);
							factory.getZombie(k)->setExist(0);
						}
					}

					plantFactory.getPlant(i, j)->setExist(0);
					/*plantFactory.setPlant(i, j, 0);
					for (int i = 0; i < 5; i++)
					{
						for (int j = 0; j < 9; j++)
						{
							if (plantFactory.getPlant(i,j) != NULL && (plantFactory.getPlant(i,j)->getLane() == factory.getZombie(p)->getLane() || plantFactory.getPlant(i,j)->getLane() == factory.getZombie(p)->getLane()+1 || plantFactory.getPlant(i,j)->getLane() == factory.getZombie(p)->getLane()-1) )
							{
								plantFactory.setPlant(i, j, 0);
							}
						}
					}*/
					return false;

				}

				
				if (plantFactory.getPlant(i,j) != NULL && plantFactory.getPlant(i,j)->getType() == 3 && plantFactory.getPlant(i,j)->getExist() && factory.getZombie(p)->getExist() && plantFactory.getPlant(i,j)->getBulletX(0) > factory.getZombie(p)->getX_coordinate() && plantFactory.getPlant(i,j)->getLane() == factory.getZombie(p)->getLane())
				{
					factory.getZombie(p)->setHealth(factory.getZombie(p)->getHealth() - 2);
					std::cout << "zombie health " << factory.getZombie(p)->getHealth() << endl;
					plantFactory.getPlant(i,j)->setBulletExist(0, 0);
					return false;

				}

				if (plantFactory.getPlant(i,j) != NULL && plantFactory.getPlant(i,j)->getType() == 3 && plantFactory.getPlant(i,j)->getExist() && factory.getZombie(p)->getExist() && plantFactory.getPlant(i,j)->getBulletX(1) > factory.getZombie(p)->getX_coordinate() && plantFactory.getPlant(i,j)->getLane() == factory.getZombie(p)->getLane())
				{
					//factory.getZombie(p)->setHealth(factory.getZombie(p)->getHealth() - 1);
					std::cout << "zombie health " << factory.getZombie(p)->getHealth() << endl;
					plantFactory.getPlant(i,j)->setBulletExist(1, 0);
					return false;

				}

				if (plantFactory.getPlant(i,j) != NULL && plantFactory.getPlant(i,j)->getExist() == true && plantFactory.getPlant(i,j)->getType() != 3 && factory.getZombie(p)->getExist() && plantFactory.getPlant(i,j)->getBulletX(-1) > factory.getZombie(p)->getX_coordinate() && plantFactory.getPlant(i,j)->getLane() == factory.getZombie(p)->getLane())
				{
					factory.getZombie(p)->setHealth(factory.getZombie(p)->getHealth() - 1);
					std::cout << "zombie health " << factory.getZombie(p)->getHealth() << endl;
					plantFactory.getPlant(i,j)->setBulletExist(-1, 0);
					return false;
				}

				if (plantFactory.getPlant(i,j) != NULL && plantFactory.getPlant(i,j)->getExist() == true && factory.getZombie(p)!=nullptr && factory.getZombie(p)->getExist() && plantFactory.getPlant(i,j)->getLane() == factory.getZombie(p)->getLane() && plantFactory.getPlant(i,j)->getType()==3 && plantFactory.getPlant(i,j)->getX_coordinate()+50 > factory.getZombie(p)->getX_coordinate())
				{
					factory.getZombie(p)->setExist(0);
					for (int k = 0; k < 50; k++)
					{
						if (factory.getZombie(k) != nullptr && (factory.getZombie(k)->getLane() == factory.getZombie(p)->getLane() || factory.getZombie(k)->getLane() == factory.getZombie(p)->getLane() + 1 || factory.getZombie(k)->getLane() == factory.getZombie(p)->getLane() - 1) && (factory.getZombie(k)->getX_coordinate() > factory.getZombie(p)->getX_coordinate() - 100 && factory.getZombie(k)->getX_coordinate() < factory.getZombie(p)->getX_coordinate() + 100))
						{
							factory.getZombie(k)->setExist(0);
						}
					}
					plantFactory.getPlant(i,j)->setExist(0);
					return false;

				}

				if (plantFactory.getPlant(i,j) != NULL && factory.getZombie(p)!=NULL && plantFactory.getPlant(i,j)->getExist()==true && factory.getZombie(p)->getX_coordinate()< plantFactory.getPlant(i,j)->getX_coordinate() + 50  && factory.getZombie(p)->getX_coordinate() > plantFactory.getPlant(i,j)->getX_coordinate()  && plantFactory.getPlant(i,j)->getLane() == factory.getZombie(p)->getLane()) {
					std::cout << "Zombie " << p << " must stop!\n";
					if (clock.getElapsedTime().asSeconds() >= 2)
					{
						DamagePlant(i, j);
						clock.restart();
					}
					cout << plantFactory.getPlant(i,j)->getHealth() << endl;
					//if (plantFactory.getPlant(i,j)->getHealth()==0)
					//{
					//	
					//	check = false;
					//	//clock.restart();
					//}
					//clock.restart(); // Restart the clock
					return true;
				}
			}
		}
		return false;
	//}
	//return factory.getZombie(p)->getStop();
	
}
void Levels::printNotNullPlants()
{
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			if (plantFactory.getPlant(j,i) != NULL)
			{
				cout << "Plant is not Null at j = "<<j << "i = " << i << endl;
			}
		}
	}
}

int Levels::getPlantCount()
{
	return PlantCount;
}
void Levels::setPlantCount(int i)
{
	PlantCount = i;
}
	//for(int i=0; )