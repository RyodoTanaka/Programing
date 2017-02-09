#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

if __name__ == '__main__':
    f = open("./data/foo.py", 'r')
    program=f.read()
    line = program.split('\n')
    buf=str()
    list={}
    for i in range(len(line)):
        line[i]+=" "
        for j in range(len(line[i])):
            if (ord("a") <= ord(line[i][j]) and ord(line[i][j]) <= ord("z")) or (ord("A") <= ord(line[i][j]) and ord(line[i][j]) <= ord("Z")):
                buf=buf + line[i][j].lower()
            else:
                if buf in list:
                    list[buf]+=1
                else :
                    list[buf]=1
                buf=""

    del list[""]
    list_sorted = sorted(list.items(), key=lambda x: x[0])
    input_str=raw_input()
    input_str=input_str.lower()
    print_flg=False
    print_str=str()
    # まず一致する場合を考える
    if input_str in list:
        print input_str
    else:
        list[input_str]=1
        for k, v in sorted(list.items(), key=lambda x: x[0]):
            if print_flg:
                print_str = k
                print_flg=False
            if k==input_str:
                print_flg=True
        if print_str=="":
            print "nothing"
        else:
            print print_str
