from data_init import db
from pprint import pprint

# 更新前，打印腾讯公司文档
pprint(db.company.find_one({'name': '腾讯'}))
print('-' * 50)

# 在下方写你的代码:找到'天涯明月刀手游'，把他添加到'腾讯'公司的游戏id列表中

# 更新后打印腾讯公司文档
pprint(db.company.find_one({'name': '腾讯'}))
