# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 12:52
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

class WebSite:

    def register(self):
        print("欢迎注册")

    def login(self):
        print("欢迎登陆")

    def home(self):
        print("欢迎进入首页")

    def about(self):
        print("关于我们")

page = WebSite()
while True:

    choose = input("请输入>>>")

    if hasattr(page, choose):
        f = getattr(page, choose)
        f()
    else:
        print('输入页面未找到 404')