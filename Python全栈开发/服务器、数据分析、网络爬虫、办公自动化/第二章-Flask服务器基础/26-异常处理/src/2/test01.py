from flask import Flask, render_template, request, abort
from data_init import db
import traceback

app = Flask(__name__)
app.debug = True


@app.route('/')
def index():
    return render_template('test01.html')


@app.route('/gift', methods=['GET'])
def gift():
    # 获取用户输入的礼物
    gift = request.args.get('gift')
    try:
        data = db.gift.find_one({'name': gift})
        # 在下方写你的代码：判断礼物文档是否存在，如果不存在，直接返回响应

        if data['num'] > 0:
            db.gift.update_one({'name': gift}, {'$inc': {'num': -1}})
            return render_template('test01.html', data='许愿成功：获得%s' % gift)
        else:
            return render_template('test01.html', data='该礼物已被领完')
    # 异常处理，打印报错信息，返回 test01.html, 提示信息'程序出错了'
    except Exception as e:
        # 在下方写你的代码：打印详细的报错信息
        print('报错信息：%s', e)
        return render_template('test01.html', data='程序出错了')


if __name__ == '__main__':
    app.run(port=8001)
