#include "FootballZombie.h"
#include<iostream>

FootballZombie::FootballZombie()
{
	Health = 5;
	isColliding = false;
	Zombie_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\Football_zombie.png");
	Zombie_sprite.setTexture(Zombie_texture);
	Zombie_sprite.setPosition(50, 50);
	stop = false;
	zombieSpeed = 0;
}

FootballZombie::FootballZombie(int x, int y, bool exist, int lane)
{
	X_coordinate = x;
	Y_coordinate = y;
	this->lane = lane;
	Exist = exist;
	Health = 5;
	isColliding = false;
	stop = false;
	zombieSpeed = 2;
	Zombie_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\Football_zombie.png");
	Zombie_sprite.setTexture(Zombie_texture);
	Zombie_sprite.setScale(0.35f, 0.35f);
	//Zombie_sprite.setPosition(200, 200);
}

void FootballZombie::moveZombie(sf::RenderWindow& window)  // moves the zombie
{
	//std::cout << "Elapsed time: " << Zombie_clock.getElapsedTime().asMilliseconds() << " ms" << std::endl; // Print elapsed time
	if (Zombie_clock.getElapsedTime().asMilliseconds() < zombieSpeed && Exist)
		return;

	Zombie_clock.restart();

	bool jump = false;
	static bool right = false;
	if (stop)
	{
		static sf::Clock clk;
		if (clk.getElapsedTime().asSeconds() >= 3)
		{
			stop = false;
			clk.restart();
		}
	}
	if (X_coordinate == 800 || X_coordinate == 600 || X_coordinate == 400)
	{
		jump = true;

	}
	if (jump)
	{
		if (Y_coordinate < 460 && right && lane!= 4)
		{
			X_coordinate -= 5;
			Y_coordinate += 80;
			lane++;
			right = false;
		}
		else if (Y_coordinate > 80 && !right && lane != 0)
		{
			X_coordinate -= 5;
			Y_coordinate -= 80;
			lane--;
			right = true;
		}

		jump = false;
	}
	else if (!jump)
		if (X_coordinate > -10 && !stop)
			X_coordinate -= 5;

		else if (X_coordinate < 20 && Exist)
		{
			InvadedHouse = true;
			//std::cout << "Football zombie invaded house!\n";
			Exist = false;
		}
	//std::cout << "moving bro!\n";
	//Y_coordinate -= 500;
	//std::cout << "X " << X_coordinate << std::endl;
	//std::cout << "Y " << Y_coordinate << std::endl << std::endl;
}