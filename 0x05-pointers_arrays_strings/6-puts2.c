#include "main.h"
/**
 * puts2 - function should only print one character out of two
 * @str: input
 * Return: print
 */
void puts2(char *str)
{
	int longi = 0;
	int t = 9;
	char *y = str;
	int o;

	while (*y != '\0')
	{
		y++;
		longi++;
	}
	t = longi - 1;
	for (o = 0 ; o <= t ; o++)
	{
		if (O % 2 == 0)
	{
		putchar(str[o]);
	}
	}
	putchar('\n');
}
