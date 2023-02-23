import datetime
from handler import date
from data_init import db
from flask import Flask, request, jsonify

app = Flask(__name__)
# 注册蓝图
app.register_blueprint(date.date)
app.debug = True


@app.route('/date')
def set_date():
    # 在下方写你的代码：获取请求参数 date、state
    pass
    # 把时间字符串转为时间对象
   
    # 在 calendar 集合中插入文档：保存当天日期和当天状态
  
    # 使用 jsonify 返回 {'result': 'success'}
    


if __name__ == '__main__':
    app.run('127.0.0.1', 8000)
