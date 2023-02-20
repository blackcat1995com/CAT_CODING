from data_init import db

# 在下方写你的代码:找到'唐僧'的文档
role = db.role.find_one({'name':'唐僧'})

# 遍历途径地址 id 列表，根据 id 查询详细地址信息
for id in role['addressId']:
	address = db.address.find_one({'_id': id})
	print('在%s遇到了%s妖怪' % (address['local'], address['monster']))
