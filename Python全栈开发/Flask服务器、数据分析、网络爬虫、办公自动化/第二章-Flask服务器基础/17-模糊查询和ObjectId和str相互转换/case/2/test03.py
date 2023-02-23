from data_init import db
# 在下方写你的代码：导入ObjectId
from bson import ObjectId

id = '5d31423beb771e6c8d161875'

# 把字符串转为ObjectId对象并查询文档
obj_id = ObjectId(id)

print(type(obj_id))

pet = db.pets.find_one({'_id': obj_id})
print(pet)
