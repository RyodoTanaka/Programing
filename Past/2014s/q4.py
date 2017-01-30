#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

def calc(default, n):
    a=[]
    b=[]
    c=[]
    a.append(3.)
    b.append(1.)
    c.append(1.)
    for i in range(1,n+1):
        a.append(a[0]*(4.**(float(i))))
        b.append(b[0]*((1./3.)**(float(i))))
        c.append(c[i-1]+(b[i]**2.)*a[i-1])
    return default*c[-1]
    
    
if __name__ == '__main__':
    print calc(float(5.*5.*3.**(1./2.)), input())
