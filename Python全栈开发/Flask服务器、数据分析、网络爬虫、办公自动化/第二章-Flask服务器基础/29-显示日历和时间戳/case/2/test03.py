from data_init import db
import datetime

# 在下方写你的代码：获取当前时间的时间戳并转为总微秒数，再调用int函数转为整数
now = datetime.datetime.now()
stamp = int(now.timestamp() * 1000000)

# 在数据库中插入订单信息并查询打印
db.order.insert_one({'order_number':stamp, 'amount':156.37, 'payment':'支付宝'})

print(db.order.find_one({'order_number': stamp}))
