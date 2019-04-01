#include "Backend_aux.h"
#include "Drawing.h"
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_color.h>

//Esta funcion llama a los metodos que modifican los valores de speed, eyesight y rjigglelimit segun sea requerido
static void up_down(const char& direction, userData* myinfo, tweety* flock, char modifier);
//***********************************************************************************************************************

void eventHandle(const char& key, userData* myinfo, tweety* flock, char* modifier, bool* quit)
{
	switch (key)
	{
	case ITSTIME:
		for (unsigned int i = 0; i < myinfo->getBirdCount(); i++)
		{
			flock[i].project(flock, myinfo->getBirdCount(), myinfo->getRandomJiggleLimit(), myinfo->getEyesight());
		}
		for (unsigned int i = 0; i < myinfo->getBirdCount(); i++)
		{
			flock[i].move(HEIGHT, WIDTH);
		}
		draw_birds(myinfo, flock);
		break;

	case '1':
		myinfo->setMode(1);
		for (unsigned int i = 0; i < myinfo->getBirdCount(); i++)
		{
			flock[i].randomize(WIDTH, HEIGHT, GROUP_SPEED);
		}
		al_clear_to_color(SKY_COLOR);
		al_flip_display();
		break;
	case '2':
		myinfo->setMode(2);
		for (unsigned int i = 0; i < myinfo->getBirdCount(); i++)
		{
			flock[i].randomize(WIDTH, HEIGHT);
		}
		al_clear_to_color(SKY_COLOR);
		al_flip_display();
		break;
	case 'E': case 'V': case 'J': *modifier = key; break;
	case 'D': show_stats(myinfo); break;
	case UP: case DOWN: up_down(key, myinfo, flock, *modifier); break;
	case DO_EXIT:
		*quit = true;
		break;
	default:	break;
	}
}

static void up_down(const char& direction, userData* myinfo, tweety* flock, char modifier)
{
	if (modifier == 'V')
	{
		for (unsigned int i = 0; i < myinfo->getBirdCount(); i++)
		{
			if (direction == UP)
			{
				flock[i].incSpeed();
			}
			else
			{
				flock[i].decSpeed();
			}
		}
	}
	else if (modifier == 'E')
	{
		if (direction == UP)
		{
			myinfo->incEyesight();
		}
		else
		{
			myinfo->decEyesight();
		}
	}
	else if (modifier == 'J')
	{
		if (direction == UP)
		{
			myinfo->incRDMJL();
		}
		else
		{
			myinfo->decRDMJL();
		}
	}
}