#include<iostream>
#include<fstream>
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include "../OOP_Pro/Button.h"
#include "../OOP_Pro/Menu.h"
#include "../OOP_Pro/Instructions.h"
#include "../OOP_Pro/SimpleZombie.h"

#include "../OOP_Pro/BeginnersGarden.h"
#include "../OOP_Pro/ZombieOutskirts.h"
#include "../OOP_Pro/SunflowerField.h"
#include "../OOP_Pro/Sunflower.h"
#include "../OOP_Pro/PeaShooter.h"
#include "../OOP_Pro/Repeater.h"
#include "../OOP_Pro/SnowPea.h"
#include "../OOP_Pro/CherryBomb.h"
#include "../OOP_Pro/Walnut.h"



using namespace sf;
using namespace std;


//Drawing the background
//Drawing the background
void Game::createBack(RenderWindow& window) {
	//Drawing the background
	Image map_image;
	map_image.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\f.jpeg");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	//map_image.s);
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	//  each box is 80 by 100
	//the grid starts from 250, 80
	window.draw(s_map);
}

void Game::SaveGame()
{
	ofstream savedGame;
	savedGame.open("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\TheSavedGame.txt");
	//cout << "In the file\n";

	savedGame << GameState << endl;
	savedGame << CurrentLevel << endl;
	savedGame<<	level[CurrentLevel - 1]->getPlantCount() << endl;
	/*savedGame<<	SB->getLives();
	savedGame<<	SB->getScore();*/

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (level[CurrentLevel-1]->getPlantFactory().getPlant(i,j) != NULL)
			{
				cout << "Plant is not null\n";
				savedGame << i <<" " << j <<" " << level[CurrentLevel - 1]->getPlantFactory().getPlant(i,j)->getType()<<" "<< level[CurrentLevel - 1]->getPlantFactory().getPlant(i,j)->getX_coordinate() << " " << level[CurrentLevel - 1]->getPlantFactory().getPlant(i,j)->getY_coordinate() << " " << level[CurrentLevel - 1]->getPlantFactory().getPlant(i,j)->getLane() << " " << level[CurrentLevel - 1]->getPlantFactory().getPlant(i,j)->getHealth() << " " << endl;
			}
		}
	}

	for (int i = 0; i < 50; i++)
	{
		if (level[CurrentLevel - 1]->getZombieFactory().getZombie(i) != NULL)
		{
			savedGame << level[CurrentLevel - 1]->getZombieFactory().getZombie(i)->getX_coordinate() <<" "<< level[CurrentLevel - 1]->getZombieFactory().getZombie(i)->getY_coordinate() << " " << level[CurrentLevel - 1]->getZombieFactory().getZombie(i)->getLane() << " " << level[CurrentLevel - 1]->getZombieFactory().getZombie(i)->getExist() << " " << level[CurrentLevel - 1]->getZombieFactory().getZombie(i)->getHealth() << endl;
		}
	}
	savedGame.close();
}
void Game::RetriveOldData(sf::RenderWindow& window)
{
	ifstream savedGame;
	savedGame.open("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\TheSavedGame.txt");
	cout << "In the file\n";

	savedGame >> GameState;
	savedGame >> CurrentLevel;
	int plantnum;
	savedGame >> plantnum;
	cout << "Number of plants : " << plantnum << endl;
	level[CurrentLevel - 1]->setPlantCount(plantnum);
	/*if (CurrentLevel == 1)
		level[0] = new BeginnersGarden(window);*/
	PlantFactory plantFactory = level[CurrentLevel - 1]->getPlantFactory();
	for (int i = 0; i < plantnum; i++)
	{

		int gridY, gridX, type, x, y, lane, healthh;
		savedGame >> gridY >> gridX >> type >> x >> y >> lane >> healthh;
		cout << gridY << " " << gridX << " " << type << " " << x << " " << y << " " << lane << endl;

		if (type == 1)
		{
			Sunflower* newSunflower = new Sunflower(250 + gridX * 80, 80 + gridY * 100, gridY);

			// Check if the new Sunflower object is not null
			if (newSunflower != nullptr)
			{
				// Assign the new Sunflower object to the specified position in the plants array
				 // Get reference to the PlantFactory
				if (&plantFactory != nullptr) // Check if plantFactory is not null
				{
					plantFactory.setPlant(gridY, gridX, 1); // Assign newSunflower to the plants array
					// Update the PlantFactory in the Level object
				}
				else
				{
					cout << "PlantFactory pointer is NULL\n";
				}
			}
			else
			{
				// Print a message indicating failure to create the Sunflower object
				cout << "Failed to create Sunflower object. Memory allocation failed.\n";
			}
		}

		if (type == 2)
		{
			PeaShooter* newplant = new PeaShooter(250 + gridX * 80, 80 + gridY * 100, gridY);

			// Check if the new Sunflower object is not null
			if (newplant != nullptr)
			{
				// Assign the new Sunflower object to the specified position in the plants array
				 // Get reference to the PlantFactory
				if (&plantFactory != nullptr) // Check if plantFactory is not null
				{
					plantFactory.setPlant(gridY, gridX, 2); // Assign newSunflower to the plants array
					// Update the PlantFactory in the Level object
				}
				else
				{
					cout << "PlantFactory pointer is NULL\n";
				}
			}
			else
			{
				// Print a message indicating failure to create the Sunflower object
				cout << "Failed to create Sunflower object. Memory allocation failed.\n";
			}
		}

		if (type == 3)
		{
			Repeater* newplant = new Repeater(250 + gridX * 80, 80 + gridY * 100, gridY);

			// Check if the new Sunflower object is not null
			if (newplant != nullptr)
			{
				// Assign the new Sunflower object to the specified position in the plants array
				 // Get reference to the PlantFactory
				if (&plantFactory != nullptr) // Check if plantFactory is not null
				{
					plantFactory.setPlant(gridY, gridX, 3); // Assign newSunflower to the plants array
					// Update the PlantFactory in the Level object
				}
				else
				{
					cout << "PlantFactory pointer is NULL\n";
				}
			}
			else
			{
				// Print a message indicating failure to create the Sunflower object
				cout << "Failed to create Sunflower object. Memory allocation failed.\n";
			}
		}

		if (type == 4)
		{
			Walnut* newplant = new Walnut(250 + gridX * 80, 80 + gridY * 100, gridY);

			// Check if the new Sunflower object is not null
			if (newplant != nullptr)
			{
				// Assign the new Sunflower object to the specified position in the plants array
				 // Get reference to the PlantFactory
				if (&plantFactory != nullptr) // Check if plantFactory is not null
				{
					plantFactory.setPlant(gridY, gridX, 4); // Assign newSunflower to the plants array
					// Update the PlantFactory in the Level object
				}
				else
				{
					cout << "PlantFactory pointer is NULL\n";
				}
			}
			else
			{
				// Print a message indicating failure to create the Sunflower object
				cout << "Failed to create Sunflower object. Memory allocation failed.\n";
			}
		}

		if (type == 5)
		{
			SnowPea* newplant = new SnowPea(250 + gridX * 80, 80 + gridY * 100, gridY);

			// Check if the new Sunflower object is not null
			if (newplant != nullptr)
			{
				// Assign the new Sunflower object to the specified position in the plants array
				 // Get reference to the PlantFactory
				if (&plantFactory != nullptr) // Check if plantFactory is not null
				{
					plantFactory.setPlant(gridY, gridX, 5); // Assign newSunflower to the plants array
					// Update the PlantFactory in the Level object
				}
				else
				{
					cout << "PlantFactory pointer is NULL\n";
				}
			}
			else
			{
				// Print a message indicating failure to create the Sunflower object
				cout << "Failed to create Sunflower object. Memory allocation failed.\n";
			}
		}

		if (type == 6)
		{
			CherryBomb* newplant = new CherryBomb(250 + gridX * 80, 80 + gridY * 100, gridY);

			// Check if the new Sunflower object is not null
			if (newplant != nullptr)
			{
				// Assign the new Sunflower object to the specified position in the plants array
				 // Get reference to the PlantFactory
				if (&plantFactory != nullptr) // Check if plantFactory is not null
				{
					plantFactory.setPlant(gridY, gridX, 6); // Assign newSunflower to the plants array
					// Update the PlantFactory in the Level object
				}
				else
				{
					cout << "PlantFactory pointer is NULL\n";
				}
			}
			else
			{
				// Print a message indicating failure to create the Sunflower object
				cout << "Failed to create Sunflower object. Memory allocation failed.\n";
			}
		}
	}

	level[CurrentLevel - 1]->setPlantFactory(plantFactory);
	cout << "Not Null Plants\n";
	level[CurrentLevel - 1]->printNotNullPlants();
	cout << "\n\n\n";


	int  xx, yy, llane, health;
	bool exist;
	//if (CurrentLevel == 1)
	{
		for (int i = 0; i < 50; i++)
		{
			if (level[CurrentLevel - 1]->getZombieFactory().getZombie(i) != NULL)
			{
				savedGame >> xx >> yy >> llane >> exist >> health;
				cout << xx << " " << yy << " " << llane << " " << exist << " " << health << endl;
				level[CurrentLevel - 1]->getZombieFactory().getZombie(i)->setX_coordinate(xx);
				level[CurrentLevel - 1]->getZombieFactory().getZombie(i)->setY_coordinate(yy);
				level[CurrentLevel - 1]->getZombieFactory().getZombie(i)->setLane(llane);
				level[CurrentLevel - 1]->getZombieFactory().getZombie(i)->setExist(exist);
				level[CurrentLevel - 1]->getZombieFactory().getZombie(i)->setHealth(health);

			}

		}
	}


}


