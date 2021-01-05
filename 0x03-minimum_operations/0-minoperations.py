#!/usr/bin/python3
"""Function to find or help find minimum operations"""


def minOperations(n):
    """
        Calculates the fewest number of operations needed to result
        in exactly n H characters in the file.
    """
    if n < 2:
        return 0

    summation = []

    while n % 2 == 0:
        summation.append(2)
        n = n // 2

    for i in range(3, n + 1, 2):
        while n % i == 0:
            summation.append(i)
            n = n // i

    return (sum(summation))
