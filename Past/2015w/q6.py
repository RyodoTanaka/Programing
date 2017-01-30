#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

def fnc(n):
    if n<1:
        return 1
    result=[]
    answer=0
    result.append(1)
    print "start finding..."
    for i in range(1,n+1):
        answer = (1103515245*result[i-1]+12345)%(2**26)
        if :
            print i, answer
            index=result.index(answer)
            print index, result[index]
            break
        result.append(answer)

if __name__ == '__main__':
    fnc(int(sys.argv[1]))
