import pymongo, json


def nba_init():
    client = pymongo.MongoClient('127.0.0.1', 27017)
    db = client['mydb10']
    with open('./data/players.json', encoding='utf-8') as p:
        str = p.read()
        j = json.loads(str)
        data_list = j['RECORDS']
        if len(list(db.players.find())) <= 0:
            for data in data_list:
                for k, v in data.items():
                    if k == 'team':
                        continue
                    if v.strip() == '':
                        data[k] = '0'
                data['assists'] = float(data['assists'])
                data['blocking'] = float(data['blocking'])
                data['foul'] = float(data['foul'])
                data['games_played'] = int(data['games_played'])
                data['lose'] = int(data['lose'])
                data['rebound'] = float(data['rebound'])
                data['score'] = float(data['score'])
                data['steals'] = float(data['steals'])
                data['time'] = float(data['time'])
                data['win'] = int(data['win'])
                db.players.insert_one(data)
    return db


db = nba_init()
