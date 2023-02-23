# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2023/2/20 10:37
# @Author  : 黑猫
# 公众号    : 黑猫编程
# 网址      : https://www.hioier.com/

'''
https://www.baidu.com/s?wd=%E9%BB%91%E7%8C%AB%E7%BC%96%E7%A8%8B
'''

import urllib.parse

kw = {'wd': '黑猫编程'}
ret = urllib.parse.urlencode(kw)
print(ret)

ret = urllib.parse.unquote(ret)
print(ret)