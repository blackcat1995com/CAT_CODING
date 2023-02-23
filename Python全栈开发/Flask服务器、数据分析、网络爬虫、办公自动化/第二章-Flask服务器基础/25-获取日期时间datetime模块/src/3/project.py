import datetime
from flask import Flask, render_template

app = Flask(__name__)

app.debug = True


@app.route('/time', methods=['GET'])
def get_week():
    # 预留
    week_list = ['星期一', '星期二', '星期三', '星期四', '星期五', '星期六', '星期日']
    # 下方写你的代码，获取今天的星期，并返回中文星期
    pass


if __name__ == "__main__":
    app.run('127.0.0.1', 8000)
