import datetime

#  在下方写你的代码：第一种方法：获取当前时间
now = datetime.datetime.now()
print('当前时间:', now)
# 创建 1 天 2 小时 32 分钟 50 秒的时间差对象
delta = datetime.timedelta(days=1, hours=2, minutes=32, seconds=50)
# 计算王小宝出生时间
birth_time = now - delta

print('出生时间:', birth_time)

print('-'*50)

#  在下方写你的代码：第二种方法：获取当前时间
