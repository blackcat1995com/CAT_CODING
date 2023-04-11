# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 10:04
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

import math

class Circle:

    def __init__(self, r):

        self.__r = r

    @property
    def area(self):

        return round(self.__r **2*math.pi, 2)

    @area.setter
    def area(self, r):
        self.__r = r

    @area.deleter
    def area(self):
        del self.__r
        print('我被删除了')

c = Circle(5)
print('圆C的面积是：', c.area)

c.area = 10
print('圆C的面积是：', c.area)

del c.area
# print('圆C的面积是：', c.area)


