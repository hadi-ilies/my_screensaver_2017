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

void clear(framebuffer_t *buffer, int width, int height, sfColor color)
{
	for (int i = 0; i < width * height; i++) {
		buffer->pixels[i * 4] = color.r;
		buffer->pixels[i * 4 + 1] = color.g;
		buffer->pixels[i * 4 + 2] = color.b;
		buffer->pixels[i * 4 + 3] = 255;
	}
}

void clear_a(framebuffer_t *buffer, int width, int height, const int less_a)
{
	for (int i = 0; i < width * height; i++) {
		if (buffer->pixels[i * 4 + 3] > 0
		&& buffer->pixels[i * 4 + 3] > less_a)
			buffer->pixels[i * 4 + 3] -= less_a;
	}
}
