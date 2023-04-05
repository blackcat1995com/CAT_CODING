# !/usr/bin/python3
# -*- coding: utf-8 -*-
# 公众号：黑猫编程
# 网址：https://noi.hioier.com

x2 = 1
for day in range(4,0,-1):
    x1 = (x2 + 1) * 2
    x2 = x1
print(x1)

