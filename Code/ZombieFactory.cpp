#include "ZombieFactory.h"
#include "SimpleZombie.h"
#include "FootballZombie.h"
#include "FlyingZombie.h"
#include "DancingZombie.h"
#include "DolphinZombie.h"

ZombieFactory::ZombieFactory()
{
	for (int i = 0; i < 50; i++) {
		zombies[i] = nullptr;
	}
}

//ZombieFactory::~ZombieFactory() {
//	for (int i = 0; i < 50; i++) {
//		delete zombies[i];
//	}
//	delete zombies;
//}

Zombie* ZombieFactory::getZombie(int i) const {
	return zombies[i];
}

void ZombieFactory::setZombie(int x, int y, bool exist, int lane, int selectedZombie, int i) {
	if (zombies[x] == NULL) {
		switch (selectedZombie) {
		case 0:
			delete zombies[i];
			zombies[i] = NULL;
		case 1:
			zombies[i] = new SimpleZombie(x, y, 1, lane);
			break;
		case 2:
			zombies[i] = new FootballZombie(x, y, 1, lane);
			break;
		case 3:
			zombies[i] = new FlyingZombie(x, y, 1, lane);
			break;
		case 4:
			zombies[i] = new DancingZombie(x, y, 1, lane);
			break;
		case 5:
			zombies[i] = new DolphinZombie(x, y, 1, lane);
			break;
		}
	}
}

