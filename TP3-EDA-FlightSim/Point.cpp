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

void point::offset(double offsetX, double offsetY)
{
	posx += offsetX;
	posy += offsetY;
}