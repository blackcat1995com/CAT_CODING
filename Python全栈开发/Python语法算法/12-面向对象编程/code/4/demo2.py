# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 12:50
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

while True:

    choose = input("请输入>>>")

    if choose == "register":
        page = WebSite()
        page.register()

    elif choose == "login":
        page = WebSite()
        page.login()

    elif choose == "home":
        page = WebSite()
        page.home()

    elif choose == "about":
        page = WebSite()
        page.about()