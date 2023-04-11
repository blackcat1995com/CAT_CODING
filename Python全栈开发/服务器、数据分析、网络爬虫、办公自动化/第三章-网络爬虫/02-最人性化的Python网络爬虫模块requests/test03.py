# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2023/2/23 13:50
# @Author  : 黑猫
# 公众号    : 黑猫编程
# 网址      : https://www.hioier.com/

import csv

with open('data.csv', 'r') as f:

    reader = csv.reader(f)

    # print(reader)
    for row in reader:
        print(row)