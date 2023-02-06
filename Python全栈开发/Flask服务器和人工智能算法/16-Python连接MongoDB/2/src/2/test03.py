from data_init import db

# 更新前查询
for r in db.student.find():
    print(r)
print('------------------')

# 在下方写你的代码：更新4年级为3年级

# 更新后查询
for r in db.student.find():
    print(r)
