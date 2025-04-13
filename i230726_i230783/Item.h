#pragma once
#include "SFML/graphics.hpp"

class Item
{
private:
	sf::Sprite item_sprite;
	sf::Texture item_texture;
	int X_position;
	int Y_position;
public:
	Item();
	Item(sf::RenderWindow& window, int X_position, int Y_position, const sf::Image& image);
	bool MouseInArea(sf::RenderWindow& window);
	int getX_position() const;
	int getY_position() const;

	void setX_position(int x);
	void setY_position(int y);

	void Draw_item(sf::RenderWindow& window);
};

