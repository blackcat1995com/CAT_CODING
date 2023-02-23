import datetime
from data_init import db

stamp = 497030400.0
# 在下方写你的代码：把时间戳 stamp 转为日期时间对象并打印

date = datetime.datetime.fromtimestamp(stamp)
print(date)

# 通过日期时间查询宝藏房间
room = db.castle.find_one({'built_time': date})
print(room)