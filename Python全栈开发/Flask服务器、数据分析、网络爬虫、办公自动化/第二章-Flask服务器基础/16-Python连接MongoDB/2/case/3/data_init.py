import pymongo


def create_school():
    # 建立连接
    client = pymongo.MongoClient('127.0.0.1', 27017)
    # 创建数据库
    db = client['mydb5']

    b = list(db.student.find())
    if len(b) <= 0:
        db.student.insert_many(
            [
                {'name': '王子', 'age': 8, 'birth_place': '北京', 'height': 155, 'weight': 32,
                 'courses': ['语文', '数学', '化学', '音乐']},
                {'name': '李明', 'age': 10, 'birth_place': '杭州', 'height': 120, 'weight': 39,
                 'courses': ['语文', '数学', '英语', '美术', '音乐']},
                {'name': '刘利', 'age': 10, 'birth_place': '北京', 'height': 125, 'weight': 35,
                 'courses': ['语文', '数学', '英语', '化学', '体育']},
                {'name': '刘萧', 'age': 13, 'birth_place': '北京', 'height': 170, 'weight': 40,
                 'courses': ['语文', '数学', '英语', '历史', '政治', '地理']},
                {'name': '刘美', 'age': 18, 'birth_place': '上海', 'height': 170, 'weight': 55,
                 'courses': ['语文', '数学', '英语', '历史', '地理', '生物', '化学', '政治', '物理']},
                {'name': '王小明', 'age': 12, 'birth_place': '上海', 'height': 165, 'weight': 40,
                 'courses': ['语文', '数学', '英语', '历史', '政治']}
            ]
        )
    return db


def create_farm():
    # 建立连接
    client = pymongo.MongoClient('127.0.0.1', 27017)
    # 创建数据库
    db = client['mydb6']
    b = list(db.myFarm.find())
    if len(b) <= 0:
        db.myFarm.insert_many(
            [
                {'name': '绵羊', 'number': 20},
                {'name': '鸭子', 'number': 100},
                {'name': '奶牛', 'number': 10},
                {'name': '母鸡', 'number': 10}
            ]
        )
    return db
