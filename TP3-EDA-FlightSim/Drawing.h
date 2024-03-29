#pragma once

#define HEIGHT 70
#define WIDTH 100
#define GROUP_SPEED 0.5

#define UP 84 //Valor igual al de allegro pero con nombre mas corto
#define DOWN 85 //Valor igual al de allegro pero con nombre mas corto
#define ITSTIME 1 //Constante para saber que es el timer
#define DO_EXIT	'Q' //Valor para cerrar el programa
#define SUCCESS 1
#define FAILIURE 0
#define SKY_COLOR al_color_name("dodgerblue") //color del fondo

//INIT_ALL inicializa todo lo necesario para el trabajo,
// devuelve 0 si no pudo cargaralgo y 1 si fue exitoso
int init_all(void);

//DESTROY_ALL destruye todo lo de allegro
void destroy_all(void);

//EVENTGET analiza los eventos de ALLEGRO.
//		RECIBE: ....
//		DEVUELVE:	- ITSTIME si se marco el TEMPO
//					- '1' si se apreto el 1
//					- '2' si se apreto el 2
//					- DO_EXIT si se quiere salir o cerro display
//					- 'E' si se apreto la E
//					- 'V' si se apreto la V
//					- 'J' si se apreto el J
//					- UP o DOWN si se toco flecha arriba o abajo respectivamente
//					-  0  si no paso nada
char eventGet(void);



void draw_birds(userData* myinfo, tweety* flock);

void show_stats(userData* myinfo);