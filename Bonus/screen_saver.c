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

typedef struct equation_droite equation_droite;
struct equation_droite {
	float x;
	float y;
};

typedef struct farmebuffer {
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
} framebuffer_t;

void my_put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color);
/*int draw_line(framebuffer_t *framebuffer, sfVector2i point_A, sfVector2i point_B, sfColor color)
{
        equation_droite point_P;
	float point_a;
        float point_b;
	int C = 0;


      	point_a = (point_A.y - point_B.y) / (point_A.x - point_B.x);
	point_b = point_A.y - point_a * point_A.x;
	if(point_A.x >= point_B.x) {
		point_P.x = point_B.x;
		C = point_A.x;
	}
	else  {

		point_P.x = point_A.x;
		C = point_B.x;
	}
	for (float j = point_P.x; j != C; j++) {
		point_P.y = point_a * j + point_b;
		my_put_pixel(framebuffer, j, point_P.y, color);
	}
}
*/
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer_t *buffer = malloc(sizeof(framebuffer_t));

	buffer->pixels = malloc(sizeof(sfUint8) * width * height * 4);
	buffer->width = width;
	buffer->height = height;
	for(int i =0; i <(width * height * 4); i++)
		buffer->pixels[i] = 0;

	return (buffer);
}

sfVector2i sfVector_create( int a, int b)
{
	sfVector2i point;

	point.x = a;
	point.y = b;

	return (point);
}

void my_put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color)
{

	buffer->pixels[(buffer->width * x + y ) * 4] = color.r;
	buffer->pixels[(buffer->width * x + y ) * 4 + 1] = color.g;
       	buffer->pixels[(buffer->width * x + y ) * 4 + 2] = color.b;
	buffer->pixels[(buffer->width * x + y ) * 4 + 3] = color.a;
}
int line (framebuffer_t *buffer, int width , int height, int a, int b)
{
	for(b= 0; a != height; a++)
		my_put_pixel(buffer, a, b, sfRed);
	if (a == height) {
		for (a = 0; b != width; b++)
			my_put_pixel(buffer, a, b, sfGreen);
	}
	if (b == width && a == 0) {
		for(b = 799; a != height; a++) {
			my_put_pixel(buffer, a, b, sfBlue);
		}
	}
	if (a == height && b == 799) {
		for (a = 599; b != 0; b--)
			my_put_pixel(buffer, a, b, sfYellow);
	}
}
void color_cercle(framebuffer_t *buffer, int x_centre, int y_centre, int r, int var, int a, int b)
{
	my_put_pixel(buffer, x_centre + a, y_centre + b, sfRed);
	my_put_pixel(buffer, x_centre + b, y_centre + a, sfBlue);
	my_put_pixel(buffer, x_centre - a, y_centre + b, sfMagenta);
	my_put_pixel(buffer, x_centre - b, y_centre + a, sfWhite);
	my_put_pixel(buffer, x_centre + a, y_centre - b, sfCyan);
	my_put_pixel(buffer, x_centre + b, y_centre - a, sfGreen);
	my_put_pixel(buffer, x_centre - a, y_centre - b, sfYellow);
}
int rainbow_line(framebuffer_t *buffer, int width, int height, int a, int b)
{
	if(b < 599 && a == 799) {
		b++;
		my_put_pixel(buffer, b, a, sfRed);
		}
	if (b == 599 && a > 1) {
		a--;
		my_put_pixel(buffer, b, a, sfWhite);
		}
	if ( b > 1 && b <= 599 && a <= 1) {
		b--;
	       	my_put_pixel(buffer, b, a, sfBlue);
		}
}

int draw_cercle(framebuffer_t *buffer, int x_centre, int y_centre, int r, int var)
{
	int x = 0;
	int a = 0;
	int b = r;
	int d = r -1;

	while (b >= a) {
		if (var == 1) {
		my_put_pixel(buffer, x_centre + a, y_centre + b, sfBlue);
		my_put_pixel(buffer, x_centre + b, y_centre + a, sfGreen);
		my_put_pixel(buffer, x_centre - a, y_centre + b, sfRed);
		my_put_pixel(buffer, x_centre - b, y_centre + a, sfYellow);
		my_put_pixel(buffer, x_centre + a, y_centre - b, sfMagenta);
		my_put_pixel(buffer, x_centre + b, y_centre - a, sfCyan);
		my_put_pixel(buffer, x_centre - a, y_centre - b, sfYellow);
		my_put_pixel(buffer, x_centre - b, y_centre - a, sfWhite);
		}
		if (var == 0)
			color_cercle(buffer, x_centre, y_centre, r, var, a ,b);
	if (d >= 2 * a) {
		d -= d - 2 * a - 1;
		a++;
	}
	else if (d < 2 * (r - b)) {
		d += 2 * b - 1;
		b--;
	}
	else {
		d += 2 * (b - a - 1);
		b--;
		a++ ;
	}
	}
	x = b;// permet de faire des chemins random
	b += a;
	a += x;
}

