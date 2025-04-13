#include "Sunlight.h"
//#include<ctime>
#include<iostream>


int Sunlight::currency = 300;


Sunlight::Sunlight()
{
	X_coordinate =540;
	Y_coordinate = -40;
	RandomLanding = (rand() % 4 * 50) + 250;
	Exist = true;
	Sun_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\sun.png");
	Sun_sprite.setTexture(Sun_texture);
	Sun_sprite.setScale(0.4f, 0.4f);
}
Sunlight::Sunlight(int x, int y)
{
	X_coordinate = x;
	Y_coordinate = y;
	RandomLanding = (rand() % 4 * 50) + 250;
	Exist = false;
}

// Setters
void Sunlight::setXCoordinate(int x) {
    X_coordinate = x;
}

void Sunlight::setYCoordinate(int y) {
    Y_coordinate = y;
}

void Sunlight::setRandomLanding(int random) {
    RandomLanding = random;
}

void Sunlight::setExist(bool exist) {
    Exist = exist;
}

void Sunlight::setCurrency(int cur) {
    currency = cur;
}

// Getters
int Sunlight::getXCoordinate() const {
    return X_coordinate;
}

int Sunlight::getYCoordinate() const {
    return Y_coordinate;
}

int Sunlight::getRandomLanding() const {
    return RandomLanding;
}

bool Sunlight::doesExist() const {
    return Exist;
}

int Sunlight::getCurrency() {
    return currency;
}

void Sunlight::dropSun()
{
	if (Sun_clock.getElapsedTime().asMilliseconds() < 3 && Exist)
		return;

	Sun_clock.restart();


	if (Y_coordinate < RandomLanding)
		Y_coordinate += 2;
	
}
void Sunlight::drawSun(sf::RenderWindow& window)
{
	if (Exist == false)
	{
		X_coordinate = (rand() % 20) * 20 + 350;
		Y_coordinate = -200;
		Exist = true;
	}
	if (Exist == true)
	{
		Sun_sprite.setPosition(X_coordinate, Y_coordinate);
		window.draw(Sun_sprite);
	}
}

bool Sunlight::mouseOverSun(sf::RenderWindow& window)
{
	float posX = sf::Mouse::getPosition(window).x;
	float posY = sf::Mouse::getPosition(window).y;
	//cout << "X	"<<posX << "	Y	"<<posY<<endl;

	float buttonX = Sun_sprite.getPosition().x;
	float buttonY = Sun_sprite.getPosition().y;
	//cout << "X	" << buttonX << "	Y	" << buttonY << endl<<endl;
	float buttonLimitX = Sun_sprite.getPosition().x + Sun_sprite.getLocalBounds().width+40;
	float buttonLimitY = Sun_sprite.getPosition().y + Sun_sprite.getLocalBounds().height+80;
	//cout << "X	" << buttonLimitX << "	Y	" << buttonLimitY << endl;
	if (posX < buttonLimitX && posX>buttonX && posY < buttonLimitY && posY > buttonY)
	{
		//std::cout << "ON BUTTON\n";
		return true;
	}
	return false;
}


void Sunlight::UpdateCurrency(sf::RenderWindow& window, sf::Event event)
{
	if (mouseOverSun(window) && (event.type == sf::Event::MouseButtonPressed))
	{
		currency += 100;
		Exist = false;
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		std::cout << "clicked!";
	}
}