# !/usr/bin/python3
# -*- coding: utf-8 -*-
# 公众号：黑猫编程
# 网址：https://noi.hioier.com

x = 10
while x:
    x -= 1
    if not x % 2:
        print(x, end='')
else:
    print(x)

