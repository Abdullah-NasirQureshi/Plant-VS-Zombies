#include "FlyingZombie.h"
#include<iostream>

FlyingZombie::FlyingZombie()
{
	Health = 5;
	isColliding = false;
	Zombie_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\flyingzombie.png");
	Zombie_sprite.setTexture(Zombie_texture);
	Zombie_sprite.setPosition(50, 50);
	stop = false;
	zombieSpeed = 0;
}

FlyingZombie::FlyingZombie(int x, int y, bool exist, int lane)
{
	X_coordinate = x;
	Y_coordinate = y;
	this->lane = lane;
	//FlyingZombieCollided = false;
	Exist = exist;
	Health = 5;
	isColliding = false;
	stop = false;
	zombieSpeed = 5;
	Zombie_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\flyingzombie.png");
	Zombie_sprite.setTexture(Zombie_texture);
	Zombie_sprite.setScale(0.3f, 0.3f);
	//Zombie_sprite.setPosition(200, 200);
}

void FlyingZombie::moveZombie(sf::RenderWindow& window)  // moves the zombie
{
	bool up = false;
	//std::cout << "Elapsed time: " << Zombie_clock.getElapsedTime().asMilliseconds() << " ms" << std::endl; // Print elapsed time
	if (Zombie_clock.getElapsedTime().asMilliseconds() < zombieSpeed && Exist)
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
	if (X_coordinate > -10 && !stop)
		X_coordinate -= 3;
	else if(X_coordinate < 20 && Exist)
	{
		Exist = false;
		//std::cout << "Football zombie invaded house!\n";
		InvadedHouse = true;
	}
	/*if(X_coordinate == plant's X_coordinate && up == false)
	{
		Y_coordinate -= 40;
		up = true;
	}
	if (up == true && X_coordinate != = plant's X_coordinate)
	{
		Y_coordinate += 40;
		up = false;
	}*/
	
}