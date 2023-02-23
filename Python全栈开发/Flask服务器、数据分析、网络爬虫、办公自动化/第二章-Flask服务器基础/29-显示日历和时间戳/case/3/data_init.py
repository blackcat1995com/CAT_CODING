import pymongo
import datetime


def data_init():
    client = pymongo.MongoClient('mongodb://localhost:27017/')
    db = client.mydb29
    db.goods.delete_many({})
    db.goods.insert_many(
        [
            {'name': '贵州茅台', 'time': 956402061.0},
            {'name': '贝玛格雷葡萄酒', 'time': 999402061.0},
            {'name': '西施赛马葡萄酒', 'time': 988402001.0},
            {'name': 'NIVEA啫喱防晒霜', 'time': 1789120611.0},
            {'name': '佳洁士电动牙刷', 'time': 161100000.0},
        ]
    )
    db.castle.insert_many(
        [
            {'room': '布拉尼', 'built_time': datetime.datetime(1987, 4, 23)},
            {'room': '阿代尔', 'built_time': datetime.datetime(1986, 8, 20)},
            {'room': '比尔', 'built_time': datetime.datetime(1979, 4, 12)},
            {'room': '阿什福德', 'built_time': datetime.datetime(1983, 6, 22)},
            {'room': '路特', 'built_time': datetime.datetime(1984, 6, 22)},
            {'room': '黛丝', 'built_time': datetime.datetime(1985, 10, 2)},
            {'room': '琼斯', 'built_time': datetime.datetime(1986, 12, 15)},
            {'room': '巴顿', 'built_time': datetime.datetime(1988, 3, 3)},

        ]
    )

    return db


db = data_init()
