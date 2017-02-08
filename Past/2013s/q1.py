#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

if __name__ == '__main__':
    f = open(sys.argv[1], 'r')
    num_of_space=0
    for line in f.readlines():
        num_of_space=0
        line=line.rstrip()
        for word in line.split(' '):
            if num_of_space==1:
                print word
            num_of_space+=1
