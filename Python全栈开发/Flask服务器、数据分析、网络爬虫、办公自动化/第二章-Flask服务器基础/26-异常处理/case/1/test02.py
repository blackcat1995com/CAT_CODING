from flask import Flask, render_template, request, abort
from data_init import db

app = Flask(__name__)
app.debug = True


@app.route('/')
def index():
    return render_template('test02.html')


@app.route('/save', methods=['GET'])
def save():
    # 在下方写你的代码:添加异常处理代码
    try:
        # 接收用户存钱金额
        money = int(request.args.get('money'))
        # 更新数据库中金额
        db.money.update_one({'name': '储蓄罐'},
                            {'$inc': {'number': money}})
        return render_template('test02.html',
                               data='成功存了%s元钱' % money)
    # 出现异常后，打印报错信息，并渲染test02.html，返回data提示信息“请输入数字”
    except Exception as e:
        print('错误信息：', e)
        return render_template('test02.html', data='请输入数字')

if __name__ == '__main__':
    app.run(host='127.0.0.1', port=8001)
