# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 10:01
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

import time


# def current_time():
#     print('当前时间是：', time.time())

class Time:

    def __init__(self, hour, minute, second):

        self.hour = hour
        self.minute = minute
        self.second = second

    @staticmethod
    def current_time():

        print('当前时间是：', time.time())
        # print(self.hour)

Time.current_time()

t = Time(10, 2, 30)
t.current_time()