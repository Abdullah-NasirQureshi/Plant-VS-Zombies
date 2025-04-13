#pragma once
#include "SFML/Graphics.hpp"
#include "Item.h"
class Inventory
{
private:
	int currLevel;
	int X_position;
	int Y_position;
	Item* PlantSelection[6];
public:
	Inventory();
	Inventory(sf::RenderWindow& window, int currLevel);
	void draw(sf::RenderWindow& window);
	int MouseOnAnyItem(sf::RenderWindow& window);
	~Inventory();
};

