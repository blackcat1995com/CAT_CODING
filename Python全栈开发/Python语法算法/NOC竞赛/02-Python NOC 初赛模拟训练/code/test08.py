# !/usr/bin/python3
# -*- coding: utf-8 -*-
# 公众号：黑猫编程
# 网址：https://noi.hioier.com

k = 0
while True:
    s = input("请输入q退出：")
    if s == "q":
        k += 1
        continue
    else:
        k += 2
        break

print(k)