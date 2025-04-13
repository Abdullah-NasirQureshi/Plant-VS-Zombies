#pragma once
//#include "../OOP_Pro/Unit.h"
#include <SFML/Graphics.hpp>
#include<ctime>

class Zombie
{
protected:

	int X_coordinate;
	int Y_coordinate;
	int lane;
	bool Exist;
	bool stop;
	int Health;
	bool InvadedHouse;
	bool isColliding;
	bool summon; //only for dancing zombie
	sf::Sprite Zombie_sprite;
	sf::Texture Zombie_texture;
	int zombieSpeed;
	bool up;
	sf::Clock Zombie_clock;
	
public:

	Zombie();

	Zombie(int x, int y, bool exist, int lane);
    // Setters
	void setX_coordinate(int x);

	void setY_coordinate(int y);

	void setExist(bool exist);

	void setHealth(int health);

    //void setIsColliding(bool colliding);

	void setStop(bool s);

    // Getters
    int getX_coordinate() const;

	bool getInvadedHouse();


    int getY_coordinate() const;

    bool getExist() const;

    int getHealth() const;

   // bool getIsColliding() const;

	int getLane();

	void setLane(int i);

	int getZombieSpeed();
	
	bool getStop() const;

	//void Stop(); // stops the zombie to eat the plant
	
	void eatPlant(int);  //Damages plants
	
	void Freeze(); // slows the zombies when hit by frozen pea

	//void CheckCollision();  // Checks if units collide other units

	void DrawZombie(sf::RenderWindow& window);

	void checkHealth();  // checks for health and sets existance to false if health == 0
	//virtual
	virtual void moveZombie(sf::RenderWindow& window) ;  // moves the zombie

	virtual void SummonZombies() {}; // only for dancing zombie

	
	//virtual void draw() = 0;  // draws the sprite
};

