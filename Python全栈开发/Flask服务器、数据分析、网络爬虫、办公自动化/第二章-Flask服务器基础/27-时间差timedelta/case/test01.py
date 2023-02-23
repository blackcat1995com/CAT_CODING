import datetime

# 在下方写你的代码：第一种方法：获取中国时间并打印
Chinese_Now = datetime.datetime.now()
print('中国时间:', Chinese_Now)
# 创建12小时的时间差对象并打印
delta = datetime.timedelta(hours=12)

# 北京时间减去12小时的时间差，即是美国此时时间
American_Time = Chinese_Now - delta

print('美国时间:', American_Time)

print('-'*50)

# 在下方写你的代码：第二种方法：获取中国时间
Chinese_Now = datetime.datetime.now()
print('中国时间:', Chinese_Now)

delta = datetime.timedelta(hours=-12)

American_Time = Chinese_Now + delta

print('美国时间:', American_Time)

