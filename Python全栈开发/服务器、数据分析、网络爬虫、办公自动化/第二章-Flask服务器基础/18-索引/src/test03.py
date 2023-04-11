import config
from pprint import pprint

# 若没有初始化数据库，则初始化，若已初始化，则什么都不做
config.init_db()
# 获取数据库
db = config.get_db()

# 在下方写你的代码：获取所有索引，并输出到控制台
