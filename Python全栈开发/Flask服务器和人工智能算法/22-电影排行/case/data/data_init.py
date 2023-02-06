import json, pymongo, os

# 将data目录下的 ranking.json、score.json 保存到数据库中
def data_local():
	client = pymongo.MongoClient('127.0.0.1', 27017)
	db = client['mydb22']

	coll_list = db.list_collection_names()
	for collection in coll_list:
		# 删除集合
		db[collection].drop()

	data_path = './data'
	for maindir, subdir, file_list in os.walk(data_path):
		for file_name in file_list:
			if file_name[file_name.rindex('.'):] == '.json':
				coll = file_name[:file_name.rindex('.')]

				with open(data_path + '/' + file_name, encoding='utf-8') as file:
					str = json.loads(file.read())
					if str is '' or str is None:
						continue
					else:
						data = []
						data.extend(str['RECORDS'])
						db[coll].insert_many(data)
	return db


if __name__ == '__main__':
	data_local()


# 数据说明
# ranking 票房排行
'''
  name : 电影名称
  area : 地区
  avgPrice : 平均票价
  boxOffice : 总票房
  releaseTime : 上映时间
  showCount : 上映场次
  type : 电影类别
'''

# score 豆瓣高分电影
'''
  name : 电影名称
  poster : 电影海报
  rate : 豆瓣评分
'''
