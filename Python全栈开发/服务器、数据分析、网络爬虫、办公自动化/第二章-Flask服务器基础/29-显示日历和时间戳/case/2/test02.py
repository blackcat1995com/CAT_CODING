import datetime

str_time = '2022-6-28 11:54:10'
# 在下方写你的代码:把字符串str_time转为日期时间对象
time = datetime.datetime.strptime(str_time, '%Y-%m-%d %H:%M:%S')
# 再把获取的日期时间对象转换为时间戳，然后打印
stamp = time.timestamp()
print(stamp)
