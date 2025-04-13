#pragma once
#include "SFML/Graphics.hpp"

class LawnMower
{
	int X_Coordinate;
	int Y_Coordinate;
	bool exists;
	int lane;
	bool move;
	sf::Sprite LawnMower_sprite;
	sf::Texture LawnMower_texture;
	sf::Clock Mower_clock;

public:
	LawnMower();
	LawnMower(int x, int y, int i);
	void moveMower();
	void DrawMower(sf::RenderWindow& window);
	int getLane();
	void setXCoordinate(int x);
	int getXCoordinate() const;
	void setYCoordinate(int y);
	int getYCoordinate() const;
	void setExists(bool e);
	bool getExists() const;
	void setMove(bool e);
	bool getMove() const;
};

