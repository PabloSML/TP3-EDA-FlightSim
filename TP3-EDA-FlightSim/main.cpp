/************************ LIBRERIAS ************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Random.h"
#include "parser.h"
#include "UserData.h"
#include "Tweety.h"
#include "Drawing.h"

int main(int argc, char* argv[])
{
	randomize();					//Seed para nros random
	init_all();							//Inicializo allegro
	userData_t* myinfo;
	tweety* birds;
	bool quit = false;
	char whatsNext;				//Variable con la informacion de la event_queue
	if (parseCmdLine(argc, argv, /*&parseCallBack*/, &myinfo))
	{
		//ME PARECE QUE ES ASI: new tweety[getUserData(myinfo,BIRDS)];
		birds = (tweety*) malloc(sizeof(tweety) * myinfo->birdCount);
		//create_birds();														//no se si hay alguna funcion en tweety.cpp para hacer los pajaritos
		while (!quit)
		{
			whatsNext = itstime();
			switch (whatsNext)
			{
				case ITSTIME:
									for (int i = 0; i < myinfo->birdCount; i++)
									{
										//birds[i].proyect(birds);
									}
									for (int i = 0; i < myinfo->birdCount; i++)
									{
										//birds[i].move(birds);
									}
									//draw_birds(b);
									//tick_count++;
									break;
				case '1':case '2':case 'E':case 'J':case 'V': case UP:case DOWN:
									modify(whatsNext, myinfo, birds);
									break;
				case DO_EXIT:
									quit = true;
									break;
				default:			break;
			}
		}
	}
	destroy_all();
	destroyUserData(myinfo);
	return 1;
}

