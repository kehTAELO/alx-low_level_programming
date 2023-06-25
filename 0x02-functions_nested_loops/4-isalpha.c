#include "main.h"

/**
 * _isalpha - Checks for aphabetic character
 * @c: The character to be checked
 * Return: 1 for aphabetic character or 0 for anything else
 */

int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= "z"));
}
