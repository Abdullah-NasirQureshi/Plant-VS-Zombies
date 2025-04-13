#include "../OOP_Pro/MainMenu.h"
#include<SFML/Graphics.hpp>
#include<iostream>



MainMenu::MainMenu(sf::RenderWindow& window)
{
	button_image.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\button.jpg");
	background_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\mainPage.jpg");
	background_sprite.setTexture(background_texture);
	background_sprite.setPosition(0, 0);
	click[0] = new Button(window, "PLAY", 215, 180, 100, button_image);
	click[1] = new Button(window, "INSTRUCTIONS", 635, 180, 70, button_image);
	click[2] = new Button(window, "EXIT", 425, 350, 100, button_image);
}

void MainMenu::draw(sf::RenderWindow& window)
{
	window.draw(background_sprite);
	for (int i = 0; i < 3; i++)
	{
		click[i]->Draw_button(window);
	}
	
}

bool MainMenu::MouseOnAnyButton(sf::RenderWindow& window, int i)
{
	if (click[i]->MouseInArea(window))
	{
		cout << "in"<<endl;
		return true;
	}

	return false;
}

void MainMenu::Highligh_Buttons(int i)
{
	click[i]->Highlight();
}

void MainMenu::original_Buttons(int i)
{
	click[i]->Original();
}
