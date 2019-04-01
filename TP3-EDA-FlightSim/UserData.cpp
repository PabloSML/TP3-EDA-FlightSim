#include <cstdlib>
#include "UserData.h"
#define _USE_MATH_DEFINES
#include <math.h>


unsigned int
userData::getBirdCount()
{
	return birdCount;
}

double
userData::getEyesight()
{
	return eyesight;
}

double
userData::getRandomJiggleLimit()
{
	return randomJiggleLimit;
}

int
userData::getMode()
{
	return mode;
}

bool 
userData::setBirdCount(double value)
{
	bool success = false;

	if (birdCount == EMPTY)
	{
		birdCount = value;
		success = true;
	}

	return success;
}

bool 
userData::setEyesight(double value)
{
	bool success = false;

	if (eyesight == EMPTY)
	{
		eyesight = value;
		success = true;
	}

	return success;
}

bool 
userData::setRandomJiggleLimit(double value)
{
	bool success = false;

	if (randomJiggleLimit == EMPTY)
	{
		randomJiggleLimit = value;
		success = true;
	}

	return success;
}

bool
userData::setMode(int value)
{
	bool success = false;

	if (mode == EMPTY)
	{
		mode = value;
		success = true;
	}

	return success;
}

bool
userData::incEyesight()
{
	if (eyesight != MAX_EYESIGHT)
	{
		eyesight += EYESIGHT_DELTA;
		if (eyesight > MAX_EYESIGHT)
		{
			eyesight = MAX_EYESIGHT;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool
userData::decEyesight()
{
	if (eyesight != MIN_EYESIGHT)
	{
		eyesight -= EYESIGHT_DELTA;
		if (eyesight < MIN_EYESIGHT)
		{
			eyesight = MIN_EYESIGHT;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool
userData::incRDMJL()
{
	if (randomJiggleLimit != MAX_RDMJL)
	{
		randomJiggleLimit += RDMJL_DELTA;
		if (randomJiggleLimit > MAX_RDMJL)
		{
			randomJiggleLimit = MAX_RDMJL;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool
userData::decRDMJL()
{
	if (randomJiggleLimit != MIN_RDMJL)
	{
		randomJiggleLimit -= RDMJL_DELTA;
		if (randomJiggleLimit < MIN_RDMJL)
		{
			randomJiggleLimit = MIN_RDMJL;
		}
		return true;
	}
	else
	{
		return false;
	}
}

//esta funcion devuelve 'true' si todos los datos han sido ingresados exitosamente, 'false' si no
bool 
userData::isDataFull()
{
	bool dataFull = true;

	if (birdCount == EMPTY)
		dataFull = false;
	if (eyesight == EMPTY)
		dataFull = false;
	if (randomJiggleLimit == EMPTY)
		dataFull = false;
	if (mode == EMPTY)
		dataFull = false;

	return dataFull;
}