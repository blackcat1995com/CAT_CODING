# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 19:48
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

with open('myself.jpg', 'rb') as f:
    content = f.read()

with open('myself[副本].jpg', 'wb') as f:
   f.write(content)
    # f.write(content)