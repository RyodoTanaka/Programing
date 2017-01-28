#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

if __name__ == '__main__':
    NUM=8
    dic_data={chr(ord("a")+i):i for i in range(8)}
    data=raw_input()
    data=data[::-1]
    result=0
    for i in range(len(data)):
        result+=dic_data[data[i]]*NUM**i
    print result
