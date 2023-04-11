# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2023/2/23 15:24
# @Author  : 黑猫
# 公众号    : 黑猫编程
# 网址      : https://www.hioier.com/

from bs4 import BeautifulSoup

with open("test02.html", "r", encoding="utf-8") as f:

    html = f.read()

# print(html)
# print(type(html))

bs = BeautifulSoup(html, "html.parser")

# print(bs.find("div", class_="box"))
# print(bs.findAll("div", class_="box"))

# print(bs.find("ul", attrs={"name":"list"}))

# print(bs.select("#d1"))
# print(bs.select(".box"))

# print(bs.title)

print(bs.div.attrs)
