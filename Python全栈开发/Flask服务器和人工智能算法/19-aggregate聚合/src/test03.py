from flask import Flask, render_template, jsonify
from data_init import db

app = Flask(__name__)
app.debug = True


@app.route('/', methods=['GET'])
def index():
    return render_template('test03.html')


@app.route('/data', methods=['GET'])
def show_data():
    # 在下方写你的代码：计算2017-2019年每年全国粮食的总产量

    return jsonify({'data': data})


if __name__ == '__main__':
    app.run(host='127.0.0.1', port=8003)
