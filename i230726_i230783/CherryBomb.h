#pragma once
#include "Plant.h"
class CherryBomb : public Plant
{
public:
	CherryBomb(int, int, int);

	virtual void Update(sf::RenderWindow& window);
	void Explode();
};

