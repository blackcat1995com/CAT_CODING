from flask import Flask, render_template
from data_init import db

web = Flask(__name__)

web.debug = True


@web.route('/data', methods=['GET'])
def show_data():

    # 在下方写你的代码：统计的代码：查询 AQI大于100 的城市
    # data = list(db.air.find({'AQI': {'$gt': 100}}))
    # 查询 二氧化硫浓度 大于等于15 的城市
    # data = list(db.air.find({'SO2': {'$gte': 15}}))
    # 查询 PM2.5浓度 小于35 的城市
    # data = list(db.air.find({'PM25': {'$lt': 35}}))
    # 查询 空气质量 不是优 的城市
    data = list(db.air.find({'quality': {'$ne': '优'}}))

    return render_template('table.html', data=data)


if __name__ == '__main__':
    web.run('127.0.0.1', 8001)
