# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2023/2/20 10:29
# @Author  : 黑猫
# 公众号    : 黑猫编程
# 网址      : https://www.hioier.com/

import urllib.request

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/110.0.0.0 Safari/537.36'
}
request = urllib.request.Request("http://www.baidu.com/", headers=headers)

response = urllib.request.urlopen(request)

print(response)

html = response.read().decode("utf-8")

# print(html)

# print(response.getcode())
# print(response.geturl())
# print(response.info())
print(request.get_header("User-agent"))