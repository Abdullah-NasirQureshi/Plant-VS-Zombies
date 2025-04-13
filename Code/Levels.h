#pragma once
#include<SFML/Graphics.hpp>
#include "../OOP_Pro/Zombie.h"
#include "../OOP_Pro/Sunlight.h"
#include "../OOP_Pro/Inventory.h"
#include "../OOP_Pro/ZombieFactory.h"
#include "../OOP_Pro/PlantFactory.h"
#include "../OOP_Pro/Button.h"
#include "../OOP_Pro/LawnMower.h"

class Levels
{
protected:
	int currentlevel;
	sf::Image map_image; //background image
	sf::Texture map;
	sf::Sprite s_map;
	sf::Texture Sun_texture;
	sf::Sprite Sun_sprite;
	sf::Font font;
	sf::Text Sun_currency;
	sf::Text lev;
	Inventory* inventory;
	ZombieFactory factory;
	PlantFactory plantFactory;
	Sunlight* sun;
	sf::Image Button_image; // button image
	bool ZombieEnteredHouse;
	Button* button[3];
	LawnMower* Mowers[5];

public:
	
	PlantFactory getPlantFactory();
	int PlantCount=0;
	void setPlantFactory(PlantFactory p);
	ZombieFactory getZombieFactory();
	void createButton(sf::RenderWindow& window);
	virtual bool MouseOnAnyButton(sf::RenderWindow& window, int x)=0;
	virtual void Highligh_Buttons(int x)=0;
	virtual void original_Buttons(int x)=0;
	virtual void CreateZombies() = 0;
	virtual void moveZombies(sf::RenderWindow& window) = 0;
	virtual void DrawZombies(sf::RenderWindow& window) = 0;
	virtual bool PlacePlant(int selectedPlant, float mouseX, float mouseY);
	virtual void DrawPlants(sf::RenderWindow& window);
	void UpdatePlants(sf::RenderWindow& window);
	virtual void createBack(sf::RenderWindow& window) = 0;
	virtual bool LevelCompleted() = 0;
	virtual void DrawInventory(sf::RenderWindow& window) = 0;
	virtual void handleSuns(sf::RenderWindow& window, sf::Event event);
	virtual void handleMowers(sf::RenderWindow& window)=0;
	void InformationStrip(sf::RenderWindow& window, int lives, int score);
	void DamagePlant(int p, int q);
	bool CheckCollision(int p);   // Checks if units collide other units and p is the index of zombie being compared
	virtual void ManageInteractions(sf::RenderWindow& window) = 0;
	virtual bool getZombieEnteredHouse()=0;

	void printNotNullPlants();
	int getPlantCount();
	void setPlantCount(int p);


	//virtual void setupLevel(sf::RenderWindow& window);
};

