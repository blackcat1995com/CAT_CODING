import pymongo
from bson import ObjectId


def data_init():
    client = pymongo.MongoClient('mongodb://localhost:27017/')
    db = client.mydb23
    db.country.delete_many({})
    db.country.insert_many(
        [
            {'name': '中国', 'area': '960万平方千米', 'population': '14亿'},
            {'name': '美国', 'area': '937万平方千米', 'population': '3.3亿',
             'capitalId': ObjectId("5f64559e69ad7139bc4eb3cc")},
            {'name': '日本', 'area': '37.7962万平方千米', 'population': '1.26亿',
             'capitalId': ObjectId("5f64559e69ad7139bc4eb3cd")},
        ]
    )
    db.capital.delete_many({})
    db.capital.insert_many(
        [
            {"_id": ObjectId("5d3574b14d2f71241800528d"), 'name': '北京', 'area': '16410.54平方千米',
             'population': '2153.6万人'},
            {"_id": ObjectId("5f64559e69ad7139bc4eb3cc"), 'name': '华盛顿哥伦比亚特区', 'area': '177平方千米', 'population': '70万人'},
            {"_id": ObjectId("5f64559e69ad7139bc4eb3cd"), 'name': '东京', 'area': '2155平方千米', 'population': '1392万人'},

        ]
    )
    db.pokemon.delete_many({})
    db.role.delete_many({})
    pokemons = [
        {"_id": ObjectId("5d3574b14d2f71241800528d"), "name": "皮卡丘", "height": "0.4m",
         "weight": "6kg", "attribute": "电"},
        {"_id": ObjectId("5d3574b24d2f71241800528e"), "name": "火稚鸡", "height": "0.4m",
         "weight": "2.5kg", "attribute": "炎"},
        {"_id": ObjectId("5d3574b24d2f71241800528f"), "name": "杰尼龟", "height": "0.5m",
         "weight": "9.0kg", "attribute": "水"},
        {"_id": ObjectId("5d3574b24d2f712418005290"), "name": "大岩蛇", "height": "8.8m",
         "weight": "210.0kg", "attribute": "岩石+地上"},
        {"_id": ObjectId("5d3574b24d2f712418005291"), "name": "波加曼", "height": "0.4m",
         "weight": "5.2kg", "attribute": "水"},
        {"_id": ObjectId("5d3574b24d2f712418005292"), "name": "螺钉地鼠", "height": "0.3m",
         "weight": "8.5kg", "attribute": "地面"},
        {"_id": ObjectId("5d3574b24d2f712418005293"), "name": "花椰猴", "height": "0.6m",
         "weight": "10.5kg", "attribute": "草"},
        {"_id": ObjectId("5d3574b24d2f712418005294"), "name": "宝石海星", "height": "1.1m",
         "weight": "80.0kg", "attribute": "水+超能力"},
        {"_id": ObjectId("5d3574b24d2f712418005295"), "name": "飞天螳螂", "height": "1.5m",
         "weight": "56.0kg", "attribute": "虫+飞行"},
        {"_id": ObjectId("5d3574b24d2f712418005296"), "name": "小拳石", "height": "0.4m",
         "weight": "20.0kg", "attribute": "岩石+地面"},
    ]
    roles = [
        {"name": "小智", "gender": "男"},
        {"name": "小遥", "gender": "女", "pokemonId": [ObjectId("5d3574b24d2f71241800528e")]},
        {"name": "小茂", "gender": "男", "pokemonId": [ObjectId("5d3574b24d2f71241800528f")]},
        {"name": "小刚", "gender": "男",
         "pokemonId": [ObjectId("5d3574b24d2f712418005290"), ObjectId("5d3574b24d2f712418005296")]},
        {"name": "小光", "gender": "女", "pokemonId": [ObjectId("5d3574b24d2f712418005291")]},
        {"name": "艾莉丝", "gender": "女", "pokemonId": [ObjectId("5d3574b24d2f712418005292")]},
        {"name": "天桐", "gender": "男", "pokemonId": [ObjectId("5d3574b24d2f712418005293")]},
        {"name": "小霞", "gender": "女", "pokemonId": [ObjectId("5d3574b24d2f712418005294")]},
        {"name": "小建", "gender": "男", "pokemonId": [ObjectId("5d3574b24d2f712418005295")]}
    ]

    db.pokemon.insert_many(pokemons)
    db.role.insert_many(roles)

    return db


db = data_init()
