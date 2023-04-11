import pymongo
from bson import ObjectId


def data_init():
    client = pymongo.MongoClient('mongodb://localhost:27017/')
    db = client.mydb24
    db.company.delete_many({})
    db.company.insert_many(
        [
            {'_id': ObjectId('5f98da2769ad7130e43ffdfb'), 'name': '腾讯', 'chairman': '马化腾', 'time': '1998年11月11日',
             'gameId': [ObjectId('5f98da2769ad7130e43ffdfd'), ObjectId('5f98da2769ad7130e43ffdfe'),
                        ]},
            {'_id': ObjectId('5f98da2769ad7130e43ffdfc'), 'name': '网易', 'chairman': '丁磊', 'time': '1997年6月',
             'gameId': [ObjectId('5f98da2769ad7130e43ffdff'), ObjectId('5f98da2769ad7130e43ffe00'),
                        ObjectId('5f98da2769ad7130e43ffe02')]}
        ]
    )
    db.game.delete_many({})
    db.game.insert_many(
        [
            {'_id': ObjectId('5f98da2769ad7130e43ffdfd'), 'name': '王者荣耀', 'type': '推塔，即时对战，英雄对战',
             'time': '2015年11月26日'},
            {'_id': ObjectId('5f98da2769ad7130e43ffdfe'), 'name': '和平精英', 'type': '射击，竞技', 'time': '2019年5月8日'},
            {'_id': ObjectId('5f98da2769ad7130e43ffdff'), 'name': '阴阳师', 'type': '卡牌，角色扮演', 'time': '2016年6月20日'},
            {'_id': ObjectId('5f98da2769ad7130e43ffe00'), 'name': '我的世界 ', 'type': '沙盒，创造，生存', 'time': '2017年8月8日'},
            {'_id': ObjectId('5f98da2769ad7130e43ffe01'), 'name': '天涯明月刀手游', 'type': '角色扮演', 'time': '2020年10月16日'},
            {'_id': ObjectId('5f98da2769ad7130e43ffe02'), 'name': '创世西游', 'type': '角色扮演', 'time': '2011年3月20日'},

        ]
    )

    db.student.delete_many({})
    db.student.insert_many(
        [
            {'_id': ObjectId('5f992dc569ad710fb40560fa'), 'name': '小童', 'age': 14, 'gender': '男',
             'musicId': [ObjectId('5f992dc569ad710fb40560fd')]},
            {'_id': ObjectId('5f992dc569ad710fb40560fb'), 'name': '小美', 'age': 13, 'gender': '女',
             'musicId': [ObjectId('5f992dc569ad710fb40560fe'), ObjectId('5f992dc569ad710fb40570fe')]},
        ]
    )
    db.music.delete_many({})
    db.music.insert_many(
        [
            {'_id': ObjectId('5f992dc569ad710fb40560fc'), 'name': '少年', 'singer': '梦然'},
            {'_id': ObjectId('5f992dc569ad710fb40560fd'), 'name': '破茧', 'singer': '张韶涵'},
            {'_id': ObjectId('5f992dc569ad710fb40560fe'), 'name': '飞鸟和蝉', 'singer': '任然'},
            {'_id': ObjectId('5f992dc569ad710fb40570fe'), 'name': '雨下一整晚', 'singer': '周杰伦'},
        ]
    )

    db.customer.delete_many({})
    db.customer.insert_many(
        [
            {'_id': ObjectId('5f993f5469ad713d0024debd'), 'name': '小美', 'age': 13, 'gender': '女',
             'goodId': [ObjectId('5f993f5469ad713d0024debf'), ObjectId('5f993f5469ad713d0024debe')]}
        ]
    )
    db.goods.delete_many({})
    db.goods.insert_many(
        [
            {'_id': ObjectId('5f993f5469ad713d0024debe'), 'name': 'coke', 'price': 3.5, 'number': 3},
            {'_id': ObjectId('5f993f5469ad713d0024debf'), 'name': 'bread', 'price': 10, 'number': 1},
            {'_id': ObjectId('5f993f5469ad713d0024dec0'), 'name': 'egg', 'price': 0.5, 'number': 10},
            {'_id': ObjectId('5f993f5469ad713d0024dec1'), 'name': 'chocolate', 'price': 20, 'number': 2},
        ]
    )

    return db


db = data_init()
