#pragma once

#include "Point.h"

class tweety
{
public:
	tweety(int width, int height);
	move(void);
	move(double speed);
	project(tweety* flock, int birdCount, double randomJiggleLimit, double eyesight);


private:
	double speed;
	point pos;
	double angle;
	double newAngle;
	double eyesight;
	double rJiggle;
	bool inSight(const tweety& t, double rJiggle);

};