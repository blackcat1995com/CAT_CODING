# !/usr/bin/python3
# -*- coding: utf-8 -*-
# 公众号：黑猫编程
# 网址：https://noi.hioier.com

li1 = [1, 2, 3, 4, 5]
li2 = [3, 4, 5, 6 ,7 , 8]
li3 = []
for i in li2:
    if i not in li1:
        li3.append(i)
print(li3)

