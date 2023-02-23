import pymongo


def data_init():
    # 建立连接
    client = pymongo.MongoClient('127.0.0.1', 27017)
    # 创建数据库
    db = client['mydb8']
    db.drop_collection('cartoon')
    b1 = list(db.staffs.find())
    if len(b1) <= 0:
        db.staffs.insert_many(
            [
                {'name': '李明康', 'pass': 'Yes', 'health_code': 'No'},
                {'name': '李小刚', 'pass': 'No', 'health_code': 'No'},
                {'name': '张建豪', 'pass': 'No', 'health_code': 'Yes'},
                {'name': '周慧慧', 'pass': 'Yes', 'health_code': 'Yes'},
                {'name': '刘聪聪', 'pass': 'No', 'health_code': 'No'},
                {'name': '张丽', 'pass': 'No', 'health_code': 'Yes'},
                {'name': '杨洋', 'pass': 'Yes', 'health_code': 'No'},
                {'name': '钱帆', 'pass': 'No', 'health_code': 'No'},
                {'name': '马星星', 'pass': 'No', 'health_code': 'No'},
                {'name': '刘颖', 'pass': 'No', 'health_code': 'Yes'},
                {'name': '董丽娜', 'pass': 'Yes', 'health_code': 'Yes'},
                {'name': '徐菲', 'pass': 'No', 'health_code': 'No'},
                {'name': '李响', 'pass': 'Yes', 'health_code': 'No'}

            ]
        )

    b2 = list(db.cartoon.find())
    if len(b2) <= 0:
        db.cartoon.insert_many(
            [
                {'name': '一人之下', 'author': '动漫堂', 'number': 4798343, 'type': '精品'},
                {'name': '愿望方', 'author': '动漫堂', 'number': 133485, 'type': '普通'},
                {'name': '逆鳞', 'author': '两只猫', 'number': 193005, 'type': '普通'},
                {'name': '恰似寒光遇骄阳', 'author': '火力熊猫', 'number': 473868, 'type': '普通'},
                {'name': '校园高手', 'author': '比格熊', 'number': 1528496, 'type': '精品'},
                {'name': '天籁之音', 'author': '两只猫', 'number': 1710087, 'type': '精品'},
                {'name': '狩人', 'author': '比格熊', 'number': 743245, 'type': '普通'},
                {'name': '败者为寇', 'author': 'KG工坊', 'number': 495884, 'type': '普通'},
                {'name': '全职法师', 'author': '火力熊猫', 'number': 1407149, 'type': '精品'},
                {'name': '妄想理论', 'author': '动漫堂', 'number': 142845, 'type': '普通'},
                {'name': '传武', 'author': 'KG工坊', 'number': 1512169, 'type': '精品'},
                {'name': '银之守墓人', 'author': '两点十分动漫', 'number': 2886231, 'type': '精品'},
                {'name': '造物法则', 'author': '百漫文化', 'number': 402899, 'type': '普通'},
                {'name': '兵魂', 'author': '两点十分动漫', 'number': 160919, 'type': '普通'},
                {'name': '六界行者', 'author': '比格熊', 'number': 107460, 'type': '普通'}

            ]
        )
    
    b3 = list(db.heros.find())
    if len(b3) <= 0:
        db.heros.insert_many(
            [
                {'name': '孙策', 'type': '战士', 'skill': '怒潮', 'partner': '哪吒、牛魔王'},
                {'name': '鲁班大师', 'type': '辅助', 'skill': '稷下科技', 'partner': '苏烈'},
                {'name': '李信', 'type': '战士', 'skill': '灰暗利刃', 'partner': '张飞、孙膑'},
                {'name': '张飞', 'type': '坦克', 'skill': '黑暗潜能', 'partner': '黄忠、后裔'},
                {'name': '杨玉环', 'type': '法师', 'skill': '惊鸿调', 'partner': '鲁班、程咬金'},
                {'name': '干将莫邪', 'type': '法师', 'skill': '比翼同心', 'partner': '钟无艳'},
                {'name': '司马懿', 'type': '刺客', 'skill': '静默之语', 'partner': '项羽、干将莫邪'},
                {'name': '花木兰', 'type': '战士', 'skill': '空烈斩', 'partner': '庄周、刘邦'},
                {'name': '妲己', 'type': '法师', 'skill': '失心', 'partner': '孙悟空、阿珂'},
                {'name': '大乔', 'type': '辅助', 'skill': '川流不息', 'partner': '狄仁杰、花木兰'}
                
            ]
        )
        
    return db


db = data_init()
