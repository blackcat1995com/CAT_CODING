from data_init import db
from pprint import pprint

pprint(db.student.find_one({'name':'王小明'}))
print('-' * 50)
# 下方写你的代码:找到姓名为唐美丽、 王海洋对应的文档，把它与学生 王小明 建立嵌入式关系
parents = list(db.parent.find({
		'$or':[
			{'name': '唐美丽'},
			{'name': '王海洋'}
		]
	}))

db.student.update_one({'name':'王小明'}, {'$set':{'parent':parents}})
pprint(db.student.find_one({'name':'王小明'}))
