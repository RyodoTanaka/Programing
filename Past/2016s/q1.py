#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

if __name__ == '__main__':
    NUM=4
    # get data
    data = input()
    # 何乗が最高か調べる
    x=int(math.log(data)/math.log(NUM))
    result = [0] * (x+1)
    result[x]+=1
    tmp_data=data-(NUM**x)
    while True:
        if tmp_data==0:
            break
        x=int(math.log(tmp_data)/math.log(NUM))
        result[x]+=1
        tmp_data-=NUM**x

    result.reverse()
    for value in result:
        sys.stdout.write(str(value))
    print
