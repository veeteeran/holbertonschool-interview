#!/usr/bin/python3
"""Reads stdin line by line and computes metrics"""
from sys import stdin, stdout
import traceback


if __name__ == "__main__":
    # save as a dict using key/value
    my_dict = {}
    file_size = 0
    counter = 0
    try:
        # open and read file
        for line in stdin:
            # Check if line is empty
            if line is None:
                continue

            file_size += int(line.split()[-1])
            # Status code is key, value is number of occurences
            status_code = int(line.split()[-2])
            if status_code in my_dict:
                my_dict[status_code] += 1
            else:
                my_dict[status_code] = 1

            counter += 1
            # Print after ten lines (keep track in a variable)
            if counter % 10 == 0:
                print("File size: {}".format(file_size))
                # Print status code in ascending order, sort by key(?)
                for k in sorted(my_dict):
                    print("{}: {}".format(k, my_dict[k]))

        print("File size: {}".format(file_size))
        # Print status code in ascending order, sort by key(?)
        for k in sorted(my_dict):
            print("{}: {}".format(k, my_dict[k]))
    # Print after keyboard interrupt CTRL+C
    except KeyboardInterrupt as e:
        print("File size: {}".format(file_size))
        # Print status code in ascending order, sort by key(?)
        for k in sorted(my_dict):
            print("{}: {}".format(k, my_dict[k]))
    #    print("This is e", e)
    #    traceback.print_exc(file=stdout)
    #    traceback.print_exc(limit=2, file=stdout)
        raise
