#include "Unit.h"
using namespace std;

Unit::Unit()
{
    X_coordinate = 0;
    Y_coordinate = 0;
    Exist = false;
}
Unit::Unit(int x, int y, bool exist)
{
    X_coordinate = x;
    Y_coordinate = y;
    Exist = exist;
}

// Setters
void Unit::setX_coordinate(int x) {
    X_coordinate = x;
}

void Unit::setY_coordinate(int y) {
    Y_coordinate = y;
}

void Unit::setExist(bool exist) {
    Exist = exist;
}

void Unit::setHealth(int health) {
    Health = health;
}

void Unit::setIsColliding(bool colliding) {
    isColliding = colliding;
}

// Getters
int Unit::getX_coordinate() const {
    return X_coordinate;
}

int Unit::getY_coordinate() const {
    return Y_coordinate;
}

bool Unit::getExist() const {
    return Exist;
}

int Unit::getHealth() const {
    return Health;
}

bool Unit::getIsColliding() const {
    return isColliding;
}

void Unit::receiveDamage()
{
    Health--;
}

void Unit::CheckCollision(){}
void Unit::Pause(){}
void Unit::draw(){}
void Unit::update(){}
void Unit::Animate(){}
