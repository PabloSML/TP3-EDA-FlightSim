/*
parser.c
Grupo 1:
Dutriez, Philippe
Dalla Lasta, Pedro
Smolkin, Pablo
*/

#include <cctype>
#include <iostream>
#include "parser.h"

using namespace std;

/*
Esta funcion valida la forma de lo ingresado por linea de comandos y utiliza una funcion recibida para validar su coherencia
Recibe:
	argc: cantidad de argumentos a analizar
	argv: argumentos a analizar
	checkInputs: funcion que contiene los criterios de validacion segun la coherencia de los argumentos
	userData: puntero hacia una zona designada por el usuario para pasar a la funcion checkInputs
Devuelve:
	-1 si hubo un error en el formato o coherencia de lo ingresado
	sum - la suma de la cantidad de opciones y parametros - si no hubo ningun error
Clave: Argumento que comienza con '-' y requiere un valor como siguiente argumento. No puede ser vacia
Valor: Argumento precededido por una clave. No puede ser vacio
Parámetro: Argumento que no comienza con '-' y no es precedido por una clave
*/
int parseCmdLine(int argc, char const *argv[], pCallback checkInputs, void * userData)
{
	int i;
	int sum = 0;

	for (i = 1; i < argc; i++)
	{
		if (*argv[i] == '-')
		{
			if (argv[i][1] == '\0')	//Analiza si el caracter siguiente al guion es vacio
			{
				cout << "Missing Key\n";
				return ERROR;
			}
			else if (i == argc - 1)	//Analiza si no existe valor para la opcion actual
			{
				cout << "Missing Value\n";
				return ERROR;
			}
			else if (!(checkInputs(argv[i] + 1, argv[i + 1], userData)))	//Analiza la validez de la opcion segun lo determinado por el Callback
			{
				cout << "Program terminated due to invalid option/value.\n";
				return ERROR;
			}
			else
				i++;	//Si la opcion es valida, se incrementa el indice para saltear el valor
		}
		else
		{
			if (!(checkInputs(NULL, argv[i], userData)))	//Analiza la validez del parametro segun lo determinado por el Callback
			{
				cout << "Program terminated due to invalid parameter\n";
				return ERROR;
			}
		}
		sum++;	//Si lo analizado es valido, se suma a la cuenta total de opciones y parametros
	}
	return sum;
}