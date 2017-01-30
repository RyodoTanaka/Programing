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
        result.append((161*result[i-1]+2457)%(2**24))
    return result[-1]

if __name__ == '__main__':
    print fnc(int(sys.argv[1]))
