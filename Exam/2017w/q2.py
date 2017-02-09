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

    # print list
    # print len(list)
    del list[""]
    cnt=0
    for k, v in sorted(list.items(), key=lambda x: x[1], reverse=True):
        if cnt<5:
            print k, v
            cnt+=1
