#include "Item.h"
#include <iostream>
using namespace std;
//Item();
//Item(sf::RenderWindow& window, int X_position, int Y_position);
//bool MouseInArea(sf::RenderWindow& window);
//int getX_position() const;
//int getY_position() const;
//
//// Setters
//void setX_position(int x);
//void setY_position(int y);
//void Draw_item(sf::RenderWindow& window);
//void Select();

Item::Item(sf::RenderWindow& window, int X_position, int Y_position, const sf::Image& image) {
	item_texture.loadFromImage(image);
	item_sprite.setTexture(item_texture);
	item_sprite.setPosition(X_position, Y_position);
}

int Item::getX_position() const {
	return X_position;
}

int Item::getY_position() const {
	return Y_position;
}

// Setters
void Item::setX_position(int x) {
	X_position = x;
}

void Item::setY_position(int y) {
	Y_position = y;
}

bool Item::MouseInArea(sf::RenderWindow& window)
{
	float posX = sf::Mouse::getPosition(window).x;
	float posY = sf::Mouse::getPosition(window).y;
	//cout << "X	"<<posX << "	Y	"<<posY<<endl;

	float itemX = item_sprite.getPosition().x;
	float itemY = item_sprite.getPosition().y;
	//cout << "X	" << itemX << "	Y	" << itemY << endl<<endl;
	float itemLimitX = item_sprite.getPosition().x + item_sprite.getLocalBounds().width;
	float itemLimitY = item_sprite.getPosition().y + item_sprite.getLocalBounds().height;
	//cout << "X	" << itemLimitX << "	Y	" << itemLimitY << endl;
	if (posX < itemLimitX+50 && posX>itemX+40 && posY < itemLimitY+60 && posY > itemY+40)
	{
		//cout << "ON ITEM\n";
		return true;
	}
	return false;
}

void Item::Draw_item(sf::RenderWindow& window)
{
	window.draw(item_sprite);
}