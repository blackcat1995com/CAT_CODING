import config, time


# 获取平均查询用时
def check_time():
    
    time1 = time.time()

    for i in range(100):
        db.student.find_one({'name': '宦寻珍'})

    time2 = time.time()

    time_avg = (time2 - time1) / 100

    return time_avg


# 若没有初始化数据库，则初始化，若已初始化，则什么都不做
config.init_db()
# 获取数据库
db = config.get_db()

# 在下方写你的代码：查看未创建索引前查询用时
time_avg = check_time()
print('未使用索引，平均查询用时%fs' % time_avg)

# 在字段name上创建升序索引
db.student.create_index([('name', 1)])
 
# 查看使用索引查询用时
time_avg = check_time()
print('使用索引，平均查询用时%fs' % time_avg)
