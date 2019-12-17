#!/usr/bin/env python

###############################################################################
# zjw 20191216
###############################################################################

import numpy as np

def sense_and (x1, x2):
    w1 = 0.5
    w2 = 0.5
    theta = 0.7

    temp = x1 * w1 + x2 * w2

    if temp > theta:
        return 1
    else:
        return 0


if __name__ == "__main__":
    input1 = 1
    input2 = 1
    result = sense_and(input1, input2)
    print("the result is: %s" % result) 