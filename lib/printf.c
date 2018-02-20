/*
** EPITECH PROJECT, 2017
** test
** File description:
** printf.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "my.h"
#include <stddef.h>

void my_printf_next2(const char *str, va_list argc, int i)
{
	if (str[i] == '%' && str[i + 1] == 'p') {
		my_putstr("0x");
		my_put_nbr_base_char(va_arg(argc, size_t), BASE16m);
		i++;
	} if (str[i] == '%' && str[i + 1] == 'S' )
		 my_modulo_s(va_arg(argc, char*));
	if (str[i] == '%' && str[i + 1] == '%')
		my_putchar('%');
	if (str[i] == '%' && str[i + 1] != '%') {
		my_putchar(str[i]);
		i++;
	} if (str[i] == '%' && str[i + 1] == ' ' && str[i + 2] == 'd') {
		my_putchar(' ');
		my_put_nbr(va_arg(argc, int));
	} if (str[i] == '\\' && str[i + 1] == '\\')
		my_putchar('\\');
}

void my_printf_next(const char *s, va_list argc , int i)
{
	if (s[i] == '%' && s[i + 1] == 'o') {
		my_put_nbr_base_char(va_arg(argc, unsigned int), BASE8);
		i++;
	} if (s[i] == '%' && s[i + 1] == 'u') {
		my_put_nbr_base_char(va_arg(argc, unsigned int), BASE10);
		i++;
	} if (s[i] == '%' && s[i + 1] == 'x') {
		my_put_nbr_base_char(va_arg(argc, unsigned int), BASE16m);
		i++;
	} if (s[i] == '%' && s[i + 1] == 'X') {
		my_put_nbr_base_char(va_arg(argc, unsigned int), BASE16M);
		i++;
	} else {
		my_printf_next2(s, argc, i);
	}
}

int my_printf(const char *format, ...)
{
	va_list argc;

	va_start(argc, format);
	for (int j = 0; format[j] != '\0'; j++) {
		if ((format[j] == '%' && format[j + 1] == 'd')||
		(format[j] == '%' && format[j + 1] == 'i')) {
			my_put_nbr(va_arg(argc, int));
			j++;
			return (0);
		} if (format[j] == '%' && format[j + 1] == 's') {
			my_putstr(va_arg(argc, char *));
			j++;
			return (0);
		} if (format[j] == '%' && (format[j + 1] != 'd'
		|| format[j + 1] != 's'||format[j + 1] != 'i')) {
			my_printf_quart(format, argc, j);
			j++;
		} else
			my_putchar(format[j]);
	}
	return (0);
}

int my_put_nbr_base_char(size_t nb, char *base)
{
	size_t a = nb;
	int base1 = my_strlen(base);

	if (a > 0) {
		a = (nb % base1);
		my_put_nbr_base_char((nb / base1) , base);
		my_putchar(base[a]);
	}
	return (0);
}

int my_modulo_s(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 0  &&  str[i] <= 7) {
		my_putchar('\\');
		my_putstr("00");
		my_putchar(str[i] + '0');
		} else if (str[i] > 7 && str[i] < 32) {
		my_putchar('\\');
		my_putchar('0');
		my_put_nbr(str[i] + 2);
		} else if (str[i] >= 127) {
		my_putchar('\\');
		my_putstr("177");
		} else if (str[i] >= 32 && str[i] < 127)
		my_putchar(str[i]);
	}
	return (0);
}
