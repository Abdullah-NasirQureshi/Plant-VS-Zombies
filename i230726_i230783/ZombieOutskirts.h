#pragma once
#include "../OOP_Pro/Levels.h"
class ZombieOutskirts: public Levels
{
public:
	ZombieOutskirts();
	ZombieOutskirts(sf::RenderWindow& window);
	void CreateZombies();
	void DrawInventory(sf::RenderWindow& window);
	void moveZombies(sf::RenderWindow& window);
	void DrawZombies(sf::RenderWindow& window);
	virtual void createBack(sf::RenderWindow& window);
	virtual bool LevelCompleted();
	void handleSuns();

	virtual bool MouseOnAnyButton(sf::RenderWindow& window, int x);
	virtual void handleMowers(sf::RenderWindow& window);
	virtual void Highligh_Buttons(int x);
	void original_Buttons(int x);
	virtual void ManageInteractions(sf::RenderWindow& window);
	virtual bool getZombieEnteredHouse();
};

