# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 13:02
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

class Animal:

    def __init__(self, name, color):

        self.name = name
        self.color = color

    def __repr__(self):

        ret = self.name + "是" + self.color
        return ret

bat = Animal("蝙蝠", "黑色")
print(bat)
print(str(bat) + "口感很好")
print("蝙蝠的特征：%s" % bat)

print(repr(bat))
print("你了解蝙蝠吗？ %r" % bat)