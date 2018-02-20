/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"

void my_put_pixel(framebuffer_t *buffer, int x, int y, sfColor color)
{
	if (( x < buffer->height  && x >= 0 )
	&& ( y < buffer->width && y >= 0)) {
		buffer->pixels[(buffer->width * x + y ) * 4] = color.r;
		buffer->pixels[(buffer->width * x + y ) * 4 + 1] = color.g;
		buffer->pixels[(buffer->width * x + y ) * 4 + 2] = color.b;
		buffer->pixels[(buffer->width * x + y ) * 4 + 3] = color.a;
	}
}

void line (framebuffer_t *buffer, int width , int height, coord *p)
{
	for(p->b= 0; p->a != height; p->a++)
		my_put_pixel(buffer, p->a, p->b, sfRed);
	if (p->a == height) {
		for (p->a = 0; p->b != width; p->b++)
			my_put_pixel(buffer, p->a, p->b, sfGreen);
	}
	if (p->b == width && p->a == 0) {
		for(p->b = 799; p->a != height; p->a++) {
			my_put_pixel(buffer, p->a, p->b, sfBlue);
		}
	}
	if (p->a == height && p->b == 799) {
		for (p->a = 599; p->b != 0; p->b--)
			my_put_pixel(buffer, p->a, p->b, sfYellow);
	}
}

sfColor rgba(int r, int g, int b, int a)
{
	sfColor rgba;

	rgba.r = r;
	rgba.g = g;
	rgba.b = b;
	rgba.a = a;
	return (rgba);
}

void draw_cercle(framebuffer_t *buffer, int x_centre, int y_centre, int r)
{
	cercl *coor = malloc(sizeof(cercl));

	coor->a = 0;
	coor->b = r;
	coor->d = r - 1;
	while (coor->b >= coor->a) {
		display_part_cercle(buffer, x_centre, y_centre, coor);
		if (coor->d >= 2 * coor->a) {
			coor->d -=  2 * coor->a - 1;
			coor->a++;
		} else if (coor->d < 2 * (r - coor->b)) {
			coor->d += 2 * coor->b - 1;
			coor->b--;
		} else {
			coor->d += 2 * (coor->b - coor->a - 1);
			coor->b--;
			coor->a++;
		}
	}
}
