#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @w: number to print in binary
 */

void print_binary(unsigned long int w)
{
int t, count = 0;
unsigned long int current;
for (t = 63; t >= 0; t--)
{
current = w >> t;
if (current & 1)
{
_putchar('1');
count++;
}
else if (count)
_putchar('0');
}
if (!count)
_putchar('0');
}
