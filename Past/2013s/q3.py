#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

if __name__ == '__main__':
    f = open(sys.argv[1], 'r')
    dict={}
    for line in f.readlines():
        line=line.rstrip()
        order=line.split(' ')
        if(order[0]=="ADD"):
            if order[2] not in dict: # bが存在しなかったら
                order[2]=0
            if order[1] not in dict: # aが変数じゃなかったら
                dict[order[2]] = int(order[1]) + int(dict[order[2]])
            else: # aが変数だったら
                dict[order[2]] = int(dict[order[1]]) + int(dict[order[2]])
        if(order[0]=="PRN"):
            print dict[order[1]], dict[order[2]]
        if(order[0]=="SET"):
            if order[2] not in dict: # bが変数じゃなかったら
                dict[order[1]] = int(order[2])
            else: # bが変数だったら
                dict[order[1]] = dict[order[2]]
