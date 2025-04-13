#include "../OOP_Pro/Menu.h"
#include<SFML/Graphics.hpp>
#include<iostream>



Menu::Menu(sf::RenderWindow& window)
{
	Button_image.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\button.jpg");
	MainMenuBackground_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\mainPage.jpg");
	MainMenuBackground_sprite.setTexture(MainMenuBackground_texture);
	MainMenuBackground_sprite.setPosition(0, 0);
	mainMenuButtons[0] = new Button(window, "NEW GAME", 215, 80, 90, Button_image);
	mainMenuButtons[1] = new Button(window, "SAVED GAME", 635, 80, 80, Button_image);
	mainMenuButtons[2] = new Button(window, "INSTRUCTIONS", 215, 250, 70, Button_image);
	mainMenuButtons[3] = new Button(window, "LEVELS", 635, 250, 90, Button_image);
	mainMenuButtons[4] = new Button(window, "SCOREBOARD", 215, 420, 70, Button_image);
	mainMenuButtons[5] = new Button(window, "EXIT", 635, 420, 100, Button_image);

	
	InstructionsBackground_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\Instructions.jpg");
	InstructionsBackground_sprite.setTexture(InstructionsBackground_texture);
	InstructionsBackground_sprite.setPosition(0, 0);
	InstructionsButtons[0] = new Button(window, "BACK", 30, 560, 100, Button_image);
	InstructionsButtons[1] = new Button(window, "GO TO GAME", 815, 560, 80, Button_image);
	
	PausePageBackground_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\gg.png");
	PausePageBackground_sprite.setTexture(InstructionsBackground_texture);
	PausePageBackground_sprite.setPosition(0, 0);
	PausePageButtons[0] = new Button(window, "RESUME", 420, 150, 80, Button_image);
	PausePageButtons[1] = new Button(window, "INSTRUCTIONS", 420, 300, 75, Button_image);
	PausePageButtons[2] = new Button(window, "MAIN MENU", 420, 450, 90, Button_image);

	LevelsBackground_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\gg.png");
	LevelsBackground_sprite.setTexture(LevelsBackground_texture);
	LevelsBackground_sprite.setPosition(0, 0);
	LevelsButtons[0] = new Button(window, "LEVEL 1", 215, 80, 80, Button_image);
	LevelsButtons[1] = new Button(window, "LEVEL 2", 635, 80, 80, Button_image);
	LevelsButtons[2] = new Button(window, "LEVEL 3", 215, 250, 80, Button_image);
	LevelsButtons[3] = new Button(window, "LEVEL 4", 635, 250, 80, Button_image);
	LevelsButtons[4] = new Button(window, "LEVEL 5", 215, 420, 80, Button_image);
	LevelsButtons[5] = new Button(window, "LEVEL 6", 635, 420, 80, Button_image);
	LevelsButtons[6] = new Button(window, "BACK", 425, 590, 90, Button_image);

	ScoreBoardBackground_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\gg.png");
	ScoreBoardBackground_sprite.setTexture(ScoreBoardBackground_texture);
		
}

void Menu::drawMainMenu(sf::RenderWindow& window)
{
	window.draw(MainMenuBackground_sprite);
	for (int i = 0; i < 6; i++)
	{
		mainMenuButtons[i]->Draw_button(window);
	}
	
}

bool Menu::MouseOnAnyButtonMainMenu(sf::RenderWindow& window, int i)
{
	if (mainMenuButtons[i]->MouseInArea(window))
	{
		//cout << "in"<<endl;
		return true;
	}
	return false;
}

void Menu::Highligh_ButtonsMainMenu(int i)
{
	mainMenuButtons[i]->Highlight();
}

void Menu::original_ButtonsMainMenu(int i)
{
	mainMenuButtons[i]->Original();
}



void Menu::drawInstructions(sf::RenderWindow& window)
{
	window.draw(InstructionsBackground_sprite);
	InstructionsButtons[0]->Draw_button(window);
	InstructionsButtons[1]->Draw_button(window);
}

bool Menu::MouseOnAnyButtonInstructions(sf::RenderWindow& window, int i)
{
	if (InstructionsButtons[i]->MouseInArea(window))
	{
		//cout << "in" << endl;
		return true;
	}

	return false;
}

void Menu::Highligh_ButtonsInstructions(int i)
{
	InstructionsButtons[i]->Highlight();
}

void Menu::original_ButtonsInstructions(int i)
{
	InstructionsButtons[i]->Original();
}



void Menu::drawPausePage(sf::RenderWindow& window)
{
	window.draw(PausePageBackground_sprite);
	PausePageButtons[0]->Draw_button(window);
	PausePageButtons[1]->Draw_button(window);
	PausePageButtons[2]->Draw_button(window);
}

bool Menu::MouseOnAnyButtonPausePage(sf::RenderWindow& window, int i)
{
	if (PausePageButtons[i]->MouseInArea(window))
	{
		//cout << "in" << endl;
		return true;
	}

	return false;
}

void Menu::Highligh_ButtonsPausePage(int i)
{
	PausePageButtons[i]->Highlight();
}

void Menu::original_ButtonsPausePage(int i)
{
	PausePageButtons[i]->Original();
}


void Menu::drawLevels(sf::RenderWindow& window)
{
	window.draw(LevelsBackground_sprite);
	for (int i = 0; i < 7; i++)
	{
		LevelsButtons[i]->Draw_button(window);
	}
}

bool Menu::MouseOnAnyButtonLevels(sf::RenderWindow& window, int i)
{
	if (LevelsButtons[i]->MouseInArea(window))
	{
		//cout << "in" << endl;
		return true;
	}
	return false;
}

void Menu::Highligh_ButtonsLevels(int i)
{
	LevelsButtons[i]->Highlight();
}

void Menu::original_ButtonsLevels(int i)
{
	LevelsButtons[i]->Original();
}