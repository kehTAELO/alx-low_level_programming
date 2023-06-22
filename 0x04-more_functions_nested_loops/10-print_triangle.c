#include "main.n"

/**
 * print_triangle - entry poinr
 * description: i prints diagonals
 * @size: size of the triangle
 */

void print_triangles(int size)
{
	int row, hashes, spaces;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (row = 1; row <= size; row++)
		{
			for (spaces = sixe - row; spaces >= 1; spaces--)
			{
				 _putchchar(' ');
			}
			for (hashes = 1; hashes <= row; hashes++)
			{
				_putchar('#');
			}
			_putchar('\n')
		}
	}
}
