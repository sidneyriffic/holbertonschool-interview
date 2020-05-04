#!/usr/bin/python3
"""Return list containing pascal's triangle up to row n"""


def pascal_triangle(n):
    """Return list containing pascal's triangle up to row n"""
    if n <= 0:
        return []
    triangle = [[1]]
    for row in range(n - 1):
        newrow = [1]
        for col in range(len(triangle[row]) - 1):
            newrow.append(triangle[row][col] + triangle[row][col + 1])
        newrow.append(1)
        triangle.append(newrow)
    return triangle
