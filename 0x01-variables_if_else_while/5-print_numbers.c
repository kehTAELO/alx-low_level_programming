#include <stdio.h>

#include <stdlib.h>

#include <time.h>


/**
 * main - entry point 
 *description: ptints numbers from 0 to 9.
 * Return: Always 0
 */
int main(void)
{
	int d;
	for(d = '0'; d <= '9'; d++)
	putchar(d);
	putchar('\n');

	return (0);
}
