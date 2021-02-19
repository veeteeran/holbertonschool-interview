#!/usr/bin/python3
"""
Determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    if data == []:
        return True

    length = len(data)
    mask = 255
    index = 0
    while (index < length):
        if data[index] < 0:
            return False
        try:
            if type(data[index]) is not int:
                return False
            # bitmask to pull least significant 8 bits
            d = data[index] & mask
            # Continuation block without a header
            if d > 127 and d < 192:
                return False
            # This range signifies a 2 byte block
            if d > 191 and d < 224:
                byte_two = data[index + 1] & mask
                if byte_two > 127 and byte_two < 192:
                    index += 2
                else:
                    return False
            # This range signifies a 3 byte block
            if d > 223 and d < 240:
                byte_two = data[index + 1] & mask
                byte_three = data[index + 2] & mask
                if (byte_two > 127 and byte_two < 192)\
                        and (byte_three > 127 and byte_three < 192):
                    index += 3
                else:
                    return False
            # This range signifies a 4 byte block
            if d > 239 and d < 248:
                byte_two = data[index + 1] & mask
                byte_three = data[index + 2] & mask
                byte_four = data[index + 3] & mask
                if (byte_two > 127 and byte_two < 192)\
                        and (byte_three > 127 and byte_three < 192)\
                        and (byte_four > 127 and byte_four < 192):
                    index += 4
                else:
                    return False
        except IndexError:
            return False
        else:
            # All other values are valid, move to next element
            index += 1
    return True
