# !/usr/bin/python3
# -*- coding: utf-8 -*-
# 公众号：黑猫编程
# 网址：https://noi.hioier.com

for n in range(100, 200):
    i = n // 100
    j = n // 10 % 10
    k = n % 10
    if n == i ** 3 + j ** 3 + k ** 3:
        print(n)

