/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#ifndef MY_H
#define MY_H
#include <stdarg.h>
#include <stddef.h>
#define BASE2 "01"
#define BASE8 "01234567"
#define BASE16M "0123456789ABCDEF"
#define BASE16m "0123456789abcdef"
#define BASE10 "0123456789"

int my_put_nbr_float(double nb);
void my_putchar(char c);
int my_compute_power_rec(int nb , int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime(int nb);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str , int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab , int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest , char const *src);
int my_strcmp(char const *s1 , char const *s2);
char *my_strcpy(char *dest , char const *src);
int my_str_isalpha(char const *str);
int my_str_islower (char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest , char const *src , int nb);
int my_strncmp(char const *s1 , char const *s2 , int n);
char *my_strncpy(char *dest, char const *src , int n);
char *my_strstr(char const *str , char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int my_printf(const char *format , ...);
int my_put_nbr_base(int nb, char *base);
int my_put_nbr_base_char(size_t nb, char *base);
int my_modulo_s(char *str);
int my_printf_quart(const char *S1, va_list argc , int j);
void my_printf_next(const char *s, va_list argc, int i);
int my_printf(const char *format , ...);
void my_printf_next2(const char *str, va_list argc, int i);

#endif
