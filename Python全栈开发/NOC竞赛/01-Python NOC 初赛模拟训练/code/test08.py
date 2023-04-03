# !/usr/bin/python3
# -*- coding: utf-8 -*-
# 公众号：黑猫编程
# 网址：https://noi.hioier.com

import turtle as t

def DrawCctCircle(n):
    t.penup()
    t.goto(0, -n)
    t.pendown()
    t.circle(n)

for i in range(20, 80, 20):
    DrawCctCircle(i)

t.done()
