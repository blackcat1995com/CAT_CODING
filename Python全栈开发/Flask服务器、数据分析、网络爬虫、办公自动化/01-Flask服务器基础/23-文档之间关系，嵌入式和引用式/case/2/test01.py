from data_init import db
from pprint import pprint


# 下方写你的代码:找到首都 北京 对应的文档，把它与 中国 建立引入式关系
capital = db.capital.find_one({'name':'北京'})
db.country.update_one({'name':'中国'},{'$set':{'capitalId':capital['_id']}})
pprint(db.country.find_one({'name':'中国'}))

# 查询美国的首都信息

