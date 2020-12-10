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
    locked = list(range(1, len(boxes)))
    was_locked = len(locked)
    keys = boxes[0]

    while locked:
        for key in keys:
            if key in locked:
                locked.remove(key)
                keys.extend(boxes[key])

        # If these are equal no further boxes unlocked
        if len(locked) == was_locked:
            return False

        was_locked = len(locked)

    return True

if __name__ == '__main__':
    canUnlockAll(boxes)
