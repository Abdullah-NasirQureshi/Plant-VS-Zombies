#ifndef GAME_H
#define GAME_H
#pragma once
#include <SFML/Graphics.hpp>
#include "../OOP_Pro/ScoreBoard.h"
#include "../OOP_Pro/Levels.h"
class Game
{
	Inventory* playerInventory[6];
	Levels* level[6];
	Sunlight sun;
	int GameState; // 1 for Main page, 2 for Instruction page, and 3 for pause page and 4 for the game play 5 for levels
	int CurrentLevel;
	bool lifeCeck;
	ScoreBoard* SB;
	
public:
	Game();
	void SaveGame();
	void RetriveOldData(sf::RenderWindow& window);
	void createBack(sf::RenderWindow& window);
	~Game();
	//void MainMenu(sf::RenderWindow& window);

};
#endif


