#pragma once
#include "Plant.h"
class Walnut : public Plant
{
	bool isRolling;
public:
	Walnut(int, int, int);

	void setRoll(bool Roll);
	bool getRoll() const;

	void rollWalnut();
	virtual void Update(sf::RenderWindow&);
};

