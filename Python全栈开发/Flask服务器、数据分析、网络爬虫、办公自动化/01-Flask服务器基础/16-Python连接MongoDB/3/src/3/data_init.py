import pymongo, json


def apps_init():
    client = pymongo.MongoClient('127.0.0.1', 27017)
    db = client['mydb11']
    with open('./data/apps.json', encoding='utf-8') as p:
        str = p.read()
        j = json.loads(str)
        data_list = j
        if len(list(db.apps.find())) <= 0:
            for data in data_list:
                data['ranking'] = int(data['ranking'])
                db.apps.insert_one(data)
    return db


db = apps_init()
