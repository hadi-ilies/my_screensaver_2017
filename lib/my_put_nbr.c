/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
	int a = 0;

	a = nb;
	if (a < 0) {
		a = -a ;
		my_putchar('-');
	}
	if (a > 9) {
		my_put_nbr( a / 10 );
	}
	my_putchar((a % 10 ) + '0');
	return (a);
}
