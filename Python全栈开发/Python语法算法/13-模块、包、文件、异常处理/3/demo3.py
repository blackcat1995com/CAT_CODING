# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 19:44
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

f_read = open('data01.txt')
f_write = open('data01[副本].txt', 'a')

text = f_read.read()
f_write.write(text)

f_read.close()
f_write.close()