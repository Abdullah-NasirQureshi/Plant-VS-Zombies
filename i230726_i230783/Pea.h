#pragma once
class Pea
{
private:
	float x;
	float y;
	bool exists;
	int type;
public:
	Pea(float, float);

	float getX() const;
	float getY() const;
	bool getExists() const;

	void setX(float);
	void setY(float);
	void setExists(bool);
};

