import config
from pprint import pprint

# 若没有初始化数据库，则初始化，若已初始化，则什么都不做
config.init_db()
# 获取数据库
db = config.get_db()

# 删除前索引列表
pprint('删除前')
indexes = list(db.student.list_indexes())
pprint(indexes)

# 在下方写你的代码：删除name索引


# 删除后索引列表
pprint('删除后')
indexes = list(db.student.list_indexes())
pprint(indexes)
