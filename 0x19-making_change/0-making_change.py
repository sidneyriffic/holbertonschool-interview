#!/usr/bin/python3
"""Return minimum number of coins that equals total"""


def makeChange(coins, total):
    """Return minimum number of coins that equals total"""
    coins = sorted(coins, reverse=True)
    change = 0
    for coin in coins:
        change += total // coin
        total %= coin
    if total:
        return -1
    return change
