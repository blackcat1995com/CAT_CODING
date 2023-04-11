# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 19:38
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

f = open('data01.txt', mode='r', encoding='utf-8')

line = f.readline()
print(line)

line = f.readline()
print(line)

if line == '\n':
    print('ok')

line = f.readline()
print(line)

line = f.readline()
print(line)

if line == '\n':
    print('ok')

line = f.readline()
print(line)

if line == '\n':
    print('ok')

line = f.readline()
print(line)

if line == '':
    print('yes')

f.close()
