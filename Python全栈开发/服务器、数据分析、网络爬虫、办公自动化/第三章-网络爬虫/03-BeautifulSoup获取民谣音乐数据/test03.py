# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2023/2/23 15:42
# @Author  : 黑猫
# 公众号    : 黑猫编程
# 网址      : https://www.hioier.com/

import requests
from bs4 import BeautifulSoup
import tkinter as tk
from PIL import Image, ImageTk
from io import BytesIO

url = "https://music.douban.com/tag/民谣"

headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36'}

response = requests.get(url, headers=headers)

# print(response.text)
bs = BeautifulSoup(response.text, "html.parser")

listResult = bs.select("tr.item", limit=5)

resultList = []

for result in listResult:

    resultDict = {}

    resultDict['musicImage'] = result.select('img')[0]['src']
    resultDict['musicName'] = result.select('a')[0]['title'].split('-')[1].strip()
    resultDict['musicInfo'] = result.select("p.pl")[0].get_text()

    resultList.append(resultDict)

print(resultList)

w = tk.Tk()
w.geometry('400x510')

w.resizable(0, 0)

w.title("黑猫音乐爬虫")

for i in range(5):

    # 创建Frame组件
    frame = tk.Frame(w, width=400, height=100, bg='white')
    frame.place(relx=0, rely=i*0.2)

    # 显示音乐封面
    imgResponse = requests.get(resultList[i]['musicImage'])
    image = Image.open(BytesIO(imgResponse.content))

    photoImage = ImageTk.PhotoImage(image.resize((81, 81)))

    labelImg = tk.Label(frame, image=photoImage, width=81, height=81)
    labelImg.place(relx=0.04, rely=0.05)
    labelImg.image = photoImage

    # 显示音乐
    labelName = tk.Label(frame, text=resultList[i]['musicName'], bg='white', fg='#3377AA', font=("./font/simhei.ttf", 11))
    labelName.place(relx=0.3, rely=0.1)

    # 显示音乐信息
    labelInfo = tk.Label(frame, text=resultList[i]['musicInfo'], bg='white', fg='#666666', font=("./font/simhei.ttf", 9))
    labelInfo.place(relx=0.3, rely=0.6)

w.mainloop()