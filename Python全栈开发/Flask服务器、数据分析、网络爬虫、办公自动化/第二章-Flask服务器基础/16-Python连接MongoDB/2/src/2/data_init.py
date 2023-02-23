import pymongo


def data_init():
    client = pymongo.MongoClient('127.0.0.1', 27017)
    db = client['mydb4']
     
    if len(db.list_collection_names()) is 0:
        students = [
            {"name": "盖茨", "math": 89, "grade": "4年级"},
            {"name": "特朗普", "math": 79, "grade": "4年级"},
            {"name": "马云", "math": 29, "grade": "2年级"}
        ]
        db.student.insert_many(students)
        stars = [
            {"name": "鹿晗", "fans": "4200w"},
            {"name": "易烊千玺", "fans": "5400w"},
            {"name": "肖战", "fans": "2100w"}
        ]
        db.star.insert_many(stars)
        platforms = [
            {"name": "抖音", "ad_time": "15s", "type": "短视频"},
            {"name": "斗鱼", "ad_time": "10s", "type": "直播"},
            {"name": "快手", "ad_time": "10s", "type": "短视频"}
        ]
        db.platform.insert_many(platforms)

    return db


db = data_init()
