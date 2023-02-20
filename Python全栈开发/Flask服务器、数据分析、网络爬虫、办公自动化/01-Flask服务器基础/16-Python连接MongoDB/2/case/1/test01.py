from data_init import db, balloon_init

# 初始化气球数据
balloon_init()

if __name__ == '__main__':
    # 在下方写你的代码：删除指定位置的气球
    db.balloon.delete_one({'pos': '(1,2)'})
    # 遍历
    result = db.balloon.find()
    for balloon in result:
        print(balloon)
