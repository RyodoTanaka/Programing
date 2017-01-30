#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

if __name__ == '__main__':
    f = open(sys.argv[1], 'r')
    str_data=[]
    str_line=[]
    str_num=[]
    line_num=0
    for line in f.read().split('\n'):
        line_num+=1
        if line not in str_data:
            str_data.append(line)
            str_line.append(line_num)
            str_num.append(1)
        else:
            str_num[str_data.index(line)]+=1
    for i in range(len(str_num)):
        if str_num[i]>1:
            print str_data[i]
    f.close()
