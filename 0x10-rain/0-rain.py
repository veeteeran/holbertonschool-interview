#!/usr/bin/python3
"""Rain interview question"""


def rain(walls):
    """Rain interview question"""
    rain = 0
    for i in range(1, len(walls)):
        left = max(walls[0:i + 1])
        right = max(walls[i:len(walls)])
        minHeight = min(left, right)
        if minHeight - walls[i] < 0:
            continue
        else:
            rain += minHeight - walls[i]

    return rain
