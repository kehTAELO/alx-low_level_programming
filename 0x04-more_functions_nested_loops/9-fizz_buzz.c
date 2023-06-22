#include <stdio.h>
#include "main.h"

/**
 * main - entry point
 *
 * descri[ption: prints the numbers 1 - 100 
 * fizz for multiples of 3,buzz for multiples of 5.
 * and fiz buss for multiplies of both
 *
 * return: always 0
 */
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 15 == 0)
			printf("fizzbuzz");
		else if (i % 3 = o)
			printf("fizz");
		else if (i % 5 == 0)
			printf("buzz");
		else
			printf("%i", 1);
		if (i < 100)
			printf(" ");
	}
	printf("\n")
	return (0);
}
