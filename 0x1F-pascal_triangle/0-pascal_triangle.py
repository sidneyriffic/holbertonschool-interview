#!/usr/bin/python3
"""
Function that returns a list of lists of integers
representing Pascal's triangle of depth n.
"""


def pascal_triangle(n):
    """
    Returns a list of lists of integers representing
    Pascal's triangle of depth n.
    """
    if n <= 0:
        return []
    triangle = [[1]]
    for i in range(1, n):
        line = []
        for x in range(i + 1):
            if x == 0:
                line.append(1)
            elif x != i:
                line.append(triangle[i - 1][x - 1]
                            + triangle[i - 1][x])
            else:
                line.append(1)
        triangle.append(line)
    return triangle
