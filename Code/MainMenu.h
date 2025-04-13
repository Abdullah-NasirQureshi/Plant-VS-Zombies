#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H
#include "../OOP_Pro/Button.h"
#include<SFML/Graphics.hpp>


class MainMenu
{
	sf::Image button_image;
	Button* click[3];
	sf::Texture background_texture;
	sf::Sprite background_sprite;

public:
	MainMenu(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	bool MouseOnAnyButton(sf::RenderWindow& window, int i);
	void Highligh_Buttons(int i);
	void original_Buttons(int i);
};

#endif