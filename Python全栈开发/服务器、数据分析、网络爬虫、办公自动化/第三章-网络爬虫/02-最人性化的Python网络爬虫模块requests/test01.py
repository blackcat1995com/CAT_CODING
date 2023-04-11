# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2023/2/23 13:40
# @Author  : 黑猫
# 公众号    : 黑猫编程
# 网址      : https://www.hioier.com/

import requests
import re
import csv

titles = []

for i in range(1, 78):

    url = "http://blog.hioier.com/blog/detail/%d/" % i

    response = requests.get(url)

    # print(response.text)

    title = re.findall("<h3 class=\"arc-title index-title\">(.*)</h3>", response.text)
    title.insert(0, i)
    titles.append(title)

# print(titles)

with open('data.csv', 'w', newline='') as f:

    writer = csv.writer(f)
    writer.writerows(titles)