int main(int argc, char **argv)
{
	// x et y sont inverser dou le probleme des coordoonees FDP
	int var = 0;
	int width = 800;
	int height = 600;
	int r;
	int x;
	int y;
	int a = 799;
	int b = 0;
	int i = 0;
	int j =0;
	sfVideoMode mode = {800, 600, 32};
	sfRenderWindow* Window;
	sfEvent event;
	sfTexture* texture = sfTexture_create(width, height);
	sfSprite* sprite = sfSprite_create();
	sfText* text;
	framebuffer_t *buffer = framebuffer_create(width, height);
	sfVector2f centre;
	centre.x = 400;
	centre.y = 300;

	srand(time(NULL));

	if(argv[1][0] == '-') {
	printf("1: Windows logo.\n");
	printf("2: French flag.\n");
	printf("3: optical effect.\n");
	}
	if(argv[1][0] == '1') {
	Window = sfRenderWindow_create(mode,"SFML Window", sfResize | sfClose,NULL);
	if(!Window) {
                return EXIT_FAILURE;
	}
	line (buffer, width, height, i, j);
	if (!texture) {
		return EXIT_FAILURE;
	}
	while (sfRenderWindow_isOpen(Window)) {
		x = (rand() % ( width - height + 1)) + height;
		y = (rand() % ( width - height + 1)) + height;
		my_put_pixel(buffer, x - 300, y - 400, sfBlue);
		my_put_pixel(buffer, x - 300, y - 200, sfYellow);
		my_put_pixel(buffer, x - 500, y - 400, sfRed);
		my_put_pixel(buffer, x - 500, y - 200, sfGreen);
		while(sfRenderWindow_pollEvent(Window, &event)) {
			if(event.type == sfEvtClosed)
				sfRenderWindow_close(Window);
		}
		sfTexture_updateFromPixels(texture, buffer->pixels, width, height, 0, 0);
		sfSprite_setTexture(sprite, texture, sfTrue);
		sfRenderWindow_clear(Window, sfBlack);
		sfRenderWindow_drawSprite(Window, sprite, NULL);
		sfRenderWindow_display(Window);
	}
	sfTexture_destroy(texture);
	return EXIT_SUCCESS;
	}
	if(argv[1][0] == '2') {
		Window = sfRenderWindow_create(mode,"SFML Window", sfResize | sfClose,NULL);
	if(!Window) {
                return EXIT_FAILURE;
	}
       	if (!texture) {
		return EXIT_FAILURE;
	}
	while (sfRenderWindow_isOpen(Window)) {
		if(b < 599 && a == 799) {
			b++;
			my_put_pixel(buffer, b, a, sfRed);
		}
	       	if (b == 599 && a > 1) {
			a--;
			my_put_pixel(buffer, b, a, sfWhite);
		}
		if ( b > 1 && b <= 599 && a <= 1) {
			b--;
			my_put_pixel(buffer, b, a, sfBlue);
		}
		x = (rand() % ( width - height + 1)) + height;
		y = (rand() % ( width - height + 1)) + height;
		my_put_pixel(buffer, x - 300, y - 525, sfBlue);
		my_put_pixel(buffer, x - 300, y - 325, sfWhite);
		my_put_pixel(buffer, x - 500, y - 525, sfBlue);
		my_put_pixel(buffer, x - 500, y - 325, sfWhite);
		my_put_pixel(buffer, x - 300, y - 125, sfRed);
	       	my_put_pixel(buffer, x - 500, y - 125, sfRed);
		while(sfRenderWindow_pollEvent(Window, &event)) {
			if(event.type == sfEvtClosed)
				sfRenderWindow_close(Window);
		}
		sfTexture_updateFromPixels(texture, buffer->pixels, width, height, 0, 0);
		sfSprite_setTexture(sprite, texture, sfTrue);
		sfRenderWindow_clear(Window, sfBlack);
		sfRenderWindow_drawSprite(Window, sprite, NULL);
		sfRenderWindow_display(Window);
	}
	sfTexture_destroy(texture);
	return EXIT_SUCCESS;
	}
	if(argv[1][0] == '3') {
		Window = sfRenderWindow_create(mode,"SFML Window", sfFullscreen, NULL);
	if(!Window) {
                return EXIT_FAILURE;
	}
	if (!texture) {
		return EXIT_FAILURE;
	}
	while (r <= 250) {
		var++;
		r+= (rand() % ( 20 - 1 + 1)) + 1;
		draw_cercle(buffer,  height / 2, width / 2, r, var);
		var = 0;
		draw_cercle(buffer, height / 2, width / 2, r - 100, var);
		var++;
		draw_cercle(buffer,  height / 2, width / 2, r - 200, var);
		draw_cercle(buffer,  height / 2, width / 2, r, var);
		var = 0;
		draw_cercle(buffer,  height / 2, width / 2, r - 100, var);
		var++;
		draw_cercle(buffer,  height / 2, width / 2, r - 200, var);
		}
	sfSprite_setOrigin(sprite, centre);// permet de definir le centre de rotation
	sfSprite_setPosition(sprite, centre);//mettre position;
	sfTexture_updateFromPixels(texture, buffer->pixels, width, height, 0, 0);
	sfSprite_setTexture(sprite, texture, sfTrue);
	while (sfRenderWindow_isOpen(Window)) {
	       while(sfRenderWindow_pollEvent(Window, &event)) {
		       if(event.type == sfEvtClosed)
			       sfRenderWindow_close(Window);
	       }
	       /* sfTexture_updateFromPixels(texture, buffer->pixels, width, height, 0, 0); */
	       /* sfSprite_setTexture(sprite, texture, sfTrue); */
	       sfRenderWindow_clear(Window, sfBlack);
	       sfSprite_rotate(sprite, 0.125);//permet de dappliquer une rotation nombre de degres
	       sfRenderWindow_drawSprite(Window, sprite, NULL);
	       sfRenderWindow_display(Window);
	}
	sfTexture_destroy(texture);
	return EXIT_SUCCESS;
	}
}
