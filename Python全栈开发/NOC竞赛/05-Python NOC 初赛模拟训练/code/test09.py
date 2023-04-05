# !/usr/bin/python3
# -*- coding: utf-8 -*-
# 公众号：黑猫编程
# 网址：https://noi.hioier.com

sum = 0
for i in range(0, 100):
    if i % 2 == 0:
        sum -= i
    else:
        sum += i
print(sum)

