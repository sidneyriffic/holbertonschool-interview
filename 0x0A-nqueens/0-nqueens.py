#!/usr/bin/python3
"""Solve the nqueens problem"""

import sys


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
try:
    size = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    exit(1)
if size < 4:
    print("N must be at least 4")
    exit(1)


def nqueen_solver(size, y, queens):
    """Solve the nqueens problem"""
    for x in range(size):
        threat = 0
        for queen in queens:
            if x == queen[1]:
                threat = 1
                break
            if y - x == queen[0] - queen[1]:
                threat = 1
                break
            if x - queen[1] == queen[0] - y:
                threat = 1
                break
        if threat == 0:
            queens.append([y, x])
            if y != size - 1:
                nqueen_solver(size, y + 1, queens)
            else:
                print(queens)
            del queens[-1]


nqueen_solver(size, 0, [])
