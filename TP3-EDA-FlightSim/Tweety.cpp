#include "Tweety.h"
#include "Random.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdbool>

#define SPEED_DELTA 0.2
#define MIN_SPEED 0.5
#define MAX_SPEED 5.0

//modo 1
void
tweety::randomize(unsigned int maxWidth, unsigned int maxHeight, double groupSpeed)
{
	speed = groupSpeed;
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
		if (inSight(&(flock[i]), eyesight))
		{
			angleSum += flock[i].angle;
			divider++;
		}
	}
	newAngle = (angleSum / divider) + (randDoubleBetween(-randomJiggleLimit, randomJiggleLimit));//Valores elegidos para evitar vuelo circular

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

point*
tweety::getPos()
{
	return &pos;
}

bool
tweety::incSpeed()
{
	if (speed != MAX_SPEED)
	{
		speed += SPEED_DELTA;
		if (speed > MAX_SPEED)
		{
			speed = MAX_SPEED;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool
tweety::decSpeed()
{
	if (speed != MIN_SPEED)
	{
		speed -= SPEED_DELTA;
		if (speed < MIN_SPEED)
		{
			speed = MIN_SPEED;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool
tweety::inSight(tweety* bird, double eyesight)
{
	if (pos.distanceTo(bird->getPos()) <= eyesight)
	{
		return true;
	}
	else
	{
		return false;
	}
}