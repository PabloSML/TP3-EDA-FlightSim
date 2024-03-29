#include <iostream>
#include <cstring>
#include <cstdlib>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Callback.h"
#include "UserData.h"
using namespace std;

int parseCallBack(const char* key, const char* value, void* usrData) //chequea si los datos ingresados por la linea de comandos son validos
{
	double tempValue = atof(value);
	userData* myData = (userData*)usrData;
	bool program_success = CB_SUXS;

	//checking if option is valid
	if (key != NULL) //es opcion
	{
		if (!strcmp(key, "birds") && 0 < tempValue && tempValue < MAX_BIRDCOUNT) //cantidad de pajaros
		{
			if (!(myData->setBirdCount(tempValue)))
			{
				cout << "Error: Option 'Birds' has been set more than once\n";
				program_success = CB_ERR;
			}
		}
		else if (!strcmp(key, "eyesight") && 0 < tempValue && tempValue < MAX_EYESIGHT) //vista del pajaro  
		{
			if (!(myData->setEyesight(tempValue)))
			{
				cout << "Error: Option 'Eyesight' has been set more than once\n";
				program_success = CB_ERR;
			}
		}
		else if (!strcmp(key, "randomjigglelimit") && 0 < tempValue && tempValue < MAX_RDMJL) //modificador de precision de la vista	  
		{
			if (!(myData->setRandomJiggleLimit(tempValue)))
			{
				cout << "Error: Option 'randomJiggleLimit' has been set more than once\n";
				program_success = CB_ERR;
			}
		}
		else if (!strcmp(key, "mode") && (tempValue == 1 || tempValue == 2))
		{
			if (!(myData->setMode(tempValue)))
			{
				cout << "Error: Option mode' has been set more than once\n";
				program_success = CB_ERR;
			}
		}
		else //option not valid
		{
			program_success = CB_ERR;
		}
	}

	else
	{
		cout << "This program does not accept parameters. Invalid input\n";
		getchar();		//pemite que el usuario visualize su codigo de error
		program_success = CB_ERR;
	}

	return program_success; //devuelve 1 si ingreso bien los datos y 0 si los ingreso mal
}
