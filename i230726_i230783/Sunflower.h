#pragma once
#include "Plant.h"
#include "Sunlight.h"
#include "Bullet.h"
class Sunflower : public Plant
{
	static int ProductionRate;
	sf::Clock ProductionTime;
	Sunlight* sunlight;
public:
	Sunflower(int x, int y, int aLane);

	virtual void Update(sf::RenderWindow& window);
	virtual bool interact(sf::RenderWindow& window);
	void GenerateSunlight();

	//getters
	int getProductionRate() const;
};

