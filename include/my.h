/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#pragma once

#include <SFML/Graphics.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int a;
	int b;
	int d;
} cercl;
typedef struct coor {
	int x;
	int y;
	int a;
	int b;
	int i;
	int j;
	int var1;
	int var2;
} coord;

typedef struct
{
	int r1;
	int r2;
	int r3;
} rayon;

typedef struct farmebuffer {
	int width;
	int height;
	sfUint8 *pixels;
} framebuffer_t;

typedef struct screen {
	rayon *r;
	coord *p;
	int width;
	int height;
	int width2;
	int height2;
	sfVideoMode mode;
	sfRenderWindow *Window;
	sfTexture *texture;
	sfSprite *sprite;
	framebuffer_t *buffer;
}screen_t;

int parsing();
void d_flag (char **argv);
void h_flag (char **argv);
int my_printf(const char *format , ...);
framebuffer_t *framebuffer_create(int width, int height);
void display_logo(framebuffer_t *buffer, coord *p, int width, int height);
void display_flag(framebuffer_t *buffer, coord *p, int width, int height);
void my_put_pixel(framebuffer_t *buffer, int x, int y, sfColor color);
void line (framebuffer_t *buffer, int width , int height, coord *p);
void draw_cercle(framebuffer_t *buffer, int x_centre, int y_centre, int r);
void clear(framebuffer_t *buffer, int width, int height, sfColor color);
void clear_a(framebuffer_t *buffer, int width, int height, int color);
sfRenderWindow *display_window_one(screen_t *scre);
void display_loop(screen_t *scre, coord *p);
int display_window_two(screen_t *scre);
int display_window_three(sfTexture *texture);
void cercle(framebuffer_t *buffer, rayon *r, int height, int width);
void cercle_loop(screen_t *scre);
void flag_loop(screen_t *scre);
int choice (char **argv, screen_t *scre);
screen_t *global(char **argv);
void display_part_cercle(framebuffer_t *buffer, int x_centre,
			int y_centre, cercl *coor);
