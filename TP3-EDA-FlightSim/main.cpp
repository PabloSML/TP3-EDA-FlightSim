/************************ LIBRERIAS ************************/
#include <stdio.h>
#include <stdlib.h>
#include <new>
#include <stdbool.h>
#include <time.h>
#include "Random.h"
#include "parser.h"
#include "Callback.h"
#include "UserData.h"
#include "Tweety.h"
#include "Drawing.h"

#define HEIGHT 70
#define WIDTH 100

int main(int argc, char* argv[])
{
	randomize();					//Seed para nros random

	if (init_all())							//Inicializo allegro
	{
		userData myinfo;

		bool quit = false;
		char whatsNext;				//Variable con la informacion de la event_queue

		if (parseCmdLine(argc, argv, parseCallBack, &myinfo))
		{
			tweety* flock = new (std::nothrow) tweety[myinfo.getBirdCount()];

			//randomize segun modo (falta modo)

			while (!quit)
			{
				whatsNext = itstime();
				switch (whatsNext)
				{
					case ITSTIME:
										for (int i = 0; i < myinfo.getBirdCount(); i++)
										{
											flock[i].project(flock, myinfo.getBirdCount(), myinfo.getRandomJiggleLimit(), myinfo.getEyesight());
										}
										for (int i = 0; i < myinfo.getBirdCount(); i++)
										{
											flock[i].move(HEIGHT, WIDTH);
										}
										draw_birds(&myinfo, flock);
										//tick_count++;
										break;

					case '1':case '2':case 'E':case 'J':case 'V': case UP:case DOWN:
										modify(whatsNext, &myinfo, flock);
										break;
					case DO_EXIT:
										quit = true;
										break;

					default:			break;
				}
			}
		}
		destroy_all();

	}

	return 1;
}

