#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys
import datetime

def func(input11, input12, input21, input22):
    i11=input11[::-1]
    i12=input12[::-1]
    i21=input21[::-1]
    i22=input22[::-1]
    a1=[int(i) for i in i11]
    a2=[int(i) for i in i21]
    b1=[int(i) for i in i12]
    b2=[int(i) for i in i22]
    d1=[0 for i in range(len(i11))]
    d2=[0 for i in range(len(i21))]
    r=[[0]for j in range(32)]
    # ゼロ桁目を追加
    a1.insert(0,0)
    b1.insert(0,0)
    d1.insert(0,0)
    a2.insert(0,0)
    b2.insert(0,0)
    d2.insert(0,0)
    for i in range(len(r)):
        for j in range(i):
            r[i].append(0)
        for j in range(1,len(a1)):
            r[i].append((a1[j]*a2[i+1]+d1[j-1])%10)
            d1[j]=int((a1[j]*a2[i+1]+d1[j-1])//10)
            if j==len(a1)-1:
                r[i].append(d1[j])
    for i in range(len(r)):
        for j in range(len(r[-1])-len(r[i])):
            r[i].append(0)
    print r

    return 

if __name__ == '__main__':
    input1="12345678901234567890123456789012 04"
    input2="98765432109876543210987654321098 09"
    input1=input1.split()
    input2=input2.split()
    # input1=raw_input().split()
    # input2=raw_input().split()
    a1=input1[0]
    b1=input1[1]
    a2=input2[0]
    b2=input2[1]    
    func(a1, b1, a2, b2)
