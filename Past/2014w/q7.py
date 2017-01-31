#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys
import datetime

def func(x):
    print ((1.+math.sqrt(5.))/2.)**float(x)/math.sqrt(5.)
    return str(((1.+math.sqrt(5.))/2.)**float(x)/math.sqrt(5.))

if __name__ == '__main__':
    result=func(140)
    print_str=""
    for i in result:
        if i!='.':
            print_str = print_str + i
    for i in range(len(result), 33):
        print_str = print_str + "0"
    sys.stdout.write(print_str)
    sys.stdout.write(" 01")
    print
