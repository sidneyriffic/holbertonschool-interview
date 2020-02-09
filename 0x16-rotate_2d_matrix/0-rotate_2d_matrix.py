#!/usr/bin/python3
"""Rotate a 2d matrix 90 degrees clockwise"""


def rotate_2d_matrix(matrix):
    """Rotate a 2d matrix 90 degrees clockwise"""
    size = len(matrix)
    for x in range(size + size % 2 - 2):
        for y in range(x, size - x - 1):
            if x <= y:
                temp = matrix[x][y]
                matrix[x][y] = matrix[size - y - 1][x]
                matrix[size - y - 1][x] = matrix[size - x - 1][size - y - 1]
                matrix[size - x - 1][size - y - 1] = matrix[y][size - x - 1]
                matrix[y][size - x - 1] = temp
    if len(matrix) == 2:
        temp = matrix[0][0]
        matrix[0][0] = matrix[1][0]
        matrix[1][0] = matrix[1][1]
        matrix[1][1] = matrix[0][1]
        matrix[0][1] = temp
