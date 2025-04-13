#include "Bullet.h"

int Bullet::bulletSpeed = 5;

Bullet::Bullet(int x, int y, int aLane, int aType) {
	this->X = x;
	this->Y = y;
	this->lane = aLane;
	this->type = aType;
	this->Exist = true;
	if (aType == 0) {
		Bullet_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\Pea.png");
		Bullet_sprite.setScale(0.04f, 0.04f);
	}
	else if (aType == 1) {
		Bullet_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\frozenpea.png");
		Bullet_sprite.setScale(0.06f, 0.06f);
	}

	Bullet_sprite.setTexture(Bullet_texture);
	bulletClock.restart();
}

int Bullet::getX() const 
{
	return this->X;
}

int Bullet::getY() const
{
	return this->Y;
}

int Bullet::getType() const {
	return this->type;
}

bool Bullet::getExist() const
{
	return Exist;
}
int Bullet::getLane() const {
	return this->lane;
}

int Bullet::getBulletSpeed() const {
	return bulletSpeed;
}

bool Bullet::getExists() const {
	return this->Exist;
}

void Bullet::setX(int x) {
	this->X = x;
}

void Bullet::setY(int y) {
	this->Y = y;
}

void Bullet::setExist(bool s)
{
	Exist = s;
}
void Bullet::moveBullet() {
	if (bulletClock.getElapsedTime().asMilliseconds() < bulletSpeed) {
		return;
	}

	bulletClock.restart();

	if (this->X > 1200) {
		Exist = false;
	}
	else {
		this->X += 10;
	}
}

void Bullet::DrawBullet(sf::RenderWindow& window) {
	if (this->Exist == true)
	{
		/*std::cout << "X " << X_coordinate << std::endl;
		std::cout << "Y " << Y_coordinate << std::endl;*/
		Bullet_sprite.setPosition(this->X, this->Y);
		window.draw(Bullet_sprite);
	}
}