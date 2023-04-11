# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 18:18
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

import sys

print(sys.version)
print(sys.platform)
print(sys.path)
print(sys.modules)

print(sys.argv)

print(sum([int(i) for i in sys.argv[1:]]))