/*
	Este archivo contiene funciones auxiliares al funcionamiento del programa
*/

#pragma once

#include "Tweety.h"
#include "UserData.h"

//EVENTHANDLE analiza los datos ingresados por el teclado y hace las actividades correspondientes
//		RECIBE:		- key: parametro a analisar
//					- myinfo: varaible con informacion util para otra funcion
//					- birds: varaible con informacion util para otra funcion
//		DEVUELVE:	...
void eventHandle(const char& key, userData* myinfo, tweety* flock, char* modifier, bool* quit);