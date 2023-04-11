from data_init import db
import datetime

stamp = 956402061.0
# 在下方写你的代码：查询时间戳 stamp 对应的商品文档并打印

data = db.goods.find_one({'time': stamp})
print(data)
# 如果商品存在
if data:
    # 把商品中的时间戳转为日期时间对象
    time = datetime.datetime.fromtimestamp(data['time'])

    # 再把日期时间对象转为字符串并打印
    str_time = time.strftime('%Y/%m/%d %H:%M:%S')

    print(str_time)

# 如果商品不存在，则打印“验证失败”
else:
    print('验证失败')

