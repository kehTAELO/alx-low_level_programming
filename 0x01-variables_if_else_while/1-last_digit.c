#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 *Description: 'randomly prints the last digit of a generated number where it is greater than 5, less than 6,or 0.'
 * return: always 0
 */
int main (void)
{
	int n;
	int ld;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	ld = n % 10;

	if ((n % 10) > 5)
	{
		printf(last digit of %d is %d and is greater than 5/n", n, ld);
	}
	else if ((n % 10) < 6 && (n % 10) !=0)
	{
		printf("last digit of %d is % and is 0/n", n, ld);
	
	else 
	{
		printf("Last digit of %d is %d and is not 0/n", n, ld);
	}

	return (0);
}
	


			
