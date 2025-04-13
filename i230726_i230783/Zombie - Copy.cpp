#include "Zombie.h"
#include "../OOP_Pro/PlantFactory.h"
#include<ctime>
#include<iostream>
#include "../OOP_Pro/ScoreBoard.h"

Zombie::Zombie()
{
	X_coordinate = 970;
	Y_coordinate = 40;
	Exist = true;
	Health = 5;
	InvadedHouse = false;
	isColliding = false;
	Zombie_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\zombie.jpg");
	Zombie_sprite.setTexture(Zombie_texture);
	Zombie_sprite.setScale(0.2f, 0.2f);
	//Zombie_sprite.setPosition(200, 200);
	stop = false;
	zombieSpeed = 0;
}

Zombie::Zombie(int x, int y, bool exist, int lane)
{
	X_coordinate = x;
	Y_coordinate = y;
	this->lane = lane;
	Exist = exist;
	Exist = true;
	Health = 5;
	isColliding = false;
	stop = false;
	zombieSpeed = 5;
	Zombie_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\zombie.jpg");
	Zombie_sprite.setTexture(Zombie_texture);
	Zombie_sprite.setScale(0.2f, 0.2f);
	//Zombie_sprite.setPosition(200, 200);
}

// Setters
void Zombie::setX_coordinate(int x) {
	//std::cout << "setting x !\n";
    X_coordinate = x;
}

void Zombie::setY_coordinate(int y) {
    Y_coordinate = y;
}

void Zombie::setExist(bool exist) {
    Exist = exist;
}

void Zombie::setHealth(int health) {
    Health = health;
}

//void Zombie::setIsColliding(bool colliding) {
//    isColliding = colliding;
//}

// Getters
int Zombie::getX_coordinate() const {
    return X_coordinate;
}

int Zombie::getY_coordinate() const {
    return Y_coordinate;
}

bool Zombie::getInvadedHouse()
{
	return InvadedHouse;
}
bool Zombie::getExist() const {
    return Exist;
}

int Zombie::getHealth() const {
    return Health;
}

bool Zombie::getStop() const {
	return stop;
}

int Zombie::getLane()
{
	return this->lane;
}

void Zombie::setLane(int i)
{
	this->lane = i;
}

//bool Zombie::getIsColliding() const {
//    return isColliding;
//}


int Zombie::getZombieSpeed()
{
	return zombieSpeed;
}
void Zombie::setStop(bool s) // stops the zombie to eat the plant
{
	stop = s;
}
void Zombie::moveZombie(sf::RenderWindow& window)   // moves the zombie
{
	//std::cout << "Elapsed time: " << Zombie_clock.getElapsedTime().asMilliseconds() << " ms" << std::endl; // Print elapsed time
	if (Zombie_clock.getElapsedTime().asMilliseconds() < zombieSpeed )
		return;

	Zombie_clock.restart();

	if (stop)
	{
		static sf::Clock clk;
		if (clk.getElapsedTime().asSeconds() >= 3)
		{
			stop = false;
			clk.restart();
		}
	}

	if (Exist && !stop && X_coordinate > -10)
		X_coordinate -= 2;
	
	else if (X_coordinate < 20 && Exist)
	{
		InvadedHouse = true;
		Exist = false;
		
	}
		//Y_coordinate -= 500;
	//std::cout << "X " << X_coordinate << std::endl;
	//std::cout << "Y " << Y_coordinate << std::endl << std::endl;
}

void Zombie::DrawZombie(sf::RenderWindow& window)
{
	//std::cout << "Drawing andar wale zombie\n";
	if (Health < 1)
		Exist = false;

	if (Exist == true)
	{
		/*std::cout << "X " << X_coordinate << std::endl;
		std::cout << "Y " << Y_coordinate << std::endl;*/
		Zombie_sprite.setPosition(X_coordinate, Y_coordinate);
		window.draw(Zombie_sprite);
	}
}
void Zombie::eatPlant(int a)  //Damages plants
{
	//receiveDamage();
}
void Zombie::Freeze() {} // slows the zombies when hit by frozen pea

//virtual
//void Zombie::CheckCollision()   // Checks if units collide other units
//{
//
//	//for(int i=0; )
//} 
//virtual void draw() = 0;  // draws the sprite

void Zombie::checkHealth()
{
	if (Health == 0)
	{
		Exist = false;
	}
}
