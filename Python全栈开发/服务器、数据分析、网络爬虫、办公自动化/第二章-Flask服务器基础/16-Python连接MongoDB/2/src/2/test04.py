from data_init import db

# 更新前查询
for r in db.platform.find():
    print(r)
print('------------------')

# 在下方写你的代码：更新短视频时长为5秒

# 更新后查询
for r in db.platform.find():
    print(r)
