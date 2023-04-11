# !/usr/bin/python3
# -*- coding: utf-8 -*-
# 公众号：黑猫编程
# 网址：https://noi.hioier.com

num = 15
for i in range(5):
    if num % 3 == 0:
        num = num / 3
    else:
        num = 2 * num + 1
print(num)

