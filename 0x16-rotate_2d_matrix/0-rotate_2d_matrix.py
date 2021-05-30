#!/usr/bin/python3
"""Given an n x n 2D matrix, rotate it 90 degrees clockwise"""


def rotate_2d_matrix(matrix):
	"""In place rotation of 2D matrix"""
	nestedLen = len(matrix[0])
	for i in range(nestedLen // 2):
		for j in range(i, nestedLen - i - 1):
			temp = matrix[i][j]
			matrix[i][j] = matrix[nestedLen - 1 - j][i]
			matrix[nestedLen - 1 - j][i] = matrix[nestedLen - 1 - i][nestedLen - 1 - j]
			matrix[nestedLen - 1 - i][nestedLen - 1 - j] = matrix[j][nestedLen - 1 - i]
			matrix[j][nestedLen - 1 - i] = temp
