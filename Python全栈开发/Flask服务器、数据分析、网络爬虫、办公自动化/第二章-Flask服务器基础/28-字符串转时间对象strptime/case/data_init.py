import pymongo
import datetime


def data_init():
    client = pymongo.MongoClient('mongodb://localhost:27017/')
    db = client.mydb28
    db.fight.delete_many({})
    db.fight.insert_many(
        [
            {'name': '小明', 'time': datetime.datetime(2022, 8, 20), 'result': '胜利'},
            {'name': '小明', 'time': datetime.datetime(2022, 8, 20), 'result': '失败'},
            {'name': '小明', 'time': datetime.datetime(2022, 8, 20), 'result': '胜利'},
            {'name': '小明', 'time': datetime.datetime(2022, 6, 22), 'result': '失败'},
            {'name': '小美', 'time': datetime.datetime(2022, 6, 22), 'result': '成功'},
            {'name': '小美', 'time': datetime.datetime(2022, 6, 22), 'result': '成功'},

        ]
    )
    db.calendar.delete_many({})

    return db


db = data_init()
