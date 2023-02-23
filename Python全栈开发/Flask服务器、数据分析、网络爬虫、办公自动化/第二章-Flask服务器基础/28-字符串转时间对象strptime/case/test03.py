import datetime

# 在下方写你的代码：距离考试倒计时10天，计算出洋洋考试那天的日期
date = datetime.datetime.now().date()
print(date)

delta = datetime.timedelta(days=10)
print(date + delta)