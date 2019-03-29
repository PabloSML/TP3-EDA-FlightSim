#include <stdlib.h>
#include "UserData.h"

//esta funcion crea una instancia de la estructura userData y la incializa con la constante EMPTY en cada campo
userData_t* createUserData()
{
	userData_t* data = NULL;
	data = (userData_t*)malloc(sizeof(userData_t));
	if (data != NULL)
	{
		data->eyesight = EMPTY;
		data->randomJiggleLimit = EMPTY;
	}
	return data;
}

//esta funcion modifica el dato seleccionado con el valor recibido por argumento
bool setUserData(userData_t* userData, data_t field, int value)
{
	bool success = false;

	switch (field)
	{
	case EYESIGHT:
		if (!(userData->eyesight))
		{
			userData->eyesight = value;
			success = true;
		}
		break;
	case RDMJG:
		if (!(userData->randomJiggleLimit))
		{
			userData->randomJiggleLimit = value;
			success = true;
		}
		break;
	}

	return success;
}

//esta funcion devuelve el dato especificado
int getUserData(userData_t* userData, data_t field)
{
	switch (field)
	{
	case EYESIGHT:
		return userData->eyesight;
		break;
	case RDMJG:
		return userData->randomJiggleLimit;
		break;
	} 
}

//esta funcion devuelve 'true' si todos los datos han sido ingresados exitosamente, 'false' si no
bool isDataFull(userData_t* data)
{
	bool dataFull = true;

	if (data->eyesight == EMPTY)
		dataFull = false;
	if (data->randomJiggleLimit == EMPTY)
		dataFull = false;

	return dataFull;
}

//esta funcion libera la memoria pedida por la estructura 
void destroyUserData(userData_t* userData)
{
	free(userData);
	userData = NULL;
}