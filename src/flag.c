/*
** EPITECH PROJECT, 2017
** TEST
** File description:
** TEST
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"
#include <stdio.h>

void flag_loop(screen_t *scre)
{
	sfEvent event;

	while (sfRenderWindow_isOpen(scre->Window)) {
		display_flag(scre->buffer, scre->p, scre->width, scre->height);
		while(sfRenderWindow_pollEvent(scre->Window, &event)) {
			if(event.type == sfEvtClosed)
			sfRenderWindow_close(scre->Window);
		}
		display_window_two(scre);
	}
}
