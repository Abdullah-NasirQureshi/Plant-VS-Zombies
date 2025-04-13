#pragma once
#include<SFML/Graphics.hpp>
class Sunlight
{
	int X_coordinate;
	int Y_coordinate;
	int RandomLanding;
	bool Exist;
	//sf::Event click;
	sf::Clock Sun_clock;
	sf::Texture Sun_texture;
	sf::Sprite Sun_sprite;


public:
	static int currency;

	Sunlight();
	Sunlight(int x, int y);

    // Setters
	void setXCoordinate(int x);
    void setYCoordinate(int y);
    void setRandomLanding(int random);
    void setExist(bool exist);
    static void setCurrency(int cur);

    // Getters
    int getXCoordinate() const;
    int getYCoordinate() const;
    int getRandomLanding() const;

    bool doesExist() const;
    static int getCurrency();
	void dropSun();
	void drawSun(sf::RenderWindow& window);
	bool mouseOverSun(sf::RenderWindow& window);
	void UpdateCurrency(sf::RenderWindow& window, sf::Event event);
};

