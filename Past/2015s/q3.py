#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

if __name__ == '__main__':
    f = open(sys.argv[1], 'r')
    past_line=""
    for line in f.read().split('\n'):
        if line==past_line:
            sys.stdout.write(line)
            print
        past_line=line
    f.close()
