# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 19:43
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

f = open("data01.txt")
eof = False
while not eof:
    line = f.readline()
    if line:
        if line != "\n":
            print(line.strip())
    else:
        print("文件结束")
        eof = True
f.close()