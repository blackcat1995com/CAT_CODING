from data_init import *

db = create_school()

if __name__ == '__main__':
    print(db.student.find_one({'name': '李明'}))
    # 在下方写你的代码：更新李明的年龄
    db.student.update_one({'name': '李明'}, {'$inc': {'age': 1}})

    print(db.student.find_one({'name': '李明'}))
