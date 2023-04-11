# !/usr/bin/python3
# -*- coding: utf-8 -*-
# 公众号：黑猫编程
# 网址：https://noi.hioier.com

li = []
for i in range(2,10):
    count = 0
    for x in range(2,i-1):
        if i % x == 0:
            count += 1
    if count != 0:
        li.append(i)
print(li)


