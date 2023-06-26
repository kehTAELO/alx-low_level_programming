#include <stdlib.h>

#include <time.h>

#include <stdio.h>


/**
 * main - Entry point
 * Description: 'randomly prints the last digit of a generated number'
 * return: Always
 */
int main (void)

{

	int n, lastd;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lastd = n % 10;

	if (lastd > 5)
	{
	printf("last digit of %d is %d and is greater than 5\n", n, lastd);
	}
	else if (lastd == 0)
	{
	printf("last digit of %d is %d and is 0\n", n, lastd);
	}
	else if (lastd < 6 && lastd != 0)
	{
	printf("last digit of %d is %d and is less than 6 and is not 0\n", n, lastd);
	}
	return (0);
}
