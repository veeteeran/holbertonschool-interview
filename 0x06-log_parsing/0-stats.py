#!/usr/bin/python3
"""Reads stdin line by line and computes metrics"""
from sys import stdin, stdout
import traceback


# save as a dict using key/value
my_dict = {0: 0}
counter = 0
try:
    # open and read file
    for line in stdin:
        # Starting from the end iterate backwards to find quote
        index = -1
        while line[index] != '"':
            index -= 1
        # Add 2 to index to get back to start of status code
        index += 2
        line = line[index:]
        # File size is key, value is size in bytes
        size = int(line[4:])
        my_dict[0] += size

        # Status code is key, value is number of occurences
        status_code = int(line[0:3])
        if status_code in my_dict:
            my_dict[status_code] += 1
        else:
            my_dict[status_code] = 1

        counter += 1
        # Print after ten lines (keep track in a variable)
        if counter % 10 == 0:
            # Print status code in ascending order, sort by key(?)
            for k in sorted(my_dict):
                if k == 0:
                    print("File size: {}".format(my_dict[k]))
                else:
                    print("{}: {}".format(k, my_dict[k]))
# Print after keyboard interrupt CTRL+C
except KeyboardInterrupt as e:
    for k in sorted(my_dict):
        if k == 0:
            print("File size: {}".format(my_dict[k]))
        else:
            print("{}: {}".format(k, my_dict[k]))

#    print("This is e", e)
#    traceback.print_exc(file=stdout)
#    traceback.print_exc(limit=2, file=stdout)
    raise
