#include "SimpleZombie.h"

SimpleZombie::SimpleZombie()
{
	Health = 5;
	isColliding = false;
	Zombie_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\zombie1.png");
	Zombie_sprite.setTexture(Zombie_texture);
	Zombie_sprite.setPosition(50, 50);
	stop = false;
	zombieSpeed = 0;
}

SimpleZombie::SimpleZombie(int x, int y, bool exist, int lane)
{
	X_coordinate = x;
	Y_coordinate = y;
	this->lane = lane;
	Exist = exist;
	Health = 5;
	isColliding = false;
	stop = false;
	zombieSpeed = 2;
	Zombie_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\zombie.jpg");
	Zombie_sprite.setTexture(Zombie_texture);
	Zombie_sprite.setScale(0.2f, 0.2f);
	//Zombie_sprite.setPosition(200, 200);
}