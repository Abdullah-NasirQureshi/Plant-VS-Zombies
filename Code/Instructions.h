#pragma once
#include "../OOP_Pro/Button.h"

class Instructions
{
	sf::Image InstructionsButton_image;
	Button* InstructionsButtons;
	sf::Texture InstructionsBackground_texture;
	sf::Sprite InstructionsBackground_sprite;

public:
	Instructions(sf::RenderWindow& window);
	void drawInstructions(sf::RenderWindow& window);
	bool MouseOnAnyButtonInstructions(sf::RenderWindow& window);
	void Highligh_ButtonsInstructions();
	void original_ButtonsInstructions();
};

