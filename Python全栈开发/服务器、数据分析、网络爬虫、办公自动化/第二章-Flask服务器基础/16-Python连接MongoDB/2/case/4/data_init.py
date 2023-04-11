import pymongo


def data_init():
    # 建立连接
    client = pymongo.MongoClient('127.0.0.1', 27017)
    # 创建数据库
    db = client['mydb7']
    b1 = list(db.residents.find())
    if len(b1) <= 0:
        db.residents.insert_many(
            [
                {"name": "李键", "temperature": "正常", "mask": "No"},
                {"name": "张萌", "temperature": "不正常", "mask": "Yes"},
                {"name": "刘笑笑", "temperature": "正常", "mask": "Yes"},
                {"name": "陈一帆", "temperature": "不正常", "mask": "No"},
                {"name": "赵杰", "temperature": "正常", "mask": "No"},
                {"name": "刘倍", "temperature": "正常", "mask": "Yes"},
                {"name": "曹正", "temperature": "正常", "mask": "No"},
                {"name": "张冬青", "temperature": "正常", "mask": "Yes"},
                {"name": "周宁", "temperature": "不正常", "mask": "No"}
            ]
        )
    b2 = list(db.cartoons.find())
    if len(b2) <= 0:
        db.cartoons.insert_many(
            [
                {"name": "樱木花道", "gender": "男", "age": 16, "works": "灌篮高手"},
                {"name": "流川枫", "gender": "男", "age": 16, "works": "灌篮高手"},
                {"name": "赤木晴子", "gender": "女", "age": 15, "works": "灌篮高手"},
                {"name": "路飞", "gender": "男", "age": 17, "works": "海贼王"},
                {"name": "娜美", "gender": "女", "age": 18, "works": "海贼王"},
                {"name": "索隆", "gender": "男", "age": 19, "works": "海贼王"},
                {"name": "乌索普", "gender": "男", "age": 17, "works": "海贼王"},
                {"name": "漩涡鸣人", "gender": "男", "age": 12, "works": "火影忍者"},
                {"name": "宇智波佐助", "gender": "男", "age": 12, "works": "火影忍者"},
                {"name": "日向雏田", "gender": "女", "age": 13, "works": "火影忍者"},
                {"name": "春野樱", "gender": "女", "age": 12, "works": "火影忍者"},
                {"name": "山中井野", "gender": "女", "age": 13, "works": "火影忍者"}
            ]

        )
    b3 = list(db.scores.find())
    if len(b3) <= 0:
        db.scores.insert_many(
            [
                {'grade': '高一', 'name': '何一凡', 'subject': '数学', 'score': 89},
                {'grade': '高二', 'name': '刘玉云', 'subject': '语文', 'score': 76},
                {'grade': '高一', 'name': '李洲洲', 'subject': '数学', 'score': 102},
                {'grade': '高三', 'name': '张浩楠', 'subject': '英语', 'score': 109},
                {'grade': '高一', 'name': '贺涛然 ', 'subject': '数学', 'score': 95},
                {'grade': '高二', 'name': '刘梦', 'subject': '数学', 'score': 104},
                {'grade': '高二', 'name': '马浩鑫', 'subject': '语文', 'score': 99},
                {'grade': '高一', 'name': '孟浩轩', 'subject': '英语', 'score': 73},
                {'grade': '高一', 'name': '张蒙', 'subject': '语文', 'score': 86},
                {'grade': '高三', 'name': '路冰', 'subject': '数学', 'score': 83},
                {'grade': '高一', 'name': '郭阳', 'subject': '数学', 'score': 106},
                {'grade': '高一', 'name': '刘宇飞', 'subject': '英语', 'score': 110}
            ]
        )
    return db


db = data_init()
