#pragma once
#include "../OOP_Pro/Levels.h"
//#include "../OOP_Pro/SimpleZombie.h"
//#include "../OOP_Pro/Zombie.h"
class BeginnersGarden: public Levels
{
	//Zombie* zombies[10];
public:
	BeginnersGarden();
	BeginnersGarden(sf::RenderWindow& window);
	void CreateZombies();
	void DrawInventory(sf::RenderWindow& window);
	void moveZombies(sf::RenderWindow& window);
	void DrawZombies(sf::RenderWindow& window);
	virtual void createBack(sf::RenderWindow& window);
	virtual bool LevelCompleted();
	void handleSuns();

	//sf::Image Button_image; // button image
	/*sf::Texture Button_texture;
	sf::Sprite Button_sprite;*/
	//Button* button;
	virtual void handleMowers(sf::RenderWindow& window);
	virtual bool MouseOnAnyButton(sf::RenderWindow& window, int x);
	virtual void Highligh_Buttons(int x);
	virtual void original_Buttons(int x);
	virtual void ManageInteractions(sf::RenderWindow& window);
	virtual bool getZombieEnteredHouse();
};

