import datetime
from data_init import db

str_time = '2022/8/20'
# 在下方写你的代码： 把时间字符串转为时间对象
time = datetime.datetime.strptime(str_time, '%Y/%m/%d')
print(time)

# 查询小明对战赢了几次
count = db.fight.count_documents({'name':'小明', 'result':'胜利'})
print(count)

count = db.fight.count_documents({'time':time})
print(count)
