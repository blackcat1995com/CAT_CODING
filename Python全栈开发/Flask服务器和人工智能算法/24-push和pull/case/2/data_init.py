import pymongo
from bson import ObjectId


def data_init():
    client = pymongo.MongoClient('mongodb://localhost:27017/')
    db = client.mydb24
    db.park.delete_many({})
    db.children.delete_many({})
    db.park.insert_many(
        [
            {'_id': ObjectId('5d43f8eddf02a9cdb5e3186a'), 'name': '香港迪士尼游乐园', 'size': '126公顷', 'adress': '香港新界大屿山'},
            {'_id': ObjectId('5d43f8eddf02a9cdb5e3186b'), 'name': '宁波市凤凰山主题公园', 'size': '26公顷',
             'adress': '浙江省宁波市的北仑区主城区'},
            {'_id': ObjectId('5d43f8eddf02a9cdb5e3186c'), 'name': '深圳欢乐谷', 'size': '35公顷', 'adress': '深圳市南山区侨城西街18号'},
            {'_id': ObjectId('5d43f8eddf02a9cdb5e3186d'), 'name': '苏州乐园', 'size': '54公顷', 'adress': '江苏省苏州新区中心'},
            {'_id': ObjectId('5d43f8eddf02a9cdb5e3186e'), 'name': '杭州未来世界公园', 'size': '1.6公顷', 'adress': '浙江省杭州市'},
            {'_id': ObjectId('5d43f8eddf02a9cdb5e3186f'), 'name': '广州长隆欢乐世界', 'size': '133公顷', 'adress': '广州番禺迎宾路'},
            {'_id': ObjectId('5d43f8eddf02a9cdb5e31870'), 'name': '常州环球动漫嬉戏谷乐园', 'size': '74.13公顷',
             'adress': '江苏省常州市武进区太湖湾度假区'},
            {'_id': ObjectId('5d43f8eddf02a9cdb5e31871'), 'name': '大连发现王国', 'size': '47公顷',
             'adress': '辽宁省大连市金石滩国家旅游度假区'},
            {'_id': ObjectId('5d43f8eddf02a9cdb5e31872'), 'name': '北京欢乐谷', 'size': '56公顷',
             'adress': '北京市朝阳区京哈高速与东四环南路交汇处'},
            {'_id': ObjectId('5d43f8eddf02a9cdb5e31873'), 'name': '上海迪士尼乐园', 'size': '390公顷',
             'adress': '上海市浦东新区川沙镇黄赵路310号'},
        ]
    )

    db.children.insert_many(
        [
            {'_id': ObjectId('5d43f8eedf02a9cdb5e31874'), 'name': '王子博', 'age': 10, 'grade': '三年级',
             'parkId': [ObjectId('5d43f8eddf02a9cdb5e3186a'), ObjectId('5d43f8eddf02a9cdb5e3186c')]},
            {'_id': ObjectId('5d43f8eedf02a9cdb5e31875'), 'name': '陈东', 'age': 11, 'grade': '四年级',
             'parkId': [ObjectId('5d43f8eddf02a9cdb5e3186a'), ObjectId('5d43f8eddf02a9cdb5e31872')]},
            {'_id': ObjectId('5d43f8eedf02a9cdb5e31876'), 'name': '李安妮', 'age': 12, 'grade': '五年级',
             'parkId': [ObjectId('5d43f8eddf02a9cdb5e31871'), ObjectId('5d43f8eddf02a9cdb5e31872')]},
        ]
    )
    db.address.delete_many({})
    db.role.delete_many({})
    db.address.insert_many(
        [
            {'_id': ObjectId('5fb0cc3e69ad713df0b93434'), 'local': '平顶山莲花洞', 'monster': '金角大王、银角大王',
             'event': '悟空斗智斗勇，骗取葫芦、净瓶、宝剑、扇子、魔绳五件宝器，降伏二怪'},
            {'_id': ObjectId('5fb0cc3e69ad713df0b93435'), 'local': '乌鸡国', 'monster': '狮精',
             'event': '国王鬼魂求告唐僧搭救，师徒救活国王，降服狮精'},
            {'_id': ObjectId('5fb0cc3e69ad713df0b93436'), 'local': '车迟国', 'monster': '虎力鹿力、羊力',
             'event': '悟空等与三法师斗法，妖魔战败，现原形。'},
            {'_id': ObjectId('5fb0cc3e69ad713df0b93437'), 'local': '观音院', 'monster': '黑风怪', 'event': '袈裟被黑风怪窃走，请观音降服'},
            {'_id': ObjectId('5fb0cc3e69ad713df0b93438'), 'local': '通天河', 'monster': '金鱼精',
             'event': '金鱼精作法把唐僧摄人水府，观音赶来，收走金鱼精'},
            {'_id': ObjectId('5fb0cc3e69ad713df0b93439'), 'local': '黄风岭', 'monster': '黄风怪',
             'event': '悟空请来须弥山灵吉菩萨，收伏此怪'},
            {'_id': ObjectId('5fb0cc3e69ad713df0b9343a'), 'local': '金兜洞', 'monster': '青牛精', 'event': '悟空请太上老君，责其收伏青牛。'},
            {'_id': ObjectId('5fb0cc3e69ad713df0b9343b'), 'local': '琵琶洞', 'monster': '蝎子精',
             'event': '悟空请来昴日星官化作大公鸡，使妖怪现原形而死'},
            {'_id': ObjectId('5fb0cc3e69ad713df0b9343c'), 'local': '白虎岭', 'monster': '白骨精', 'event': '悟空三打白骨精'},
            {'_id': ObjectId('5fb0cc3e69ad713df0b9343d'), 'local': '朱紫国', 'monster': '金毛统','event': '悟空为国王治病，打败妖怪金毛统，救回王后'},
            {'_id': ObjectId('5fb0cc3e69ad713df0b9343e'), 'local': '狮驼山', 'monster': '青毛狮子、黄牙老象、金翅大鹏鸟',
             'event': '众菩萨罗汉帮助降伏三怪'},
        ]
    )
    db.role.insert_many(
        [
            {'_id': ObjectId('5fb0cc3e69ad713df0b9343d'), 'name': '唐僧', 'alias': '唐三藏', 'weapon': '九环锡杖',
             'addressId': [ObjectId('5fb0cc3e69ad713df0b93434'), ObjectId('5fb0cc3e69ad713df0b93435'),
                           ObjectId('5fb0cc3e69ad713df0b93436'), ObjectId('5fb0cc3e69ad713df0b93437'),
                           ObjectId('5fb0cc3e69ad713df0b93438'), ObjectId('5fb0cc3e69ad713df0b93439'),
                           ObjectId('5fb0cc3e69ad713df0b9343a'), ObjectId('5fb0cc3e69ad713df0b9343b'),
                           ObjectId('5fb0cc3e69ad713df0b9343e')
                           ]}
        ]
    )

    return db


db = data_init()
