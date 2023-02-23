import pymongo


def data_init():
    client = pymongo.MongoClient('mongodb://localhost:27017/')
    db = client.mydb26
    db.money.delete_many({})
    db.student.delete_many({})
    db.student.insert_many(
        [
            {'name': '王小满', 'age': 12, 'gender': '男'},
            {'name': '李明夏', 'age': 11, 'gender': '男'},
            {'name': '葛紫薇', 'age': 11, 'gender': '女'},
            {'name': '赵无双', 'age': 13, 'gender': '女'},
            {'name': '白美丽', 'age': 12, 'gender': '女'},
            {'name': '牛犇犇', 'age': 13, 'gender': '男'},
            {'name': '夏天', 'age': 11, 'gender': '男'},
            {'name': '周海洋', 'age': 11, 'gender': '男'},
            {'name': '张天爱', 'age': 11, 'gender': '女'},
            {'name': '宋愉悦', 'age': 12, 'gender': '女'},

        ]
    )
    return db


db = data_init()
