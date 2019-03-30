/********************** LIBRERIAS UTILIZADAS ***********************************/
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include "Tweety.h"
#include "UserData.h"
#include "Drawing.h"
 /************************** DEFINICIONES **************************************/
#define FPS 60.0               //frames p/second
#define W_DIS 100          //ancho de imagen base
#define H_DIS 70           //alto de imagen base
#define BIRD_R 1			//Radio del pajaro
#define SKY_COLOR al_color_name("dodgerblue") //color del fondo
#define BIRD_COLOR al_color_name("chocolate") //color de los pajaros
#define UP 84 //Valor igual al de allegro pero con nombre mas corto
#define DOWN 85 //Valor igual al de allegro pero con nombre mas corto
#define ITSTIME 1 //Constante para saber que es el timer
#define DO_EXIT	'Q' //Valor para cerrar el programa
/***************************** VARIABLES **************************************/
static ALLEGRO_DISPLAY *display = NULL;
static ALLEGRO_EVENT_QUEUE *event_queue = NULL;
static ALLEGRO_TIMER *timer = NULL;
static ALLEGRO_EVENT ev;
static char modifier = NULL; //puntero al valor que ay que modificar
static bool oneclick = false;  //flag para evitar muchas lecturas apretando 1 vez
/***************************** PROTOTIPOS **************************************/
static void up_down(const char& direction, userData_t* myinfo, tweety* birds);
/***************************** FUNCIONES **************************************/
int init_all(void)
{
	// Instalamos Allegro
	if (!al_init())
	{
		printf("Failed to initialize Allegro");
		return 0;
	}
	//TIMER
	timer = al_create_timer(1.0 / FPS);
	if (!timer)
	{
		printf("failed to create timer!\n");
		return 0;
	}
	//EVENT QUEUE
	event_queue = al_create_event_queue();
	if (!event_queue)
	{
		printf("failed to create event_queue!\n");
		al_destroy_timer(timer);
		return 0;
	}
	//KEYBOARD
	if (!al_install_keyboard())
	{
		fprintf(stderr, "failed to initialize the keyboard\n");
		return 0;
	}
	//Inicializo primitivas
	if (!al_init_primitives_addon())
	{
		printf("failed to initialize primitives!\n");
		al_destroy_event_queue(event_queue);
		al_destroy_timer(timer);
		al_uninstall_keyboard();
		return 0;
	}
	// Inicializo el display
	display = al_create_display(W_DIS,H_DIS);
	if (display == NULL)
	{
		printf("failed to create display!\n");
		al_destroy_timer(timer);
		al_destroy_display(display);
		al_destroy_event_queue(event_queue);
		al_shutdown_primitives_addon();
		al_uninstall_keyboard();
		return 0;
	}
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_start_timer(timer);
	return 1;
	return 0;
}

void destroy_all(void)
{
	if (display != NULL)
	{
		al_shutdown_primitives_addon();
		al_destroy_timer(timer);
		al_destroy_display(display);
		al_destroy_event_queue(event_queue);
		al_uninstall_keyboard();
		timer = NULL;
		display = NULL;
		event_queue = NULL;
	}
}


char itstime(void)
{
	char event;
	if (al_get_next_event(event_queue, &ev)) //Toma un evento de la cola
	{
		//FUERON ORDENADOS POR IMPORTANCIA
		if (ev.type == ALLEGRO_EVENT_TIMER)  //entra cada 1/FPS segundos
		{
			event = ITSTIME;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			event = DO_EXIT;             //Equivalente a terminar programa
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN && oneclick==false)
		{
			oneclick = true; //Activamos el flag de UNA TECLA
			switch (ev.keyboard.keycode)     //activa indicador de tecla correspondiente
			{
				case ALLEGRO_KEY_1: event = '1';		break;
				case ALLEGRO_KEY_2: event = '2';		break;
				case ALLEGRO_KEY_E: event = 'E';		break;
				case ALLEGRO_KEY_V: event = 'V';		break;
				case ALLEGRO_KEY_J: event = 'J';		break;
				case ALLEGRO_KEY_Q: event = DO_EXIT;	break;
				case ALLEGRO_KEY_UP: event = UP;		break;
				case ALLEGRO_KEY_DOWN: event = DOWN;	break;
				default:	break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)    //soltar tecla
		{
			oneclick = false;
			return 0;
		}
		else
		{
			return 0;
		}
	}
	else
		return 0;

	return event;
}


void modify(const char& key, userData_t* myinfo, tweety* birds)
{
	switch (key)
	{
	case '1': case '2': /*ALGO VA ACA PERO NO SE QUE*/ break;
	case 'E': case 'V': case 'J': modifier = key; break;
	case UP: case DOWN: up_down(key, myinfo, birds); break;
	default:	break;
	}
}

static void up_down(const char& direction,userData_t* myinfo, tweety* birds)
{
	if (modifier == 'V')
	{
		for (int i = 0; i < getUserData(myinfo,BIRDS); i++)
		{
			if (direction == UP)
			{
				//birds[i].rise_speed();				//Faltan hacer en tweety.cpp, porque se tienen que hacer desde la clase
			}
			else
			{
				//birds[i].down_speed();
			}
		}
	}
	else if (modifier == 'E')
	{
		for (int i = 0; i < getUserData(myinfo, BIRDS); i++)
		{
			if (direction == UP)
			{
				//birds[i].rise_eye();				//Faltan hacer en tweety.cpp, porque se tienen que hacer desde la clase
			}
			else
			{
				//birds[i].down_eye();
			}
		}
	}
	else if (modifier == 'J')
	{
		for (int i = 0; i < getUserData(myinfo, BIRDS); i++)
		{
			if (direction == UP)
			{
				//birds[i].rise_rdmj();				//Faltan hacer en tweety.cpp, porque se tienen que hacer desde la clase
			}
			else
			{
				//birds[i].down_rdmj();
			}
		}
	}
}

bool draw_birds(userData_t* myinfo, tweety* birds)
{
	al_clear_to_color(SKY_COLOR);
	for (int i = 0; i < getUserData(myinfo, BIRDS); i++)
	{
		//al_draw_filled_circle(birds[i].posx(), birds[i].posy(), BIRD_R, BIRD_COLOR); //FALTAN GETTERS
	}
	al_flip_display();
}