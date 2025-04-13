#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H
#include "../OOP_Pro/Button.h"
#include<SFML/Graphics.hpp>


class Menu
{
	sf::Image Button_image;

	Button* mainMenuButtons[6];
	sf::Texture MainMenuBackground_texture;
	sf::Sprite MainMenuBackground_sprite;

	Button* InstructionsButtons[2];
	sf::Texture InstructionsBackground_texture;
	sf::Sprite InstructionsBackground_sprite;

	Button* PausePageButtons[3];
	sf::Texture PausePageBackground_texture;
	sf::Sprite PausePageBackground_sprite;

	Button* LevelsButtons[7];
	sf::Texture LevelsBackground_texture;
	sf::Sprite LevelsBackground_sprite;

	sf::Texture ScoreBoardBackground_texture;
	sf::Sprite ScoreBoardBackground_sprite;

public:
	Menu(sf::RenderWindow& window);

	void drawMainMenu(sf::RenderWindow& window);
	bool MouseOnAnyButtonMainMenu(sf::RenderWindow& window, int i);
	void Highligh_ButtonsMainMenu(int i);
	void original_ButtonsMainMenu(int i);

	void drawInstructions(sf::RenderWindow& window);
	bool MouseOnAnyButtonInstructions(sf::RenderWindow& window, int i);
	void Highligh_ButtonsInstructions(int i);
	void original_ButtonsInstructions(int i);

	void drawPausePage(sf::RenderWindow& window);
	bool MouseOnAnyButtonPausePage(sf::RenderWindow& window, int i);
	void Highligh_ButtonsPausePage(int i);
	void original_ButtonsPausePage(int i);

	void drawLevels(sf::RenderWindow& window);
	bool MouseOnAnyButtonLevels(sf::RenderWindow& window, int i);
	void Highligh_ButtonsLevels(int i);
	void original_ButtonsLevels(int i);

	void drawScoreBoard(sf::RenderWindow& window);


};


#endif