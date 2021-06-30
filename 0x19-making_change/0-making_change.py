#!/usr/bin/python3
"""Function to make change"""


def makeChange(coins, total):
    """
        Determine the fewest number of coins
        needed to meet a given amount total
    """
    if total <= 0:
        return 0

    s = [0]
    for i in range(1, total + 1):
        s.append(-1)
        for coin in coins:
            if (i - coin >= 0 and s[i - coin] != -1 and
               (s[i] > s[i - coin] or s[i] == -1)):
                s[i] = 1 + s[i - coin]

    return s[total]
