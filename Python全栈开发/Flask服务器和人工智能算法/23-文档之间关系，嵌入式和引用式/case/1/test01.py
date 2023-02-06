from data_init import db
from pprint import pprint

num = '410349199244103921'

# 下方写你的代码:找到身份证号 num 对应的文档，把它与 李涵 建立嵌入式关系
card = db.card.find_one({'number':num})
db.people.update_one({'name':'李涵'}, {'$set':{'card':card}})
pprint(db.people.find_one({'name':'李涵'}))
