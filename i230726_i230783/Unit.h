#pragma once
#include <SFML/Graphics.hpp>

class Unit
{
	int X_coordinate;
	int Y_coordinate; 
	bool Exist;
	int Health;
	bool isColliding;  
	sf::Sprite Sprite;

public:
    // Constructors
    Unit();
	Unit(int, int, bool);

    // Setters
    void setX_coordinate(int x);
    void setY_coordinate(int y);
    void setExist(bool exist);
    void setHealth(int health);
    void setIsColliding(bool colliding);

    // Getters
    int getX_coordinate() const;
    int getY_coordinate() const;
    bool getExist() const;
    int getHealth() const;
    bool getIsColliding() const;

    void receiveDamage();  //To decrese health
    void Pause() ;
    void update();
    void Animate();

    // Virtual
    virtual void CheckCollision() = 0;  // Checks if units collide other units
    virtual void draw() = 0;  // draws the sprite
};

