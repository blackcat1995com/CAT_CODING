from data_init import db
from pprint import pprint

# 下方写你的代码:找到混天绫、风火轮、火尖枪对应的文档，把它与 哪吒 建立嵌入式关系
weapons = list(db.weapon.find(
 	{
 		'$or':[
 			{'name':'混天绫'},
 			{'name':'风火轮'},
 			{'name':'火尖枪'}
 		]
 	}

 ))

pprint(weapons)

db.role.update_one({'name':'哪吒'}, {'$set':{'weapon':weapons}})
pprint(db.role.find_one({'name':'哪吒'}))