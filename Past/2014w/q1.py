#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

def func(x):
    if x<=2:
        return 1
    else:
        result=[]
        result.append(1)#0
        result.append(1)#1
        result.append(1)#2
        for i in range(2,x+1):
            result.append(result[i-1]+result[i-2])
        return result[-1]

if __name__ == '__main__':
    print func(10)
