# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 16:40
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

def check_passwd():

    passwd = input('请输入你的密码：')

    if len(passwd) >= 8:
        return passwd

    raise Exception('密码长度至少8位')

try:
    passwd = check_passwd()
    print(passwd)
except Exception as e:
    print('错误类型：', e)