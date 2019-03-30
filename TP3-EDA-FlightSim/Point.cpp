#include <cmath>
#include "Point.h"
#include "Random.h"

void 
point::randomValue(unsigned int maxHeight, unsigned int maxWidth)
{
	posx = randDoubleBetween(0.0, (double)maxWidth);
	posy = randDoubleBetween(0.0, (double)maxHeight);
}

double point::getPosX() { return posx; }
double point::getPosY() { return posy; }

void 
point::offset(double offsetX, double offsetY)
{
	posx += offsetX;
	posy += offsetY;
}

double
point::distanceTo(point* p)
{
	return sqrt(pow(posx - p->getPosX(), 2.0) + pow(posy - p->getPosY(), 2.0));
}
