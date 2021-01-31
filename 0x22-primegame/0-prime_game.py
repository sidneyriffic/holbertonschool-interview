#!/usr/bin/python3
"""Pick primes out of a list until none are left"""


def primes_list(n):
    """Return list of prime numbers up to and including n."""
    primes = []
    x = 1
    while x < n:
        prime = 1
        x += 1
        for num in primes:
            if not x % num:
                prime = 0
                break
        if prime:
            primes.append(x)
    return primes


def isWinner(x, nums):
    """
    Take turns picking primes out of a list of 1 to n until none are left
    or x maximum moves. Whoever chooses the last prime number wins.
    First player is Maria, second is Ben. nums is a list of ns. Return
    name of who wins the most games.
    """
    winners = [0, 0]
    if (len(nums) < x):
        return None
    i = 0
    for n in nums:
        if i >= x:
            break
        winners[len(primes_list(n)) % 2] += 1
        i += 1
    if winners[0] == winners[1]:
        return None
    if winners[0] < winners[1]:
        return 'Maria'
    return 'Ben'
