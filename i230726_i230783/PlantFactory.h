#pragma once
#include "Plant.h"
#include<iostream>
class PlantFactory
{
private:
	Plant* plants[5][9];
public:
	PlantFactory();
	//~PlantFactory();

	Plant* getPlant(int, int) const;
	void setPlant(int, int, int);
};

