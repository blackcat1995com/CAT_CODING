# !/usr/bin/python3
# -*- coding: utf-8 -*-
# 公众号：黑猫编程
# 网址：https://noi.hioier.com

li = [81, 58, 19, 29, 85]
for i in range(2):
    max = 0
    for j in range(i, len(li)):
        if li[j] > max:
            max = li[j]
            max_index = li.index(max)
            temp = li[i]
            li[i] = max
            li[max_index] = temp
print(li)


