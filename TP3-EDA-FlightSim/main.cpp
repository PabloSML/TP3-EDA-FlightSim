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

#define INPUT_NEEDED 4

using namespace std;

int main(int argc, const char* argv[])
{
	randomize();					//Seed para nros random
	if (init_all())							//Inicializo allegro
	{
		userData myinfo;

		bool quit = false;
		char whatsNext;				//Variable con la informacion de la event_queue

		if (parseCmdLine(argc, argv, parseCallBack, &myinfo) == INPUT_NEEDED)
		{
			tweety* flock = new (std::nothrow) tweety[myinfo.getBirdCount()];

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
				whatsNext = itstime();
				switch (whatsNext)
				{
					case ITSTIME:
										for (unsigned int i = 0; i < myinfo.getBirdCount(); i++)
										{
											flock[i].project(flock, myinfo.getBirdCount(), myinfo.getRandomJiggleLimit(), myinfo.getEyesight());
										}
										for (unsigned int i = 0; i < myinfo.getBirdCount(); i++)
										{
											flock[i].move(HEIGHT, WIDTH);
										}
										draw_birds(&myinfo, flock);
										break;

					case '1':case '2':case 'E':case 'J':case 'V': case 'D':case UP:case DOWN:
										modify(whatsNext, &myinfo, flock);
										break;
					case DO_EXIT:
										quit = true;
										break;

					default:			break;
				}
			}

			delete[] flock;
		}
		else
		{
			cout << "Input Error\n";
			getchar();
		}
		destroy_all();

	}

	return 0;
}

