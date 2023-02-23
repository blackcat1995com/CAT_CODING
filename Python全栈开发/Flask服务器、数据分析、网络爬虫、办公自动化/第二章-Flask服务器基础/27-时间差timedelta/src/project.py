import datetime
from flask import Flask, jsonify, render_template, request, redirect

app = Flask(__name__)

app.debug = True


@app.route('/', methods=['GET'])
def index():
    return render_template('index.html')


@app.route('/time', methods=['GET'])
def get_date():
    # 在下方写你的代码：获取产品生产耗时参数：day、hour、minute
    pass
    # 创建2210年3月24号的时间对象

    # 创建时间差对象
    
    # 计算产品生产时间

    # 渲染 projects.html，返回数据 time


if __name__ == "__main__":
    app.run('127.0.0.1', 8000)
