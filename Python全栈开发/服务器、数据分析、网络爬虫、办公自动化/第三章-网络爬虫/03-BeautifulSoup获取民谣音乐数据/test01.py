# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2023/2/23 15:17
# @Author  : 黑猫
# 公众号    : 黑猫编程
# 网址      : https://www.hioier.com/

import requests
from bs4 import BeautifulSoup

url = "https://music.douban.com/tag/民谣"

headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36'}

response = requests.get(url, headers=headers)

# print(response.text)
bs = BeautifulSoup(response.text, "html.parser")

listResult = bs.select("tr.item", limit=5)

# print(listResult)

result = listResult[0]
# print(result)

# result = result.select("img")
# print(result[0]['src'])

# [<img alt="赵雷 Lei Zhao - 署前街少年" src="https://img2.doubanio.com/view/subject/s/public/s34295591.jpg" style="width: 80px; max-height: 120px;"/>]

# result = result.select('a')
# print(result[0]['title'].split('-')[1].strip())

result = result.select("p.pl")
print(result[0].get_text())