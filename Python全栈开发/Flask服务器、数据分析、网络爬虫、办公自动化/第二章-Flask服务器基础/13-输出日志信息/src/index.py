from flask import Flask, jsonify, request, render_template

app = Flask(__name__)
app.debug = True

# 存储报名用户
users = []

# 日志配置


@app.route('/')
def index():

    return render_template('index.html')


@app.route('/log', methods=['POST'])
def log():
    # 请在下方写你的代码：获取用户姓名和性别，使用日志logging打印用户信息

    return render_template('index.html', data='报名成功')


if __name__ == '__main__':
    app.run(host='127.0.0.1', port=8001)
