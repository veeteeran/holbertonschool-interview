#!/usr/bin/python3
"""Pascal's Triangle"""


def pascal_triangle(n):
    """
        Returns a list of lists of integers representing
        Pascal's triangle of n
    """
    result = []

    if n <= 0:
        return result

    for row_num in range(n):
        row = [None for _ in range(row_num + 1)]
        row[0], row[-1] = 1, 1

        for j in range(1, len(row) - 1):
            row[j] = result[row_num - 1][j - 1] + result[row_num - 1][j]

        result.append(row)

    return result
