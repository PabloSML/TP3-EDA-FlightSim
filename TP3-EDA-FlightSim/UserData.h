#pragma once
#ifndef USERDATA_H
#define USERDATA_H

#include <cstdbool>

#define EMPTY 0		//los campos de la clase userData se inicializan con esta constante


class userData {

public:

	userData() {
		birdCount = EMPTY;
		eyesight = EMPTY;
		randomJiggleLimit = EMPTY;
		mode = EMPTY;
	}

	unsigned int getBirdCount();
	double getEyesight();	
	double getRandomJiggleLimit();
	int getMode();

	bool setBirdCount(double value);	
	bool setEyesight(double value);	
	bool setRandomJiggleLimit(double value);	
	bool setMode(int value);

	bool incEyesight();
	bool decEyesight();

	bool incRDMJL();
	bool decRDMJL();

	bool isDataFull();	//esta funcion devuelve 'true' si todos los datos han sido ingresados exitosamente, 'false' si no

private:
	unsigned int birdCount;
	double eyesight;
	double randomJiggleLimit;
	int mode;
};


#endif