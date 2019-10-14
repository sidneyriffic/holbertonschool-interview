#include <stddef.h>

#include "slide_line.h"

int slide_line(int *line, size_t size, int direction)
{
	size_t parseidx, slideidx;
	int last = 0, change;

	if (line == NULL)
		return (0);
	if (size <= 0)
		return (0);
	if (direction == SLIDE_LEFT)
	{
		change = 1;
		slideidx = 0;
		parseidx = 0;
	}
	else if (direction == SLIDE_RIGHT)
	{
		change = -1;
		slideidx = size - 1;
		parseidx = slideidx;
	}
	else
		return (0);
	while (parseidx < size)
	{
		if (line[parseidx] == 0)
		{
			parseidx += change;
			continue;
		}
		if (last == line[parseidx])
		{
			line[slideidx] = last * 2;
			slideidx += change;
			last = 0;
		}
		else if (last != 0)
		{
			line[slideidx] = last;
			slideidx += change;
			last = line[parseidx];
		}
		else
			last = line[parseidx];
		line[parseidx] = 0;
		parseidx += change;
	}
	if (last != 0)
		line[slideidx] = last;
	return (1);
}
