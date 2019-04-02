/************************************************ LIBRERIAS *********************************************/
#include <iostream>
#include <cstdlib>
#include <new>
#include <cstdbool>
#include <ctime>
#include "Random.h"
#include "parser.h"
#include "Callback.h"
#include "UserData.h"
#include "Tweety.h"
#include "Drawing.h"
#include "Backend_aux.h"

#define INPUT_NEEDED 4 //Cantidad de argumentos 
/******************************************* USO DEL PROGRAMA *********************************************
ARGUMENTOS: -birds x -eyesight x -randomjigglelimit x -mode x (Cada uno cuenta con sus respectivas cotas).

EJECUCION: - Con 'E','V','J' se eligen las variables.
			- Con las flechas arriba y abajo se modifican.
			- Con 'D' muestra los valores de eyesight y randomjiggle por un tiempo.
			- Con 'Q' se cierra el programa
***********************************************************************************************************/
using namespace std;

int main(int argc, const char* argv[])
{
	randomize();					//Seed para nros random

	if (init_all())							//Inicializo allegro
	{
		userData myinfo;

		char whatsNext;				//Variable con la informacion de la event_queue

		int parseResult = parseCmdLine(argc, argv, parseCallBack, &myinfo);

		if (parseResult == INPUT_NEEDED)
		{
			tweety* flock = new (std::nothrow) tweety[myinfo.getBirdCount()];

			bool quit = false; //flag para cerrar todo
			char modifier;
			//Dependiendo el modo la inicialzacion de la velocidad difiere
			if (myinfo.getMode() == 1)
			{
				for (unsigned int i = 0; i < myinfo.getBirdCount(); i++)
				{
					flock[i].randomize(WIDTH, HEIGHT, GROUP_SPEED);
				}
			}
			else
			{
				for (unsigned int i = 0; i < myinfo.getBirdCount(); i++)
				{
					flock[i].randomize(WIDTH, HEIGHT);
				}
			}


			while (!quit) //Corazon del main y proyecto
			{
				whatsNext = eventGet(); //Conseguimos el proximo evento en la cola
				eventHandle(whatsNext, &myinfo, flock, &modifier, &quit); //Analizamos dicho evento
			}

			delete[] flock;
		}
		else	//codigos de error correspondientes al parseo de linea de comando
		{
			cout << "Input Error\n";
			switch (parseResult)
			{
			case KEY:
				cout << "Missing Key\n";
				break;
			case VALUE:
				cout << "Missing Value\n";
				break;
			case CB_OPT:
				cout << "Invalid Option\n";
				break;
			case CB_PAR:
				cout << "Invalid Parameter\n";
			default:
				break;
			}


			getchar();
		}
		destroy_all();

	}

	return 0;
}

