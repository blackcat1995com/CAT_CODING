import datetime
from data_init import db
from pprint import pprint

str_time = '2022-08-20'
# 在下方写你的代码：把字符串 str_time 转为日期时间对象
time = datetime.datetime.strptime(str_time, '%Y-%m-%d')

# 打印转换后的日期时间对象及类型
print(time)
print(type(time))

# 根据日期时间对象查询战绩
data = list(db.fight.find({'name':'小明', 'time':time}))
pprint(data)
