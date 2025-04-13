#pragma once
#include <SFML/Graphics.hpp>
class Plant
{
protected:
	int X_coordinate;
	int Y_coordinate;
	int lane;
	bool Exist;
	int Type;
	int Health;
	sf::Sprite Plant_sprite;
	sf::Texture Plant_texture;
	sf::Clock Plant_clock;

public:
	// Setters
	void setX_coordinate(int x);

	void setY_coordinate(int y);

	void setExist(bool exist);

	void setHealth(int health);

	void setLane(int aLane);

	// Getters
	int getX_coordinate() const;

	int getY_coordinate() const;

	int getLane() const;

	int getType() const;

	bool getExist() const;

	int getHealth() const;

	void DrawPlant(sf::RenderWindow& window);

	virtual bool interact(sf::RenderWindow& window);

	virtual void Update(sf::RenderWindow& window) = 0;

	virtual int getBulletX(int x) { return 0; }

	virtual void setBulletExist(int x, bool s) {};

	void receiveDamage(int);

	bool checkHealth();  // checks for health and sets existance to false if health == 0

	void setType(int x)
	{
		Type = x;
	}

	//virtual void draw() = 0;  // draws the sprite
};

