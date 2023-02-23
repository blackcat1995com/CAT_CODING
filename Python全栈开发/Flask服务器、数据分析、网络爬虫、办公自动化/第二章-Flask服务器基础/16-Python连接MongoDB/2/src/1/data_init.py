# 导入pymongo
import pymongo

# 建立连接
client = pymongo.MongoClient('127.0.0.1', 27017)
# 创建数据库
db = client['mydb3']


def balloon_init():
    b = list(db.balloon.find())
    if len(b) > 0:
        return
    balloons = [
        {'pos': '(1,1)', 'color': 'blue'},
        {'pos': '(1,2)', 'color': 'blue'},
        {'pos': '(1,3)', 'color': 'blue'},
        {'pos': '(1,4)', 'color': 'blue'},
        {'pos': '(2,1)', 'color': 'red'},
        {'pos': '(2,2)', 'color': 'red'},
        {'pos': '(2,3)', 'color': 'red'},
        {'pos': '(3,1)', 'color': 'blue'},
        {'pos': '(3,2)', 'color': 'blue'}
    ]
    db.balloon.insert_many(balloons)


def candy_init():
    c = list(db.candy.find())
    if len(c) > 0:
        return
    candies = [
        {'name': '旺仔QQ糖', 'price': '1'},
        {'name': '棒棒糖', 'price': '1'},
        {'name': '棉花糖', 'price': '2'},
        {'name': '大白兔奶糖', 'price': '2'},
        {'name': '水果硬糖', 'price': '1'},
    ]
    db.candy.insert_many(candies)


def garbage_init():
    g = list(db.garbage.find())
    if len(g) > 0:
        return
    garbages = [
        {'name': '废灯管', 'type': '有害垃圾'},
        {'name': '废电池', 'type': '有害垃圾'},
        {'name': '过期药品', 'type': '有害垃圾'},
        {'name': '菜叶', 'type': '厨余垃圾'},
        {'name': '果皮', 'type': '厨余垃圾'},
        {'name': '枯树叶', 'type': '厨余垃圾'},
        {'name': '牛奶盒', 'type': '可回收垃圾'},
        {'name': '饮料罐', 'type': '可回收垃圾'},
        {'name': '鸡蛋壳', 'type': '厨余垃圾'},
        {'name': '化妆品', 'type': '有害垃圾'},
        {'name': '硬纸板', 'type': '可回收垃圾'}
    ]
    db.garbage.insert_many(garbages)


def pencil_box_init():
    p = list(db.pencil_box.find())
    if len(p) > 0:
        return
    stationery = [
        {'name': '铅笔', 'price': '1'},
        {'name': '圆珠笔', 'price': '1'},
        {'name': '橡皮', 'price': '1'},
        {'name': '直尺', 'price': '2'},
        {'name': '圆规', 'price': '5'},
        {'name': '钢笔', 'price': '15'},
        {'name': '卷笔刀', 'price': '2'}
    ]
    db.pencil_box.insert_many(stationery)
