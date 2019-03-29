#include "Tweety.h"
#include "Random.h"
#include "Utilities.h"
#define _USE_MATH_DEFINES
#include <cmath>

//modo 1
void
tweety::randomize(unsigned int maxWidth, unsigned int maxHeight, double usrSpeed)
{
	speed = usrSpeed;
	pos.randomValue(maxHeight, maxWidth);
	angle = randDoubleBetween(0.0, 2 * M_PI);
}

//modo 2
void
tweety::randomize(unsigned int maxWidth, unsigned int maxHeight)
{
	speed = randDoubleBetween(0.5, 5.0);
	pos.randomValue(maxHeight, maxWidth);
	angle = randDoubleBetween(0.0, 2 * M_PI);
}

void
tweety::project(tweety* flock, int birdCount, double randomJiggleLimit, double eyesight)
{
	double angleSum = 0;
	unsigned int divider = 0;

	for (int i = 0; i < birdCount; i++)
	{
		if (inSight(flock[i], eyesight))
		{
			angleSum += flock[i].angle;
			divider++;
		}
	}
	newAngle = angleSum / divider + getRdmJiggle(divider, randomJiggleLimit);

}

void
tweety::move(unsigned int height, unsigned int width)
{
	angle = newAngle;

	double tempX = pos.getPosX();
	double tempY = pos.getPosY();

	double offsetX = speed*cos(angle);
	double offsetY = speed*sin(angle);

	if (tempX + offsetX > width)		//estas lineas hacen que el mundo sea un 'loop'
		offsetX -= width;
	else if (tempX + offsetX < 0)
		offsetX += width;
	if (tempY + offsetY > height)
		offsetY -= height;
	else if (tempY + offsetY < 0)
		offsetY += height;

	pos.offset(offsetX, offsetY);

}