from flask import Flask, jsonify, request, render_template
import logging

app = Flask(__name__)
app.debug = True

# 存储报名用户
users = []

# 日志配置
logging.basicConfig(level=logging.INFO, filename='./cat.log')


@app.route('/')
def index():

    # logging.debug('debug')
    # logging.info('info')
    # logging.warning('warning')
    # logging.error('error')

    return render_template('index.html')


@app.route('/log', methods=['POST'])
def log():
    # 请在下方写你的代码：获取用户姓名和性别，使用日志logging打印用户信息

    name = request.form.get('name')
    gender = request.form.get('gender')

    logging.info('学生%s，性别%s，报名成功' % (name, gender))

    user = {'name': name, 'gender':gender}
    users.append(user)

    return render_template('index.html', data='%s报名成功' % name)


if __name__ == '__main__':
    app.run(host='127.0.0.1', port=8001)
