from data_init import db


name = input('请输入要查询的学生姓名：')
# 在下方写你的代码：添加异常处理代码

try:
    student = db.student.find_one({'name': name})
    print(
        '学生：%s，年龄：%s，性别：%s' % (student['name'], student['age'], student['gender'])
    )
except Exception as e:

    print('错误信息：', e)
