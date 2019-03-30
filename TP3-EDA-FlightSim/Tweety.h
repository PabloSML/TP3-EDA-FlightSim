#pragma once

#include "Point.h"

class tweety
{
public:
	tweety() {};
	
	void randomize(unsigned int maxWidth, unsigned int maxHeight, double groupSpeed);	//velocidad en modo 1
	void randomize(unsigned int maxWidth, unsigned int maxHeight);	//velocidad en modo 2
	void move(unsigned int height, unsigned int width);
	void project(tweety* flock, int birdCount, double randomJiggleLimit, double eyesight);

	point* getPos();

	bool incSpeed();
	bool decSpeed();

private:
	double speed;
	point pos;
	double angle;
	double newAngle;
	bool inSight(tweety* bird, double eyesight);

};