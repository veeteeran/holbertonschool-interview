#!/usr/bin/python3
"""Rain interview question"""


def rain(walls):
    """Rain interview question"""
    rain = 0
    # Loop through the array
    for i in range(1, len(walls)):
    # At each index from start to index -> left wall getMax
        left = max(walls[0:i + 1])
    # From index to end -> right wall getMax
        right = max(walls[i:len(walls)])
    # Get min(left_wall, right_wall)
        minHeight = min(left, right)
    # rain_water += min(left_wall, right_wall) - arr[i]
        if minHeight - walls[i] < 0:
            continue
        else:
            rain += minHeight - walls[i]

    return rain
