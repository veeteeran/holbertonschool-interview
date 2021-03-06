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
        # bitmask to pull least significant 8 bits
        d = data[index] & mask
        # Valid 1 byte values
        if d < 128:
            index += 1
            continue
        try:
            # bitmask to pull least significant 8 bits
            d = data[i] & mask
            # This range signifies a 2 byte block
            if d > 191 and d < 224:
                byte_two = data[i + 1] & mask
                if byte_two > 127 and byte_two < 192:
                    index += 1
                    continue
                else:
                    return False
            # This range signifies a 3 byte block
            if d > 223 and d < 240:
                byte_two = data[i + 1] & mask
                byte_three = data[i + 2] & mask
                if (byte_two > 127 and byte_two < 192) and (byte_three > 127 and byte_three < 192):
                    index += 2
                    continue
                else:
                    return False
            # This range signifies a 4 byte block
            if d > 239 and d < 248:
                byte_two = data[i + 1] & mask
                byte_three = data[i + 2] & mask
                byte_four = data[i + 3] & mask
                if (byte_two > 127 and byte_two < 192) and (byte_three > 127 and byte_three < 192) and (byte_four > 127 and byte_four < 192):
                    index += 3
                    continue
            else:
                    return False
        except:
            return False
        index += 1

    return True
