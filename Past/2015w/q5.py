#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

def fnc(n):
    if n<1:
        return 1
    result=[]
    result.append(1)
    for i in range(1,n+1):
        result.append((1103515245*result[i-1]+12345)%(2**26))
    return result[-1]

if __name__ == '__main__':
    print fnc(int(sys.argv[1]))
