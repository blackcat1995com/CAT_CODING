# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 12:58
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

class Player:

    __instance = None
    __flag = False

    def __new__(cls, *args, **kwgrgs):
        print("new执行了")
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
        return cls.__instance

    def __init__(self):

        if not Player.__flag:

            print("init执行了")
            Player.__flag = True

video1 = Player()
print(video1)

video2 = Player()
print(video2)