#pragma once

class point {

public:
	point() {};

	void randomValue(unsigned int maxHeight, unsigned int maxWidth);

	double getPosX();
	double getPosY();

	void offset(double offsetX, double offsetY);

	double distanceTo(point* p);

private:
	double posx;
	double posy;
};