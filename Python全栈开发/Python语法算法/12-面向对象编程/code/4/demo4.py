# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 12:55
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

class Player:

    def __new__(self, *args, **kwgrgs):
        print("new执行了")

    def __init__(self):
        print("init执行了")

video1 = Player()
print(video1)

video2 = Player()
print(video2)