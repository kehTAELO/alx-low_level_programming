#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - entry point
 * description: prints the lowercase alphabet in reverse.
 * return: 0
 */
int main(void)
{
	char low;

	for (low = 'z'; low >= 'a'; low--);
	putchar(low);
	putchar('\n');


	return (0);
}
