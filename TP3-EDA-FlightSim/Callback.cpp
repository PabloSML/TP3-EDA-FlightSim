#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Callback.h"
#include "UserData.h"

int parseCallBack(const char* key, const char* value, void* usrData) //chequea si los datos ingresados por la linea de comandos son validos
{
	double tempValue = atof(value);
	userData* myData = (userData*)usrData;

	//checking if option is valid
	if (key != NULL) //es opcion
	{
		if (!strcmp(key, "birds") && 0 < tempValue) //cantidad de pajaros
		{
			if (!(myData->setBirdCount(tempValue)))
			{
				printf("%s\n", "Error: Option 'Birds' has been set more than once");
				return CB_ERR;
			}
		}
		else if (!strcmp(key, "eyesight") && 0 < tempValue) //vista del pajaro   FALTA COTA SUPERIOR
		{
			if (!(myData->setEyesight(tempValue)))
			{
				printf("%s\n", "Error: Option 'Eyesight' has been set more than once");
				return CB_ERR;
			}
		}
		else if (!strcmp(key, "randomjigglelimit") && 0 < tempValue) //modificador de precision de la vista	  FALTA COTA SUPERIOR
		{
			if (!(myData->setRandomJiggleLimit(tempValue)))
			{
				printf("%s\n", "Error: Option 'randomJiggleLimit' has been set more than once");
				return CB_ERR;
			}
		}
		else if (!strcmp(key, "mode") && (tempValue == 1 || tempValue == 2))
		{
			if (!(myData->setMode(tempValue)))
			{
				printf("%s\n", "Error: Option mode' has been set more than once");
				return CB_ERR;
			}
		}
		else //option not valid
		{
			printf("%s\n", "Invalid Option");
			getchar();				//pemite que el usuario visualize su codigo de error
			return CB_ERR;
		}
	}

	else
	{
		printf("%s\n", "This program does not accept parameters. Invalid input");
		getchar();		//pemite que el usuario visualize su codigo de error
		return CB_ERR;
	}

	return CB_SUXS; //devuelve 1 si ingreso bien los datos y 0 si los ingreso mal
}
