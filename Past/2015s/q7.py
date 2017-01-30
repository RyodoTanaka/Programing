#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

if __name__ == '__main__':
    f = open(sys.argv[1], 'r')
    past_line=""
    print_str=[]
    printed_list=[]
    for line in f.read().split('\n'):
        if line==past_line:
            print_str.append(line)
        else:
            del print_str[:]
            
        if len(print_str)==3:
            if print_str[0] not in printed_list:
                for i in range(len(print_str)+1):
                    print print_str[0]
                printed_list.append(print_str[0])
        past_line=line
    f.close()
