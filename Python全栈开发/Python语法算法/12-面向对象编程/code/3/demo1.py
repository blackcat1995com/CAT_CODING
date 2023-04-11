# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time    : 2022/10/2 9:44
# @Author  : 黑猫
# 公众号   : 黑猫编程
# 网址     : ac.blackcat1995.com

# 类的约束

from abc import ABCMeta, abstractmethod

class Payment(metaclass=ABCMeta):

    @abstractmethod
    def pay(self, money):
        print('子类继承我必须重写')


class QQpay(Payment):

    def pay(self, money):
        print('QQ支付%d元' % money)


class Wechatpay(Payment):

    def pay(self, money):
        print('微信支付%d元' % money)


class Alipay(Payment):

    pass

qq = QQpay()
wx = Wechatpay()
# zfb = Alipay()

qq.pay(10)
wx.pay(12)
