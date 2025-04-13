#include "DolphinZombie.h"

DolphinZombie::DolphinZombie()
{
	Health = 5;
	isColliding = false;
	Zombie_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\DolphinZombie.png");
	Zombie_sprite.setTexture(Zombie_texture);
	Zombie_sprite.setPosition(50, 50);
	stop = false;
	zombieSpeed = 0;

}

DolphinZombie::DolphinZombie(int x, int y, bool exist, int lane)
{
	X_coordinate = x;
	Y_coordinate = y;
	this->lane = lane;
	Exist = exist;
	Health = 5;
	isColliding = false;
	stop = false;
	zombieSpeed = 2;
	Zombie_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\DolphinZombie.png");
	Zombie_sprite.setTexture(Zombie_texture);
	Zombie_sprite.setScale(0.3f, 0.3f);
}

void DolphinZombie::moveZombie(sf::RenderWindow& window)  // moves the zombie
{
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
		X_coordinate -= 4;
	else if (X_coordinate < 20 && Exist)
	{
		Exist = false;
		//std::cout << "Football zombie invaded house!\n";
		InvadedHouse = true;
	}
}