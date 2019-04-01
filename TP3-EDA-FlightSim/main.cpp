/************************ LIBRERIAS ************************/
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

#define INPUT_NEEDED 4

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

			bool quit = false;
			char modifier;

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


			while (!quit)
			{
				whatsNext = eventGet();
				eventHandle(whatsNext, &myinfo, flock, &modifier, &quit);
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

