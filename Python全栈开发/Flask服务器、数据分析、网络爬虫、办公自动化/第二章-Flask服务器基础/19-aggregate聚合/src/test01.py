from flask import Flask, render_template, jsonify
from data_init import db
from pprint import pprint

app = Flask(__name__)
app.debug = True


@app.route('/', methods=['GET'])
def index():
    return render_template('test01.html')


@app.route('/data', methods=['GET'])
def show_data():
    # 在下方写你的代码：计算三年来每个省份消费总额，并打印结果data

    return jsonify({'data': data})


if __name__ == '__main__':
    app.run(host='127.0.0.1', port=8001)
