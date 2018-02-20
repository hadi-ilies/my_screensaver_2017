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

int parsing()
{
	my_printf("./my_screensaver: bad arguments:  0 gi");
	my_printf("ven but 1 is required\nretry with -h\n");
	return (84);
}

void d_flag (char **argv)
{
	if(argv[1][0] == '-' && argv[1][1] == 'd') {
		my_printf("1: Windows logo.\n");
		my_printf("2: French flag.\n");
		my_printf("3: windows radar.\n");
	}
}

void h_flag (char **argv)
{
	if(argv[1][0] == '-' && argv[1][1] == 'h') {
		my_printf("animation rendering in a CSFML window.\n");
		my_printf("USAGE\n");
		my_printf("./my_screensaver [OPTIONS] animation_id\n");
		my_printf("  animation_id   ID of the animation");
		my_printf("to process (between 1 and 20).\n\n");
		my_printf("OPTIONS\n");
		my_printf("-d\tprint the description of all th");
		my_printf("e animations and quit.\n");
		my_printf("-h\tprint the usage and quit.\n\n");
	}
}
screen_t *global(char **argv)
{
	screen_t *screen = malloc(sizeof(screen_t));

	screen->r = malloc(sizeof(rayon));
	screen->p = malloc(sizeof(coord));
	if(argv[1][0] == '3') {
		screen->width = 1920;
		screen->height = 1080;
	}
	else {
		screen->width = 800;
		screen->height = 600;
	}
	screen->Window = NULL;
	screen->mode.width = screen->width;
	screen->mode.height = screen->height;
	screen->mode.bitsPerPixel = 32;
	screen->texture = sfTexture_create(screen->width, screen->height);
	screen->sprite = sfSprite_create();
	screen->buffer = framebuffer_create(screen->width, screen->height);
	return (screen);
}

int choice (char **argv, screen_t *scre)
{
	if (argv[1][0] == '3') {
		scre->r->r1 = 734;
		scre->r->r2 = 367;
		scre->r->r3 = 0;
		scre->buffer = framebuffer_create(scre->width, scre->height);
		scre->texture = sfTexture_create(scre->width, scre->height);
		scre->Window = display_window_one(scre);
		sfRenderWindow_setFramerateLimit(scre->Window, 30);
		cercle_loop(scre);
		display_window_three(scre->texture);
	}
	return (0);
}
