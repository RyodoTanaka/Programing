#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import sys

if __name__ == '__main__':
    # 辞書の準備
    dic_data={'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
    # ソートされたキー値
    dic_keys=[]
    for k, v in sorted(dic_data.items(), key=lambda x: x[1], reverse=True):
        dic_keys.append(k)
    # ソートされたキー値の出現回数
    result=[0]*len(dic_data)

    # 値取得
    data=input()
    # 途中計算用
    tmp=data
    for i in range(len(dic_data)):
        result[i]=tmp//dic_data[dic_keys[i]]
        tmp=tmp%dic_data[dic_keys[i]]

    # 文字列操作
    output_data=[]
    for i in range(len(dic_data)):
        if result[i]==4:
            if result[i-1]==0:
                output_data.append(dic_keys[i])
                output_data.append(dic_keys[i-1])
                continue
            else:
                output_data[-1:]=dic_keys[i]
                output_data.append(dic_keys[i-2])
                continue
        for j in range(result[i]):
            output_data.append(dic_keys[i])

    # 表示
    for i in output_data:
        sys.stdout.write(i)
    print
