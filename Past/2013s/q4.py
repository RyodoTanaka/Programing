#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

def ADD(order1, order2, dict):
    if order2 not in dict: # bが存在しなかったら
        order2=0
    if order1 not in dict: # aが変数じゃなかったら
        dict[order2] = int(order1) + int(dict[order2])
    else: # aが変数だったら
        dict[order2] = int(dict[order1]) + int(dict[order2])

def PRN(order1, order2, dict):
    if order1 not in dict: # aは数字
        sys.stdout.write(order1)
    else: # aは変数
        sys.stdout.write(str(dict[order1]))
    sys.stdout.write(", ")
    if order2 not in dict: # bは数字
        sys.stdout.write(order2)
    else: # bは変数
        sys.stdout.write(str(dict[order2]))
    print

def SET(order1, order2, dict):
    if order2 not in dict: # bが変数じゃなかったら
        dict[order1] = int(order2)
    else: # bが変数だったら
        dict[order1] = dict[order2]

def is_same(order1, order2, dict):
    a=int()
    b=int()
    if order1 not in dict: # aは数字
        a=int(order1)
    else: # aは変数
        a=dict[order1]
    if order2 not in dict: # bは数字
        b=int(order2)
    else: # bは変数
        b=dict[order2]

    if a==b:
        return True
    else:
        return False

def JMP(order, dict):
    if order not in dict: # aは数字
        return int(order)
    else: # aは変数
        return dict[order]

    
if __name__ == '__main__':
    f = open(sys.argv[1], 'r')
    program=f.read()
    line = program.split('\n')
    dict={}
    i=0
    while i<len(line):
        order=line[i].split(' ')
        if(order[0]=="ADD"):
            ADD(order[1], order[2], dict)
        if(order[0]=="PRN"):
            PRN(order[1], order[2], dict)
        if(order[0]=="SET"):
            SET(order[1], order[2], dict)
        if(order[0]=="CMP"):
            if is_same(order[1], order[2], dict):
                i+=2
                continue
        if(order[0]=="JMP"):
            i+=JMP(order[1],dict)
            continue
        i+=1
