#include "Instructions.h"

#include "../OOP_Pro/Menu.h"
#include<SFML/Graphics.hpp>
#include<iostream>



Instructions::Instructions(sf::RenderWindow& window)
{
	InstructionsButton_image.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\button.jpg");
	InstructionsBackground_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\Instructions.jpg");
	InstructionsBackground_sprite.setTexture(InstructionsBackground_texture);
	InstructionsBackground_sprite.setPosition(0, 0);
	InstructionsButtons = new Button(window, "PLAY NOW", 815, 560, 100, InstructionsButton_image);
}

void Instructions::drawInstructions(sf::RenderWindow& window)
{
	window.draw(InstructionsBackground_sprite);
	InstructionsButtons->Draw_button(window);
}

bool Instructions::MouseOnAnyButtonInstructions(sf::RenderWindow& window)
{
	if (InstructionsButtons->MouseInArea(window))
	{
		cout << "in" << endl;
		return true;
	}

	return false;
}

void Instructions::Highligh_ButtonsInstructions()
{
	InstructionsButtons->Highlight();
}

void Instructions::original_ButtonsInstructions()
{
	InstructionsButtons->Original();
}