Game::Game() {


	

	GameState = 1;
	CurrentLevel = 1;
	lifeCeck = false;
	SB = new ScoreBoard;
	//Create a window, n*n
	sf::RenderWindow window(sf::VideoMode(1200, 700), "Plants Vs Zombies");

	level[0] = new BeginnersGarden(window);
	level[0]->CreateZombies();
	//cout << "Code 0" << endl;

	level[1] = new ZombieOutskirts(window);
	level[1]->CreateZombies();
	//cout << "Code 1" << endl;
	
	level[2] = new SunflowerField(window);
	level[2]->CreateZombies();
	//Game icon
	sf::Image icon;
	if (!icon.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\icon.png"))
	{
		return;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	
	///////////////////////////////////////

	//Game field (5*9)
	//Point 137*79 - leftmost point
	//length 41; width 53
	const int ROWS = 5;
	const int COLS = 9;

	bool FIELD_GAME_STATUS[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			FIELD_GAME_STATUS[i][j] = true;
		}
	}

	//Clock timeMoney;


	srand(time(0));
	Clock clock;

	//Inventory
	
	playerInventory[0] = new Inventory(window, 1);
	playerInventory[1] = new Inventory(window, 2);
	playerInventory[2] = new Inventory(window, 3);
	bool isDragging = false;
	int selectedPlant = 0;
	int cost = 0;

	//Menus
	Menu MM(window);
	//Instructions Ins(window);
	

	//playerInventory[0] = new Inventory(window, 1);
	//playerInventory[1] = new Inventory(window, 2);

	//bool isDragging = false;
	//int selectedPlant = -1;
	
	
	//cout << "Code 2" << endl;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMilliseconds();
		//float moneyTime = timeMoney.getElapsedTime().asSeconds();

		if (time < 16.6667)
		{
			continue;
		}

		clock.restart();
		//time = time / 800;

		Event event;

		while (window.pollEvent(event))
		{
			
			switch (event.type)
			{
			case (sf::Event::Closed) :
				window.close();
				break;

			case (sf::Event::MouseMoved):
				for (int i = 0; i < 6; i++)
				{
					if (MM.MouseOnAnyButtonMainMenu(window, i))
					{
						MM.Highligh_ButtonsMainMenu(i);
					}
					if(!MM.MouseOnAnyButtonMainMenu(window, i))
						MM.original_ButtonsMainMenu(i);

					
				}

				for (int i = 0; i < 7; i++)
				{
					if (MM.MouseOnAnyButtonLevels(window, i))
						MM.Highligh_ButtonsLevels(i);
					if (!MM.MouseOnAnyButtonLevels(window, i))
						MM.original_ButtonsLevels(i);

				}

				for (int i = 0; i < 3; i++)
				{
					if (MM.MouseOnAnyButtonPausePage(window, i))
					{
						MM.Highligh_ButtonsPausePage(i);
					}
					if (!MM.MouseOnAnyButtonPausePage(window, i))
						MM.original_ButtonsPausePage(i);
				}
				for (int i = 0; i < 2; i++)
				{
					if (MM.MouseOnAnyButtonInstructions(window,i))
						MM.Highligh_ButtonsInstructions(i);

					if (!MM.MouseOnAnyButtonInstructions(window,i))
						MM.original_ButtonsInstructions(i);
					if (level[CurrentLevel - 1]->MouseOnAnyButton(window,i))
						level[CurrentLevel - 1]->Highligh_Buttons(i);
					if (!level[CurrentLevel - 1]->MouseOnAnyButton(window,i))
						level[CurrentLevel - 1]->original_Buttons(i);
				}

				

				//playerInventory[0]->MouseOnAnyItem(window);
				break;

			case (sf::Event::MouseButtonPressed):
				if (MM.MouseOnAnyButtonMainMenu(window, 0) && GameState ==1)
				{
					GameState = 4;
				}
				else if (MM.MouseOnAnyButtonMainMenu(window, 1) && GameState == 1)
				{
					cout << "In the old game!\n";
					RetriveOldData(window);
					
				}
				else if (MM.MouseOnAnyButtonMainMenu(window, 2) && GameState == 1)
				{
					GameState = 2;
				}
				else if (MM.MouseOnAnyButtonMainMenu(window, 3) && GameState == 1)
				{
					cout << "in the game state 5\n";
					GameState = 5;
					//window.close();
				}
				else if (MM.MouseOnAnyButtonMainMenu(window, 4) && GameState == 1)
				{
					GameState = 4;
					//window.close();
				}
				else if (MM.MouseOnAnyButtonMainMenu(window, 5) && GameState == 1)
				{
					window.close();
				}
				else if (MM.MouseOnAnyButtonInstructions(window, 0) && GameState == 2)
				{
					GameState = 3;
				}
				else if (MM.MouseOnAnyButtonInstructions(window, 1) && GameState == 2)
				{
					GameState = 4;
				}
				else if (MM.MouseOnAnyButtonPausePage(window, 0) && GameState == 3)
				{
					GameState = 4;
				}
				else if (MM.MouseOnAnyButtonPausePage(window, 1) && GameState == 3)
				{
					GameState = 2;
				}
				else if (MM.MouseOnAnyButtonPausePage(window, 2) && GameState == 3)
				{
					GameState = 1;
				}
				else if (MM.MouseOnAnyButtonLevels(window, 0) && GameState == 5)
				{
					CurrentLevel = 1;
					GameState = 4;
				}
				else if (MM.MouseOnAnyButtonLevels(window, 1) && GameState == 5)
				{
					CurrentLevel = 2;
					GameState = 4;
				}
				else if (MM.MouseOnAnyButtonLevels(window, 2) && GameState == 5)
				{
					CurrentLevel = 3;
					GameState = 4;
				}
				else if (MM.MouseOnAnyButtonLevels(window, 3) && GameState == 5)
				{
					CurrentLevel = 4;
					GameState = 4;
				}
				else if (MM.MouseOnAnyButtonLevels(window, 4) && GameState == 5)
				{
					CurrentLevel = 5;
					GameState = 4;
				}
				else if (MM.MouseOnAnyButtonLevels(window, 5) && GameState == 5)
				{
					CurrentLevel = 6;
					GameState = 4;
				}
				else if (MM.MouseOnAnyButtonLevels(window, 6) && GameState == 5)
				{
					GameState = 1;
				}
				else if (GameState == 4 && level[CurrentLevel - 1]->MouseOnAnyButton(window,0))
				{
					GameState = 3;
				}
				else if (GameState == 4 && level[CurrentLevel - 1]->MouseOnAnyButton(window, 1))
				{
					SaveGame();
					window.close();
				}


				/*if (playerInventory[0]->MouseOnAnyItem(window)) {
					cout << "Dragging!\n\n";
					isDragging = true;
				}*/
			/*	if (playerInventory[1]->MouseOnAnyItem(window)) {
					isDragging = true;
				}*/
				break;

			//case (sf::Event::MouseButtonReleased):
			//	if (isDragging) {
			//		isDragging = false;
			//		//level[0].placePlant(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
			//	}

			}
			
		}


		if (GameState == 1)
			MM.drawMainMenu(window);
		else if (GameState == 2)
			MM.drawInstructions(window);
		else if (GameState == 3)
			MM.drawPausePage(window);
		else if(GameState == 5)
			MM.drawLevels(window);
		else if (GameState == 4)
		{
			switch (CurrentLevel)
			{
			case 1:
				level[0]->createBack(window);
				playerInventory[0]->draw(window);
				level[0]->handleMowers(window);
				level[0]->DrawZombies(window);
				level[0]->DrawPlants(window);
				level[0]->UpdatePlants(window);
				level[0]->moveZombies(window);
				level[0]->ManageInteractions(window);
				sun.drawSun(window);
				sun.dropSun();
				sun.UpdateCurrency(window, event);
				//std::cout << sun.getCurrency() << endl;
				level[0]->InformationStrip(window, SB->getLives(), SB->getScore());

				//Checking and updating zombie invasions
				if (level[0]->getZombieEnteredHouse() && SB->getLives() != 2)
				{
					SB->setLives(SB->getLives() - 1);
				}

				// placing plants
				if (!isDragging) {
					selectedPlant = playerInventory[0]->MouseOnAnyItem(window);
					if (selectedPlant) {
						switch (selectedPlant) {
						case 1: //sunflower
							cost = 100;
							break;
						case 2: //peaShooter
							cost = 100;
							break;
						case 3: //walnut
							cost = 50;
							break;
						case 4: //cherrybomb
							cost = 150;
							break;
						case 5: //snowpea
							cost = 175;
							break;
						case 6: //repeater
							cost = 200;
							break;
						}
						if (cost <= sun.getCurrency()) {
							window.pollEvent(event);
							switch (event.type) {
							case (sf::Event::MouseButtonPressed):
								std::cout << "Plant Selected" << endl;
								isDragging = true;
								break;
							case (sf::Event::Closed):
								window.close();
								break;
							}
						}
					}
				}
				else {
					window.pollEvent(event);
					if (event.type == sf::Event::MouseButtonReleased) {

						isDragging = false;
						//place plant
						if (level[0]->PlacePlant(selectedPlant, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
							sun.setCurrency(sun.getCurrency() - cost);
							cost = 0;
						}
						level[0]->printNotNullPlants();
						selectedPlant = 0;
					}
				}


				if (level[0]->LevelCompleted())
				{
					//cout << "level completeld...................\n";
					CurrentLevel++;
				}

				/*if (event.type == sf::Event::MouseMoved)
				{
					if (level[0]->MouseOnAnyButton(window))
						level[0]->Highligh_Buttons();

					if (!level[0]->MouseOnAnyButton(window))
						level[0]->original_Buttons();
				}*/
				break;



			case 2:
				level[1]->createBack(window);
				playerInventory[1]->draw(window);
				level[1]->handleMowers(window);
				level[1]->DrawZombies(window);
				level[1]->DrawPlants(window);
				level[1]->UpdatePlants(window);
				level[1]->moveZombies(window);
				level[1]->ManageInteractions(window);
				sun.drawSun(window);
				sun.dropSun();
				sun.UpdateCurrency(window, event);
				//std::cout << sun.getCurrency() << endl;
				level[1]->InformationStrip(window, SB->getLives(), SB->getScore());


				//Checking and updating zombie invasions
				if (level[1]->getZombieEnteredHouse() && SB->getLives() != 1)
					SB->setLives(SB->getLives() - 1);
				//cout << "Lives:" << SB->getLives() << endl;

				// placing plants
				if (!isDragging) {
					selectedPlant = playerInventory[1]->MouseOnAnyItem(window);
					if (selectedPlant) {
						switch (selectedPlant) {
						case 1: //sunflower
							cost = 50;
							break;
						case 2: //peaShooter
							cost = 100;
							break;
						case 3: //walnut
							cost = 50;
							break;
						case 4: //cherrybomb
							cost = 150;
							break;
						case 5: //snowpea
							cost = 175;
							break;
						case 6: //repeater
							cost = 200;
							break;
						}
						if (cost <= sun.getCurrency()) {
							window.pollEvent(event);
							switch (event.type) {
							case (sf::Event::MouseButtonPressed):
								std::cout << "Plant Selected" << endl;
								isDragging = true;
								break;
							case (sf::Event::Closed):
								window.close();
								break;
							}
						}
					}
				}
				else {
					window.pollEvent(event);
					if (event.type == sf::Event::MouseButtonReleased) {

						isDragging = false;
						//place plant
						if (level[1]->PlacePlant(selectedPlant, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
							sun.setCurrency(sun.getCurrency() - cost);
							cost = 0;
						}

						selectedPlant = 0;
					}
				}

				/*if (level[1]->LevelCompleted())
					CurrentLevel++;*/
				break;



			case 3:
				level[2]->createBack(window);
				playerInventory[2]->draw(window);
				level[2]->handleMowers(window);
				level[2]->DrawZombies(window);
				level[2]->DrawPlants(window);
				level[2]->UpdatePlants(window);
				level[2]->moveZombies(window);
				level[2]->ManageInteractions(window);
				sun.drawSun(window);
				sun.dropSun();
				sun.UpdateCurrency(window, event);
				//std::cout << sun.getCurrency() << endl;
				level[2]->InformationStrip(window, SB->getLives(), SB->getScore());

				//Checking and updating zombie invasions
				if (level[2]->getZombieEnteredHouse() && SB->getLives() != 1)
				{
					SB->setLives(SB->getLives() - 1);
				}

				// placing plants
				if (!isDragging) {
					selectedPlant = playerInventory[2]->MouseOnAnyItem(window);
					if (selectedPlant) {
						switch (selectedPlant) {
						case 1: //sunflower
							cost = 50;
							break;
						case 2: //peaShooter
							cost = 100;
							break;
						case 3: //walnut
							cost = 50;
							break;
						case 4: //cherrybomb
							cost = 150;
							break;
						case 5: //snowpea
							cost = 175;
							break;
						case 6: //repeater
							cost = 200;
							break;
						}
						if (cost <= sun.getCurrency()) {
							window.pollEvent(event);
							switch (event.type) {
							case (sf::Event::MouseButtonPressed):
								std::cout << "Plant Selected" << endl;
								isDragging = true;
								break;
							case (sf::Event::Closed):
								window.close();
								break;
							}
						}
					}
				}
				else {
					window.pollEvent(event);
					if (event.type == sf::Event::MouseButtonReleased) {

						isDragging = false;
						//place plant
						if (level[2]->PlacePlant(selectedPlant, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
							sun.setCurrency(sun.getCurrency() - cost);
							cost = 0;
						}
						level[2]->printNotNullPlants();
						selectedPlant = 0;
					}
				}


				if (level[2]->LevelCompleted())
				{
					//cout << "level completeld...................\n";
					CurrentLevel++;
				}

				/*if (event.type == sf::Event::MouseMoved)
				{
					if (level[0]->MouseOnAnyButton(window))
						level[0]->Highligh_Buttons();

					if (!level[0]->MouseOnAnyButton(window))
						level[0]->original_Buttons();
				}*/
				break;

				/*for (int i = 0; i < 10; i++)
				{
					Z[i]->DrawZombie(window);
					Z[i]->moveZombie();
				}*/
				//A.DrawZombie(window);
				//A.moveZombie();
			}
		}

	
		window.setSize(sf::Vector2u(1366, 768));
		window.display();
		window.clear();
	}
}

Game::~Game()
{
	
}

