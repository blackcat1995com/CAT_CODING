from flask import Flask, render_template
from data_init import db

web = Flask(__name__)

web.debug = True


@web.route('/data', methods=['GET'])
def show_data():

    # 在下方写你的代码：查询 AQI大于100 的城市
 
    # 查询 二氧化硫浓度大于等于15 的城市

    # 查询 PM2.5浓度小于35 的城市

    # 查询 空气质量不是优 的城市

    return render_template('table.html', data=data)


if __name__ == '__main__':
    web.run('127.0.0.1', 8001)
