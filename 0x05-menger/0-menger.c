#include <stdio.h>

/**
 * menger - prints a menger cube of a given level, or nothing
 * if level < 0
 * @level: level of menger cube
 */
void menger(int level)
{
	long size, check, row, col;

	if (level < 0)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}
	for (size = 1; level > 0; level--)
		size *= 3;
	for (row = 1; row <= size; row++)
	{
		for (col = 1; col <= size; col++)
		{
			for (check = 1; check <= size; check *= 3)
			{
				if (row % check * 3 <= check * 2 &&
				    row % check * 3 >= check + 1 &&
				    col % check * 3 <= check * 2 &&
				    col % check * 3 >= check + 1)
				{
					printf(" ");
					break;
				}
			}
			if (check > size)
				printf("#");
		}
		printf("\n");
	}
}
