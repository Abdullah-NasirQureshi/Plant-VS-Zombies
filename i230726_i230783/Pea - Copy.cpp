#include "Pea.h"

//Pea(float, float);
//
//float getX() const;
//float getY() const;
//bool getExists() const;
//
//void setX(int);
//void setY(int);
//void setExists(int);

Pea::Pea(float x, float y) {
	this->x = x;
	this->y = y;
	this->exists = true;
}

float Pea::getX() const {
	return this->x;
}

float Pea::getY() const {
	return this->y;
}

bool Pea::getExists() const {
	return this->exists;	
}

void Pea::setX(float anX) {
	this->x = anX;
}

void Pea::setY(float aY) {
	this->y = aY;
}

void Pea::setExists(bool anExists) {
	this->exists = anExists;
}