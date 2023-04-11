# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 16:42
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

import traceback

try:
    a = 1 / 0
    print(a)
except:
    traceback.print_exc()