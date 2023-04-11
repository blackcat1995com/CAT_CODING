# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 9:56
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

class Animal:

    __feature = 'delicious'
    country = 'China'

    def __init__(self, name, color):

        self.name = name
        self.color = color

    @classmethod
    def output(cls):
        print('所有的动物都很%s，尤其是bat' % cls.__feature)
        # print(cls.name)

# Animal.output()

# bat = Animal('bat', 'black')
# bat.output()