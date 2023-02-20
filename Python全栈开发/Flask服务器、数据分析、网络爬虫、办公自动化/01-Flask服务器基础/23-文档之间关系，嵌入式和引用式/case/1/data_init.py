import pymongo
from bson import ObjectId


def data_init():

    client = pymongo.MongoClient('127.0.0.1', 27017)
    db = client['mydb23']

    db.role.delete_many({})
    db.role.insert_many(
        [
            {'name': '哪吒', 'alias': '三太子', 'father': '托塔李天王'},
            {'name': '敖丙', 'alias': '龙三太子', 'father': '东海龙王'},
            {'name': '孙悟空', 'alias': '美猴王', 'father': ''}
        ]
    )

    db.weapon.delete_many({})
    db.weapon.insert_many(
        [
            {'name': '混天绫', 'skill': '捆绑', 'alias': '七尺混天绫'},
            {'name': '风火轮', 'skill': '飞行', 'alias': '金霞风火轮'},
            {'name': '火尖枪', 'skill': '独门枪法', 'alias': '火焰三尖枪'},
            {'name': '如意金箍棒', 'skill': '镇海', 'alias': '天河定底神珍铁'},
            {'name': '九齿钉耙', 'skill': '降妖除魔', 'alias': '上宝沁金钯'}
        ]
    )

    db.people.delete_many({})
    db.card.delete_many({})
    db.people.insert_many(
        [
            {'name': '李涵', 'gender': '女'},
            {'name': '张勇', 'gender': '男'},
        ]
    )
    db.card.insert_many(
        [
            {'number': '410349199244103921', 'time': '2020-06-29 09:53:53'},
            {'number': '410339199534204831', 'time': '2019-05-29 10:03:22'}
        ]
    )

    db.student.delete_many({})
    db.parent.delete_many({})
    db.student.insert_many([
        {'name': '王小明', 'gender': '男', 'age': 12},
        {'name': '李月月', 'gender': '女', 'age': 11},

    ])
    db.parent.insert_many([
        {'name': '王海洋', 'gender': '男', 'age': 40, 'phone': 13273195940},
        {'name': '唐美丽', 'gender': '女', 'age': 39, 'phone': 15530286061},
        {'name': '翁子涵', 'gender': '女', 'age': 39, 'phone': 18740385490},
        {'name': '李大森', 'gender': '男', 'age': 38, 'phone': 17616305280},

    ])

    return db


db = data_init()
