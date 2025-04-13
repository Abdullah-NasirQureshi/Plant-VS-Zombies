#include "PlantFactory.h"
#include "Sunflower.h"
#include "PeaShooter.h"
#include "Repeater.h"
#include "SnowPea.h"
#include "Walnut.h"
#include "CherryBomb.h"

PlantFactory::PlantFactory()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			plants[i][j] = NULL;
		}
	}
}

//PlantFactory::~PlantFactory() {
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			if (plants[i][j] != nullptr) {
//				delete plants[i][j];
//			}
//		}
//		delete[] plants[i];
//	}
//	delete[] plants;
//}

Plant* PlantFactory::getPlant(int i, int j) const {
	return plants[i][j];
}

void PlantFactory::setPlant(int gridY, int gridX, int selectedPlant) {
	if (plants[gridY][gridX] == nullptr) {
		switch (selectedPlant) {
		case 0: //delete
		
			delete plants[gridY][gridX];
			plants[gridY][gridX] = nullptr;
			break;
		case 1: //sunflower
			plants[gridY][gridX] = new Sunflower(250 + gridX * 80, 80 + gridY * 100, gridY);
			break;
		case 2: //peashooter
			plants[gridY][gridX] = new PeaShooter(250 + gridX * 80, 80 + gridY * 100, gridY);
			break;
		case 3: //walnut
			//cout << "Repeater!!\n";
			plants[gridY][gridX] = new Walnut(250 + gridX * 80, 80 + gridY * 100, gridY);
			break;
		case 4: //cherrybomb
			plants[gridY][gridX] = new CherryBomb(250 + gridX * 80, 80 + gridY * 100, gridY);
			break;
		case 5: //snowpea
			plants[gridY][gridX] = new SnowPea(250 + gridX * 80, 80 + gridY * 100, gridY);
			break;
		case 6: //repeater
			plants[gridY][gridX] = new Repeater(250 + gridX * 80, 80 + gridY * 100, gridY);
			break;
		}
	}
}