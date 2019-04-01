#pragma once
#ifndef USERDATA_H
#define USERDATA_H

#include <cstdbool>

#define EMPTY 0		//los campos de la clase userData se inicializan con esta constante
#define MAX_BIRDCOUNT 150	//se agrega una cota arbitraria a la cantidad de pajaros para prevenir incorrecto funcionamiento en computadoras mas lentas
#define EYESIGHT_DELTA 1.0
#define MIN_EYESIGHT  0.0
#define MAX_EYESIGHT 70.0
#define RDMJL_DELTA (10.0 * 2*M_PI / 360.0) //10 grados
#define MIN_RDMJL 0.0
#define MAX_RDMJL (M_PI)

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