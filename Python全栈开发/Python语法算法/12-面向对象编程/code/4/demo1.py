# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 12:44
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

class Fruit:

    def __init__(self, name, color):

        self.name = name
        self.color = color

    def cost(self, price, num):

        print(price * num)

        return price * num

apple = Fruit('苹果', '红色')
print(hasattr(apple, 'name'))
print(hasattr(apple, 'cost'))

print(getattr(apple, 'name'))
getattr(apple, 'cost')(5, 10)

delattr(apple, 'name')
# getattr(apple, 'cost')(5, 10)
print(hasattr(apple, 'name'))