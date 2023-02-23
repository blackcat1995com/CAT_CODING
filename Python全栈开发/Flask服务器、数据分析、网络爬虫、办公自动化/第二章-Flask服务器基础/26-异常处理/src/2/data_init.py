import pymongo


def data_init():
    client = pymongo.MongoClient('mongodb://localhost:27017/')
    db = client.mydb26
    db.gift.delete_many({})
    db.money.delete_many({})
    db.travel.delete_many({})
    db.gift.insert_many(
        [
            {'name': '小熊', 'price': 100, 'num': 5},
            {'name': '赛车', 'price': 200, 'num': 10},
            {'name': '零食大礼包', 'price': 150, 'num': 10},
        ]
    )
    db.money.insert_one({'name': '储蓄罐', 'number': 0})
    db.travel.insert_many([
        {'province': '北京', 'scenic': '故宫', 'cost': 140},
        {'province': '上海', 'scenic': '东方明珠塔', 'cost': ''},
        {'province': '广州', 'scenic': '广州塔', 'cost': 100},
        {'province': '深圳', 'scenic': '世界之窗', 'cost': 200},
        {'province': '海南', 'scenic': '三亚', 'cost': 500},
        {'province': '河南', 'scenic': '龙门石窟', 'cost': 240},
        {'province': '山西', 'scenic': '五台山', 'cost': 170},
        {'province': '陕西', 'scenic': '兵马俑', 'cost': 340},
        {'province': '天津', 'scenic': '津门故里', 'cost': 340},
        {'province': '河北', 'scenic': '承德避暑山庄', 'cost': 440},
        {'province': '辽宁', 'scenic': '鞍山千山', 'cost': 140},
        {'province': '吉林', 'scenic': '长白山景区', 'cost': 540},
        {'province': '浙江', 'scenic': '西湖', 'cost': 640},
    ])
    db.student.delete_many({})
    db.student.insert_many(
        [
            {'name': '王子', 'age': 8, 'courses': ['语文', '数学', '英语']},
            {'name': '李明', 'age': 10, 'courses': ['语文', '英语', '数学']},
            {'name': '刘利', 'age': 10, 'courses': ['语文', '数学']},
            {'name': '刘萧', 'age': 13, 'courses': ['数学', '英语', '语文']},
            {'name': '刘美', 'age': 18, 'courses': ['英语', '语文', '数学', ]},
            {'name': '王小明', 'age': 12, 'courses': ['语文', '数学', '英语']}
        ]
    )

    return db


db = data_init()
