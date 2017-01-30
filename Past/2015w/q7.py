#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

def fnc(n):
    if n<1:
        return 1
    result=[]
    answer=0
    dict_data={i:0 for i in range(2**10)}
    min_k=n
    result.append(1)
    print "start finding..."
    for i in range(1,n+1):
        answer = (1103515245*result[i-1]+12345)%(2**26)%(2**10)
        dict_data[answer]+=1
        if dict_data[answer]==2:
            # print i, answer
            index=result.index(answer)
            # print index, result[index]
            if i-index<min_k:
                min_k=i-index
        result.append(answer)
    print "min_k =", min_k

if __name__ == '__main__':
    fnc(int(sys.argv[1]))
