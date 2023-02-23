from data_init import db
from pprint import pprint

# 更新前，打印 name 是唐僧的文档
pprint(db.role.find_one({'name': '唐僧'}))
print('-' * 50)

# 在下方写你的代码:找到'白虎岭'
address = db.address.find_one({'local':'白虎岭'})

# 把白虎岭的 id 添加到'唐僧'文档列表中
db.role.update_one({'name':'唐僧'}, {'$push':{'addressId':address['_id']}})

# 更新后，打印 name 是唐僧的文档
pprint(db.role.find_one({'name': '唐僧'}))
