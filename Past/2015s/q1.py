#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

if __name__ == '__main__':
    f = open(sys.argv[1], 'r')
    num_of_semi_colon = 0
    for line in f.read().split(';'):
        num_of_semi_colon+=1
    print num_of_semi_colon-1
    f.close()
