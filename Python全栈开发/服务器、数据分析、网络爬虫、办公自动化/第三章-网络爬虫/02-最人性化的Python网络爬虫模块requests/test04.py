# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2023/2/23 13:56
# @Author  : 黑猫
# 公众号    : 黑猫编程
# 网址      : https://www.hioier.com/


import requests

class TiebaSpider:

    def __init__(self, name, start_page, end_page):
        self.name = name
        self.start_page = start_page
        self.end_page = end_page

        self.headers = self.headers = {
            "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.6; rv2.0.1) Gecko/20100101 Firefox/4.0.1"
        }

        self.rawURL = "https://tieba.baidu.com/f?kw=%s&ie=utf-8&pn={}" % self.name
        # print(self.rawURL)

    def load_page(self, page_num):
        fullURL = self.rawURL.format((page_num - 1) * 50)
        response = requests.get(fullURL, headers=self.headers)
        return response.text

    def save_page(self, page_num):
        file_name = "{}吧 第{}页.html".format(self.name, page_num)

        html = self.load_page(page_num)

        with open(file_name, "w", encoding="utf-8") as f:
            f.write(html)


    def run(self):
        for i in range(self.start_page, self.end_page + 1):
            self.save_page(i)

if __name__ == "__main__":

    keyword = input("请输入你的关键词：")
    a, b = [int(i) for i in input("请输入贴吧页数 a b（空格分隔）：").split()]
    # print(keyword, a, b)

    tieba_spider = TiebaSpider(keyword, a, b)
    tieba_spider.run()