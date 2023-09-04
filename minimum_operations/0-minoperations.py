#!/usr/bin/python3
"""
In a text file, there is a single character H. Your text editor can execute only
two operations in this file: Copy All and Paste. Given a number n,
write a method that calculates the fewest number of operations
needed to result in exactly n H characters in the file.
"""

def minOperations(n):
    """
    defines minOperations, where n is the number of H we want in the file
    Return the number of operations needed to have n H characters in the file
    If impossible, return 0
    """
    if (n < 2):
        return 0
    res = 0
    i = 2
    while i <= n:
        if n % i == 0:
            res += i
            n = n / i
            i = i - 1
        i = i + 1
    return int(res)
