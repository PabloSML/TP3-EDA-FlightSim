/********************** LIBRERIAS UTILIZADAS ***********************************/
#include <iostream>
#include <cstdint>
#include <cstdbool>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Tweety.h"
#include "Point.h"
#include "UserData.h"
#include "Drawing.h"
using namespace std;
 /************************** DEFINICIONES **************************************/
#define FPS 40.0               //frames p/second
#define DISP_MULT 10		//multiplicador
#define W_DIS 100          //ancho de imagen base
#define H_DIS 70           //alto de imagen base
#define BIRD_R 0.5			//Radio del pajaro
#define BIRD_COLOR al_color_name("chocolate") //color de los pajaros
#define UP 84 //Valor igual al de allegro pero con nombre mas corto
#define DOWN 85 //Valor igual al de allegro pero con nombre mas corto
#define ITSTIME 1 //Constante para saber que es el timer
#define DO_EXIT	'Q' //Valor para cerrar el programa
#define INVALID_KEY 0 //Valor que devuelve si se presiona una tecla indebida
/***************************** VARIABLES **************************************/
static ALLEGRO_DISPLAY *display = NULL;
static ALLEGRO_EVENT_QUEUE *event_queue = NULL;
static ALLEGRO_TIMER *timer = NULL;
static ALLEGRO_EVENT ev;
static bool oneclick = false;  //flag para evitar muchas lecturas apretando 1 vez
/***************************** FUNCIONES **************************************/
int init_all(void)
{
	// Instalamos Allegro
	if (!al_init())
	{
		cout << "Failed to initialize Allegro\n";
		return FAILIURE;
	}
	//TIMER
	timer = al_create_timer(1.0 / FPS);
	if (!timer)
	{
		cout << "Failed to create timer!\n";
		return FAILIURE;
	}
	//EVENT QUEUE
	event_queue = al_create_event_queue();
	if (!event_queue)
	{
		cout << "Failed to create event_queue!\n";
		al_destroy_timer(timer);
		return FAILIURE;
	}
	//KEYBOARD
	if (!al_install_keyboard())
	{
		cout << "Failed to initialize the keyboard\n";
		al_destroy_timer(timer);
		al_destroy_event_queue(event_queue);
		return FAILIURE;
	}
	//Inicializo primitivas
	if (!al_init_primitives_addon())
	{
		cout << "Failed to initialize primitives!\n";
		al_destroy_event_queue(event_queue);
		al_destroy_timer(timer);
		al_uninstall_keyboard();
		return FAILIURE;
	}
	// Inicializo el display
	display = al_create_display(W_DIS*DISP_MULT, H_DIS*DISP_MULT);
	if (display == NULL)
	{
		cout << "Failed to create display!\n";
		al_destroy_timer(timer);
		al_destroy_display(display);
		al_destroy_event_queue(event_queue);
		al_shutdown_primitives_addon();
		al_uninstall_keyboard();
		return FAILIURE;
	}
	if (!al_init_font_addon())
	{
		cout << "Failed to init font!\n";
		al_destroy_display(display);
		al_destroy_timer(timer);
		al_destroy_display(display);
		al_destroy_event_queue(event_queue);
		al_shutdown_primitives_addon();
		al_uninstall_keyboard();
		return FAILIURE;
	}
	if (!al_init_ttf_addon())
	{
		cout << "Failed to init font!\n";
		al_destroy_display(display);
		al_destroy_timer(timer);
		al_destroy_display(display);
		al_destroy_event_queue(event_queue);
		al_shutdown_primitives_addon();
		al_uninstall_keyboard();
		al_shutdown_ttf_addon();
		return FAILIURE;
	}
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_start_timer(timer);

	return SUCCESS;
}

void destroy_all(void)
{
	if (display != NULL)
	{
		al_shutdown_font_addon();
		al_shutdown_primitives_addon();
		al_destroy_timer(timer);
		al_destroy_display(display);
		al_destroy_event_queue(event_queue);
		al_uninstall_keyboard();
		al_shutdown_ttf_addon();
		timer = NULL;
		display = NULL;
		event_queue = NULL;
	}
}


char eventGet(void)
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
				case ALLEGRO_KEY_D: event = 'D';		break;
				case ALLEGRO_KEY_Q: event = DO_EXIT;	break;
				case ALLEGRO_KEY_UP: event = UP;		break;
				case ALLEGRO_KEY_DOWN: event = DOWN;	break;
				default:	event = INVALID_KEY;		break;
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


void show_stats(userData* myinfo)
{
	ALLEGRO_COLOR txtcolor = al_color_name("black");
	ALLEGRO_FONT *font = NULL;
	font = al_load_font("FreeMono.ttf",DISP_MULT*2,0);
	if (font != NULL)
	{//Mostramos variables
		al_draw_textf(font, txtcolor, DISP_MULT, DISP_MULT * 3, 0, "Eyesight:%f", myinfo->getEyesight());
		al_draw_textf(font, txtcolor, DISP_MULT, DISP_MULT * 6, 0, "RandomjiggleLimit:%f", myinfo->getRandomJiggleLimit());
		al_flip_display();
		al_rest(1.5);//Hay que dejar leer
		al_flush_event_queue(event_queue);//Vaciamos la event_queue para evitar problemas
		al_destroy_font(font);
	}

}
void draw_birds(userData* myinfo, tweety* flock)
{
	al_clear_to_color(SKY_COLOR);//Cargamos fondo y borramos pajaros anteriores
	for (unsigned int i = 0; i < myinfo->getBirdCount(); i++)
	{
		point* tempPos = flock[i].getPos();
		al_draw_filled_circle(tempPos->getPosX()*DISP_MULT, tempPos->getPosY()*DISP_MULT, BIRD_R*DISP_MULT, BIRD_COLOR);
	}
	al_flip_display();
}