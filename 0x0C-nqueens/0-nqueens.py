#!/usr/bin/python3
"""Docstring for nqueens"""


def getNQueens():
    """Checks for proper usage and valid input"""
    from sys import argv
    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    try:
        n = int(argv[1])

        if n < 4:
            print("N must be at least 4")
            exit(1)
    except ValueError:
        print("N must be a number")
        exit(1)

    return n


def printSolution(columns):
    """Print coordinates on an N x N board"""
    result = []
    for i in range(len(columns)):
        result.append([i, columns[i]])
    print(result)


def nQueens():
    """Helper function that calls other functions"""
    n = getNQueens()
    # column number stored, the index of each element is the row
    columns = []
    row = 0
    col = solveNQueens(n, row, columns)


def solveNQueens(n, row, columns):
    """
        Attempts to place queens in valid squares

            Parameters:
                    n: number of queens to place
                    row: row where queen is placed
                    columns: an array containing columns where Qs are placed
    """
    if row == n:
        printSolution(columns)
    else:
        for col in range(n):
            columns.append(col)
            if(isValid(columns)):
                solveNQueens(n, row + 1, columns)
            columns.pop()


def isValid(columns):
    """
        Checks if queen will be attacked in a certain square

            Parameter:
                    columns: an array containing columns where Qs are placed

            Return: True if valid, False otherwise
    """
    # Length of columns array - 1 is the current row where Q is placed
    row = len(columns) - 1
    for i in range(row):
        diff = abs(columns[row] - columns[i])
        if diff == 0 or diff == row - i:
            return False

    return True


if __name__ == "__main__":
    nQueens()
