#!/usr/bin/python3
"""Two players take turns removing prime numbers and multiples from integer
list until none remain"""


def isWinner(x, nums):
    """Two players take turns (up to x rounds) removing prime numbers and
    multiples from integer list until none remain"""
    turn = 0
    firstprime = 0
    nums = sorted(nums)
    if len(nums) == 0 or x < 1:
        return None
    while nums[firstprime] < 2:
        firstprime += 1
        if firstprime >= len(nums):
            return None
    nums = nums[firstprime:]
    while nums and turn < x:
        prime = nums[0]
        nums = [x for x in nums if x % prime]
        turn += 1
    if turn % 2:
        return "Ben"
    return "Maria"
