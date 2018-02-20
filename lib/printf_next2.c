/*
** EPITECH PROJECT, 2017
** second part
** File description:
** second part
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>

void my_printf_next(const char *s, va_list argc , int i);

int my_printf_quart(const char *S1, va_list argc , int j)
{
	if (S1[j] == '%' && S1[j + 1] == 'c') {
		my_putchar(va_arg(argc, int));
		j++;
		return (0);
	} if (S1[j] == '%' && S1[j + 1] == 'b') {
		my_put_nbr_base_char(va_arg(argc, unsigned int) , BASE2);
		j++;
		return (0);
	} if (S1[j] == '%' && S1[j + 1] == 'f') {
		my_put_nbr_float(va_arg(argc, double));
		return (0);
	} if (S1[j] == '%' && (S1[j + 1] != 'd'
		|| S1[j + 1] != 'c' || S1[j + 1] != 's'
		|| S1[j + 1] != 'b' || S1[j + 1] != 'i'
		|| S1[j + 1] != 'f')) {
		my_printf_next(S1, argc, j);
		j++;
		return (0);
	}
	return (0);
}

int my_put_nbr_float(double nb)
{
	int a = 10;
	int b = nb;

	my_put_nbr(b);
	b = 6;
	if (b > 0)
		my_putchar('.');

	for (int val = 0; b > 0; b--) {
		if (val < 0)
		val = -val;
		val = (int) (nb * a);
		val %= 10;
		my_put_nbr(val);
		a *= 10;
	}
	return (0);
}
