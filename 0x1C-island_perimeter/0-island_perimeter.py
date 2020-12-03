#!/usr/bin/python3
"""Return outer perimeter of an island defined by 1/0 encoding in a 2d list."""


def island_perimeter(grid):
    """
    Return outer perimeter of an island
    defined by 1/0 encoding in a 2d list.
    """
    perimeter = 0
    for x in range(len(grid)):
        for y in range(len(grid[x])):
            if grid[x][y] == 1:
                if x == 0:
                    perimeter += 1
                elif grid[x - 1][y] == 0:
                    perimeter += 1
                if y == 0:
                    perimeter += 1
                elif grid[x][y - 1] == 0:
                    perimeter += 1
                if x == len(grid) - 1:
                    perimeter += 1
                elif grid[x + 1][y] == 0:
                    perimeter += 1
                if y == len(grid[0]) - 1:
                    perimeter += 1
                elif grid[x][y + 1] == 0:
                    perimeter += 1
    return perimeter
