# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 16:36
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

fruits = ['apple', 'banana', 'orange', 'pear']

try:
    print(fruits[4])

except TypeError:
    print('类型错误')

except IndexError:
    print('下标索引错误')

except Exception as e:
    print('未知错误%s' % e)

else:
    print('没有异常才回执行的代码')

finally:
    print('不论是否异常都会执行的代码')