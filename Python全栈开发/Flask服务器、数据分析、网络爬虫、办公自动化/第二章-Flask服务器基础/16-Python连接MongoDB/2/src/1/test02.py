from data_init import db, candy_init

# 初始化糖果数据
candy_init()

if __name__ == '__main__':
    # 在下方写你的代码：将旺仔QQ糖删除

    
    # 查询遍历
    result = db.candy.find()
    for candy in result:
        print(candy)
