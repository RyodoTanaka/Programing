#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys
import datetime

def func(i1, i2):
    input1=i1[::-1]
    input2=i2[::-1]
    a=[int(i) for i in input1]
    b=[int(i) for i in input2]
    d=[0 for i in range(len(i1))]
    f=[]
    # ゼロ桁目を追加
    a.insert(0,0)
    b.insert(0,0)
    d.insert(0,0)
    f.append(0)
    for i in range(1,len(a)):
        f.append((a[i]+b[i]+d[i-1])%10)
        d[i]=int((a[i]+b[i]+d[i-1])//10)
    # 33桁のうち、0桁目を削除
    del f[0]
    # 表示用に反転
    f=f[::-1]
    return f

if __name__ == '__main__':
    input1=raw_input()
    input2=raw_input()
    #input1="00123456789012345678901234567890"
    #input2="00987654321098765432109876543210"
    for i in func(input1, input2):
        sys.stdout.write(str(i))
    print
