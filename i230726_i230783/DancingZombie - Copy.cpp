#include "DancingZombie.h"
#include "../OOP_Pro/SimpleZombie.h"
#include "../OOP_Pro/Levels.h"

DancingZombie::DancingZombie()
{
	Health = 5;
	isColliding = false;
	Zombie_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\Dancing_zombie.png");
	Zombie_sprite.setTexture(Zombie_texture);
	Zombie_sprite.setTextureRect(sf::IntRect(0, 0, Zombie_texture.getSize().x, Zombie_texture.getSize().y));
	Zombie_sprite.setPosition(50, 50);
	stop = false;
	zombieSpeed = 0;
}

DancingZombie::DancingZombie(int x, int y, bool exist, int lane)
{
	
	up = true;
	X_coordinate = x;
	Y_coordinate = y;
	this->lane = lane;
	summon = false;
	Exist = exist;
	Health = 5;
	isColliding = false;
	stop = false;
	zombieSpeed = 1;
	Zombie_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\Dancing_zombie.png");
	Zombie_sprite.setTexture(Zombie_texture);
	Zombie_sprite.setTextureRect(sf::IntRect(0, 0, Zombie_texture.getSize().x, Zombie_texture.getSize().y));
	Zombie_sprite.setScale(0.1f, 0.08f);
	
	//Zombie_sprite.setPosition(200, 200);
}

void DancingZombie::moveZombie(sf::RenderWindow& window)  // moves the zombie
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

	if (Y_coordinate < 30)
	{
		up = false;
	}
	if (Y_coordinate > 450)
	{
		up = true;
	}

	if (X_coordinate > -10 && up && !stop && Exist)
	{
		X_coordinate -= 5;
		Y_coordinate -= 5;
		
		
	}
	
	else if (X_coordinate > -10 && !up && !stop && Exist)
	{
		X_coordinate -= 5;
		Y_coordinate += 5;
	}
	else if (X_coordinate < 20 && Exist)
	{
		InvadedHouse = true;
		
		Exist = false;
	}

	if (Y_coordinate > 80 && Y_coordinate < 180)
	{
		lane = 0;
	}
	else if (Y_coordinate > 180 && Y_coordinate < 280)
	{
		lane = 1;
	}
	else if (Y_coordinate > 280 && Y_coordinate < 380)
	{
		lane = 2;
	}
	else if (Y_coordinate > 380 && Y_coordinate < 480)
	{
		lane = 3;
	}
	else if (Y_coordinate > 480 && Y_coordinate < 580)
	{
		lane = 4;
	}




	if (summon)
	{
		for (int p = 0; p < 4; p++)
		{
			dancers[p]->moveZombie(window);
			dancers[p]->DrawZombie(window);
		}
	}
}

void DancingZombie::SummonZombies()
{
	for (int i = 0; i < 4; i++)
	{
		if (!summon && Exist)
		{
			//s = ((i / 2) * 100) + 40;
			dancers[0] = new SimpleZombie(X_coordinate, (Y_coordinate+1)*100+40, 1, lane + 1);
			dancers[1] = new SimpleZombie(X_coordinate, (Y_coordinate-1)*100+40, 1, lane - 1);
			dancers[2] = new SimpleZombie(X_coordinate + 80, Y_coordinate, 1, lane);
			dancers[3] = new SimpleZombie(X_coordinate - 80, Y_coordinate, 1, lane);
			summon = true;
		}

		
	}


}