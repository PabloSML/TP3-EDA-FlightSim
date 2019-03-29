/************************ LIBRERIAS ************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <allegro5/allegro.h>
#include "Random.h"
#include "parser.h"
#include "UserData.h"
#include "Tweety.h"
/************************ VARIABLES ************************/
ALLEGRO_EVENT event;
ALLEGRO_EVENT_QUEUE* queue;

/************************ PROTOTIPOS ***********************/
void switch_event(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE* queue, userData_t * userData, tweety *birds, int quit, char whatsNext);
void modify(char whatsNext, char what, userData_t* myinfo, tweety* birds);



int main(int argc, char* argv[])
{
	randomize();																//Seed para nros random
	//init_all();																//Inicializo allegro
	userData_t* myinfo;
	tweety* birds;
	int quit = 1;
	char whatsNext;																//Letra para lo que pida el usuario
	if (parseCmdLine(argc, argv, /*&parseCallBack*/, &myinfo))
	{
		birds = (tweety*) malloc(sizeof(tweety) * myinfo->birdCount);
		//create_birds();														//no se si hay alguna funcion en tweety.cpp para hacer los pajaritos
		while (!quit)
		{
			al_register_event_source(queue, al_get_keyboard_event_source());
			if (event.type == ALLEGRO_EVENT_KEY_CHAR)
				switch_event(event, queue, myinfo, birds, quit, whatsNext);
			else
			{
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
			}
		}
	}
	getchar();
	//destroy_all();
	destroyUserData(myinfo);
	return 1;
}
void switch_event(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE* queue, userData_t * userData, tweety *birds, int quit, char whatsNext)
{
	if (al_get_next_event(queue, &ev))
	{
		switch (ev.keyboard.keycode)
		{
			case ALLEGRO_KEY_T:		//Timer
			{
				whatsNext = 'T';
				break;
			}
			case ALLEGRO_KEY_S:		//Change speed
			{
				whatsNext = 'S';
				break;
			}
			case ALLEGRO_KEY_E:		//Change eyesight 
			{
				whatsNext = 'E';
				break;
			}
			case ALLEGRO_KEY_R:		//Change random jiggle
			{
				whatsNext = 'R';
				break;
			}
			case ALLEGRO_KEY_UP:		 
			{
				char up = 'U';
				modify(whatsNext, up, userData, birds);					//Faltan las funciones de tweety que usa modify
				break;
			}
			case ALLEGRO_KEY_DOWN:		
			{
				char down = 'D';
				modify(whatsNext, down, userData, birds);
				break;
			}
			case ALLEGRO_KEY_Q:		//Quit game
			{
				quit = 0;
				break;
			}
			default:
			{
				break;
			}
		}
	}
}


void modify(char whatsNext, char what, userData_t* myinfo, tweety* birds)
{
	switch (whatsNext)
	{
		case 'T':
		{
			break;
		}
		case 'S':
		{
			if (what == 'U')
			{
				for (int i = 0; i < myinfo->birdCount; i++)
				{
					//birds[i].rise_speed();				//Faltan hacer en tweety.cpp, porque se tienen que hacer desde la clase
				}
			}
			else if (what == 'D')
			{
				for (int i = 0; i < myinfo->birdCount; i++)
				{
					//birds[i].slow_speed();
				}
			}
			break;
		}
		case 'E':
		{
			if (what == 'U')
			{
				for (int i = 0; i < myinfo->birdCount; i++)
				{
					//birds[i].rise_eyesight();
				}
			}
			else if (what == 'D')
			{
				for (int i = 0; i < myinfo->birdCount; i++)
				{
					//birds[i].lower_eyesight();
				}
			}
			break;
		}
		case 'R':
		{
			if (what == 'U')
			{
				for (int i = 0; i < myinfo->birdCount; i++)
				{
					//birds[i].rise_rjiggle();
				}
			}
			else if (what == 'D')
			{
				for (int i = 0; i < myinfo->birdCount; i++)
				{
					//birds[i].lower_rjiggle();
				}
			}
			break;
		}
		default:
			break;
	}
}



