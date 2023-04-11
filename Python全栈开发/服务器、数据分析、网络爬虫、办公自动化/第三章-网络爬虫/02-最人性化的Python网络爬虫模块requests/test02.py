# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2023/2/23 13:48
# @Author  : 黑猫
# 公众号    : 黑猫编程
# 网址      : https://www.hioier.com/

import csv

with open('data.csv', 'w', newline='') as f:

    writer = csv.writer(f)

    writer.writerow([1, "100块如何花一周"])
    writer.writerow([2, "如何上班时间高效摸鱼"])

    li = [
        [3, "如何一天赚到100万"],
        [4, "从易经到股市, 我的财富自由之路"],
        [5, "跟黑猫一起学编程"]
    ]

    writer.writerows(li)