#!/usr/bin/python3
"""
    You have n number of locked boxes in front of you. Each box is numbered
    sequentially from 0 to n - 1 and each box may contain keys to the other
    boxes.
"""


def canUnlockAll(boxes):
    """
    --------------
    METHOD: canUnlockAll
    --------------
    Description:
        Determines if all the boxes can be opened
        Return True if all boxes can be opened, else return False
    Args:
        @boxes: a list of lists
                contains keys (int values) to other boxes
    --------------
    """
    unique_list = list(set(boxes[0]))
    for i in range(len(boxes)):
        for j in unique_list:
            if j > len(boxes):
                unique_list.remove(j)
                continue
            # Get unique values from each list
            values = set(boxes[j]) - set(unique_list)
            # Create a new list
            unique_list = unique_list + list(values)

    # First box is always unlocked zero index doesn't matter
    if (0 in unique_list):
        unique_list.remove(0)
    # Create a list of keys to compare against
    all_keys = list(range(1, len(boxes)))
    unique_list = sorted(unique_list)
    if (unique_list == all_keys):
        return True
    return False

if __name__ == '__main__':
    canUnlockAll(boxes)
