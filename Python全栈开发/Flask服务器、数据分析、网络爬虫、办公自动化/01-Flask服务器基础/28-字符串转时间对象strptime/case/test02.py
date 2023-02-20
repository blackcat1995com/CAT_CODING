import datetime

str_time = '2022/08/20 10:20:29'
# 在下方写你的代码：把字符串转为日期时间对象并查看类型

time = datetime.datetime.strptime(str_time, '%Y/%m/%d %H:%M:%S')
print(time)
print(type(time))