from data_init import db
from pprint import pprint

# 更新前，打印网易公司文档
pprint(db.company.find_one({'name': '网易'}))
print('-'*50)


# 在下方写你的代码:删除网易公司游戏列表中"创世西游"的游戏id


# 更新后打印网易公司文档
pprint(db.company.find_one({'name': '网易'}))
