#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

def fnc(n):
    if n<1:
        return 1
    else:
        return (161*fnc(n-1)+2457)%(2**24)

if __name__ == '__main__':
    print fnc(int(sys.argv[1]))
