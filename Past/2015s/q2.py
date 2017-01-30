#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

if __name__ == '__main__':
    f = open(sys.argv[1], 'r')
    num_line=0
    for line in f.read().split('\n'):
        index=-1
        num_line+=1
        index = line.find("main")
        if index==-1:
            continue
        else:
            sys.stdout.write(str(num_line))
            sys.stdout.write(" ")
            sys.stdout.write(line)
            print
    f.close()
