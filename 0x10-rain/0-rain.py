#!/usr/bin/python3
"""Rain gets trapped between walls with heights indicated by an array."""


def rain(walls):
    """Rain gets trapped between walls with heights indicated by an array."""
    if len(walls) == 0:
        return 0
    leftraise = []
    rightraise = []
    prevwall = 0
    for idx, wall in enumerate(walls):
        if wall > prevwall:
            leftraise.append(idx)
            prevwall = wall
    prevwall = 0
    for idx, wall in enumerate(walls[::-1], 1):
        if wall > prevwall:
            rightraise.append(-idx)
            prevwall = wall
    water = 0
    for sidx, widx in enumerate(leftraise[:-1]):
        water += walls[widx] * (leftraise[sidx + 1] - widx)
    for sidx, widx in enumerate(rightraise[:-1]):
        water += walls[widx] * (-rightraise[sidx + 1] + widx)
    water += ((len(walls) + 1 + rightraise[-1] - leftraise[-1]) *
              walls[leftraise[-1]])
    return water - sum(walls)
