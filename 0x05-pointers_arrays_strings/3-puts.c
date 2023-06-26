#include "main.h"
/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: string to output
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		putchar(*str++);
	}
	putchar('\n');
}
