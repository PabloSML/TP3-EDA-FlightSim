#pragma once
#ifndef USERDATA_H
#define USERDATA_H

#include <stdbool.h>

#define EMPTY 0		//los campos de la estructura userData se inicializan con esta constante

typedef enum {BIRDS, EYESIGHT, RDMJG} data_t;	//los distintos datos que se pueden pedir o modificar en la estructura

class userData_t {
	public:
	unsigned int birdCount;
	double eyesight;
	double randomJiggleLimit;
};

userData_t* createUserData();	//esta funcion crea una instancia de la estructura userData y la incializa con la constante EMPTY en cada campo
bool setUserData(userData_t* userData, data_t field, double value);	//esta funcion modifica el dato seleccionado con el valor recibido por argumento
double getUserData(userData_t* userData, data_t field);	//esta funcion devuelve el dato especificado
bool isDataFull(userData_t* data);	//esta funcion devuelve 'true' si todos los datos han sido ingresados exitosamente, 'false' si no
void destroyUserData(userData_t* userData);	//esta funcion libera la memoria pedida por la estructura 

#endif