#!/usr/bin/python3
"""Rain trapping programming challenge"""


def rain(walls):
    """Rain is trapped between walls with heights indicated by an array."""
    if len(walls) == 0:
        return 0
    leftstack = []
    rightstack = []
    prevwall = 0
    for idx, wall in enumerate(walls):
        if wall > prevwall:
            leftstack.append(idx)
            prevwall = wall
    prevwall = 0
    for idx, wall in enumerate(walls[::-1], 1):
        if wall > prevwall:
            rightstack.append(-idx)
            prevwall = wall
    water = 0
    for sidx, widx in enumerate(leftstack[:-1]):
        water += walls[widx] * (leftstack[sidx + 1] - widx)
    for sidx, widx in enumerate(rightstack[:-1]):
        water += walls[widx] * (-rightstack[sidx + 1] + widx)
    water += ((len(walls) + 1 + rightstack[-1] - leftstack[-1])
              * walls[leftstack[-1]])
    return water - sum(walls)
