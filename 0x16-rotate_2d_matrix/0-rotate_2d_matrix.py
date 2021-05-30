#!/usr/bin/python3
"""Given an n x n 2D matrix, rotate it 90 degrees clockwise"""


def rotate_2d_matrix(matrix):
    """In place rotation of 2D matrix"""
    nested = len(matrix[0])
    for i in range(nested // 2):
        for j in range(i, nested - i - 1):
            temp = matrix[i][j]
            matrix[i][j] = matrix[nested - 1 - j][i]
            matrix[nested - 1 - j][i] = matrix[nested - 1 - i][nested - 1 - j]
            matrix[nested - 1 - i][nested - 1 - j] = matrix[j][nested - 1 - i]
            matrix[j][nested - 1 - i] = temp
