#pragma once

#include "Point.h"

class tweety
{
public:
	tweety() {};
	
	void randomize(unsigned int maxWidth, unsigned int maxHeight, double usrSpeed);	//velocidad en modo 1
	void randomize(unsigned int maxWidth, unsigned int maxHeight);	//velocidad en modo 2
	void move(unsigned int height, unsigned int width);
	//void move(unsigned int height, unsigned int width, double speed); no creo que sea necesario
	void project(tweety* flock, int birdCount, double randomJiggleLimit, double eyesight);


private:
	double speed;
	point pos;
	double angle;
	double newAngle;
	//double eyesight;
	//double rJiggle;
	bool inSight(const tweety& t, double eyesight);

};