import datetime

now = datetime.datetime.now()
# 在下方写你的代码：按照“04:50:35”格式，输出12小时制的当前时间
t1 = now.strftime('%I:%M:%S')

# 按照“04:50:35”格式，输出24小时制的当前时间
t2 = now.strftime('%H:%M:%S')

print(t1)
print(t2)

