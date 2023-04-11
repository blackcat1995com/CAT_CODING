# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2023/2/20 10:40
# @Author  : 黑猫
# 公众号    : 黑猫编程
# 网址      : https://www.hioier.com/


import urllib.request
import urllib.parse

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/110.0.0.0 Safari/537.36'
}

rawURL = "https://www.baidu.com/s?"
keyword = input("请输入你的关键词：")
word = {'wd': keyword}
word = urllib.parse.urlencode(word)

fullURL = rawURL + word
print(fullURL)

request = urllib.request.Request(fullURL, headers=headers)
response = urllib.request.urlopen(request)

html = response.read().decode('utf-8')
print(html)
