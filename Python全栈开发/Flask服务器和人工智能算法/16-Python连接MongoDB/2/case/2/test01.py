from data_init import db

# 更新前查询
for r in db.student.find():
    print(r)
print('------------------')

# 在下方写你的代码：更新马云数学成绩为100
db.student.update_one({'name': '马云'}, {'$set': {'math': 100}})

# 更新后查询
for r in db.student.find():
    print(r)
