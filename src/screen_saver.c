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

framebuffer_t *framebuffer_create(int width, int height)
{
	framebuffer_t *buffer = malloc(sizeof(framebuffer_t));

	buffer->pixels = malloc(sizeof(sfUint8) * width * height * 4);
	buffer->width = width;
	buffer->height = height;
	for(int i = 0; i < (width * height * 4); i++)
		buffer->pixels[i] = 0;
	return (buffer);
}

void display_logo(framebuffer_t *buffer, coord *p, int width, int height)
{
	p->x = (rand() % ( width - height + 1)) + height;
	p->y = (rand() % ( width - height + 1)) + height;
	my_put_pixel(buffer, p->x - 300, p->y - 400, sfBlue);
	my_put_pixel(buffer, p->x - 300, p->y - 200, sfYellow);
	my_put_pixel(buffer, p->x - 500, p->y - 400, sfRed);
	my_put_pixel(buffer, p->x - 500, p->y - 200, sfGreen);
}

void display_flag(framebuffer_t *buffer, coord *p, int width, int height)
{
	if(p->b < 599 && p->a == 799) {
		p->b++;
		my_put_pixel(buffer, p->b, p->a, sfRed);
	}
	if (p->b == 599 && p->a > 1) {
		p->a--;
		my_put_pixel(buffer, p->b, p->a, sfWhite);
	}
	if ( p->b > 1 && p->b <= 599 && p->a <= 1) {
		p->b--;
		my_put_pixel(buffer, p->b, p->a, sfBlue);
	}
	p->x = (rand() % ( width - height + 1)) + height;
	p->y = (rand() % ( width - height + 1)) + height;
	my_put_pixel(buffer, p->x - 300, p->y - 525, sfBlue);
	my_put_pixel(buffer, p->x - 300, p->y - 325, sfWhite);
	my_put_pixel(buffer, p->x - 500, p->y - 525, sfBlue);
	my_put_pixel(buffer, p->x - 500, p->y - 325, sfWhite);
	my_put_pixel(buffer, p->x - 300, p->y - 125, sfRed);
	my_put_pixel(buffer, p->x - 500, p->y - 125, sfRed);
}

int main(int argc, char **argv)
{
	screen_t *scre;

	if(argc < 2)
	parsing();
	else {
		scre = global(argv);
		d_flag(argv);
		h_flag(argv);
		if(argv[1][0] == '1') {
			scre->Window = display_window_one(scre);
			display_loop(scre, scre->p);
			display_window_three(scre->texture);
		} if(argv[1][0] == '2') {
			scre->p->a = 799;
			scre->Window = display_window_one(scre);
			flag_loop(scre);
			display_window_three(scre->texture);
		}
		choice(argv, scre);
	}
}
