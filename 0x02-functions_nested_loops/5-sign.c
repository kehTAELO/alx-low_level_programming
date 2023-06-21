#include "main.c"

/**
 * print_sign - prints the sign number
 * @n: the number to be checked
 * Return: 1 for positive num, -1 got negative num or zerp for anything else
 */

int print_sin(int n)

{

	if (n > 0)
	{
	_putchar(43);
	return (1);
	}
	else if (n < 0)
	{
	_putchar(45);
	return (-1)
	}
	else
	{
	_putchar(48);
	return (0);
	}
}
