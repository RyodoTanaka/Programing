#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

def func(d):
    cnt0=0
    cnt1=0
    for i in range(int(10//d+1)):
        for j in range(int(10//d+1)):
            cnt0+=1
            x=float(i)*float(d)
            y=float(j)*float(d)
            if (x-5)**2+(y-5)**2<=25:
                cnt1+=1
    print "A(d,R0) = ", cnt0
    print "A(d,R1) = ", cnt1
    return (float(cnt1)/float(cnt0))*(1./4.)
    
if __name__ == '__main__':
    print func(input())
