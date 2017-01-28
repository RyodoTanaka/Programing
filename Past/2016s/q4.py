#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

if __name__ == '__main__':
    NUM=8
    dic_data={'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
    data=raw_input()
    result=0
    for i in range(len(data)):
        if data[i]=='I' and (data[i+1]=='V' or data[i+1]=='X'):
            result-=dic_data[data[i]]
            continue
        if data[i]=='X'and (data[i+1]=='L' or data[i+1]=='C'):
            result-=dic_data[data[i]]
            continue
        if data[i]=='C' and (data[i+1]=='D' or data[i+1]=='M'):
            result-=dic_data[data[i]]
            continue
        result+=dic_data[data[i]]
    print result
