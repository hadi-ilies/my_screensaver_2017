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

void cercle(framebuffer_t *buffer, rayon *r, int height, int width)
{
	if (r->r1 >= 1101)
		r->r1 = 0;
	if (r->r2 >= 1101)
		r->r2 = 0;
	if (r->r3 >= 1101)
		r->r3 = 0;
	r->r1 += 5;
	r->r2 += 5;
	r->r3 += 5;
	draw_cercle(buffer, height/2, width/2, r->r1);
	draw_cercle(buffer, height/2, width/2, r->r2);
	draw_cercle(buffer, height/2, width/2, r->r3);
}

void cercle_loop(screen_t *scre)
{
	sfEvent event;

	while (sfRenderWindow_isOpen(scre->Window)) {
		clear_a(scre->buffer, scre->width, scre->height, 5);
		cercle(scre->buffer, scre->r, scre->height, scre->width);
		while(sfRenderWindow_pollEvent(scre->Window, &event)) {
			if(event.type == sfEvtClosed)
				sfRenderWindow_close(scre->Window);
		}
		display_window_two(scre);
	}
}

void display_part_cercle(framebuffer_t *buffer, int x_centre,
			int y_centre, cercl *coor)
{
	my_put_pixel(buffer, x_centre + coor->a, y_centre + coor->b, sfBlue);
	my_put_pixel(buffer, x_centre + coor->b, y_centre + coor->a, sfBlue);
	my_put_pixel(buffer, x_centre - coor->a, y_centre + coor->b, sfRed);
	my_put_pixel(buffer, x_centre - coor->b, y_centre + coor->a, sfRed);
	my_put_pixel(buffer, x_centre + coor->a, y_centre - coor->b, sfGreen);
	my_put_pixel(buffer, x_centre + coor->b, y_centre - coor->a, sfGreen);
	my_put_pixel(buffer, x_centre - coor->a, y_centre - coor->b, sfYellow);
	my_put_pixel(buffer, x_centre - coor->b, y_centre - coor->a, sfYellow);
}
