#pragma once
#include <SFML/Graphics.hpp>
class Bullet
{
protected:
	int X;
	int Y;
	int lane;
	int type; // 0 means normal, 1 means frozen, 2 means fire, etc
	bool Exist;

	static int bulletSpeed;

	sf::Clock bulletClock;
	sf::Sprite Bullet_sprite;
	sf::Texture Bullet_texture;

public:
	Bullet(int x, int y, int aLane, int aType);

	int getX() const;
	int getY() const;
	bool getExist() const;
	int getType() const;
	int getLane() const;
	bool getExists() const;
	int getBulletSpeed() const;

	void setX(int x);
	void setY(int y);
	void setExist(bool s);

	void moveBullet();
	void DrawBullet(sf::RenderWindow& window);
};

