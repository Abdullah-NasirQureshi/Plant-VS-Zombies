#include "Game.h"
//#include"../SFML/Images/"
// Section A
//Abdullah Nasir 23i0726
// Hamza Kaleem 23i0783

struct coordinates {
	int x;
	int y;
};


int main()
{
	Game* myGame;
	myGame = new Game();
	
	delete myGame;
	return 0;
}