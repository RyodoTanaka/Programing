#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

def fnc(n):
    if n<1:
        return 1
    else:
        return (161*fnc(n-1)+2457)%2**24

if __name__ == '__main__':
    cnt=0;
    for i in range(0,99):
        if fnc(i)%2==0:
            cnt+=1
    print cnt
