from data_init import db
from pprint import pprint

# 在下方写你的代码:找到皮卡丘、杰尼龟对应的文档，
pokemon_list = list(db.pokemon.find({
		'$or':[
			{'name':'皮卡丘'},
			{'name':'杰尼龟'}
		]
	}))
# 构造皮卡丘、杰尼龟的 id 列表
id_list = [dic['_id'] for dic in pokemon_list]
print(pokemon_list)
print(id_list)
# 把它们与 小智 建立引用式关系
db.role.update_one({'name':'小智'},{'$set':{'pokemonId':id_list}})

pprint(db.role.find_one({'name':'小智'}))