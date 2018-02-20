/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"
#include <stdio.h>

sfRenderWindow *display_window_one(screen_t *scre)
{
	scre->Window = sfRenderWindow_create(scre->mode,"SFML Window",
			sfFullscreen, NULL);
	if(!scre->Window)
		return (NULL);
	if (!scre->texture)
		return (NULL);
	return (scre->Window);
}

void display_loop(screen_t *scre, coord *p)
{
	sfEvent event;

	while (sfRenderWindow_isOpen(scre->Window)) {
		line (scre->buffer, scre->width, scre->height, p);
		display_logo(scre->buffer, p, scre->width, scre->height);
		while(sfRenderWindow_pollEvent(scre->Window, &event)) {
			if(event.type == sfEvtClosed)
				sfRenderWindow_close(scre->Window);
		}
		display_window_two(scre);
	}
}

int display_window_two(screen_t *scre)
{
	sfTexture_updateFromPixels(scre->texture, scre->buffer->pixels,
		scre->width, scre->height, 0, 0);
	sfSprite_setTexture(scre->sprite, scre->texture, sfTrue);
	sfRenderWindow_clear(scre->Window, sfBlack);
	sfRenderWindow_drawSprite(scre->Window, scre->sprite, NULL);
	sfRenderWindow_display(scre->Window);
	return (0);
}

int display_window_three(sfTexture *texture)
{
	sfTexture_destroy(texture);
	return (EXIT_SUCCESS);
}
