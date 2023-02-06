from flask import Blueprint, render_template, request, jsonify, session, redirect
import random
from config import db
from bson import ObjectId

bp = Blueprint('quiz', __name__)

questions = [
    {"id": 1, "level": 1, "question": "红楼梦的作者是谁？", "option_a": "吴承恩", "option_b": "曹雪芹", "answer": "B"},
    {"id": 2, "level": 2, "question": "玫瑰花属于哪个科？", "option_a": "牡丹科", "option_b": "蔷薇科", "answer": "B"},
    {"id": 3, "level": 2, "question": "爵士音乐起源于哪里？", "option_a": "非洲", "option_b": "南美洲", "answer": "A"},
    {"id": 4, "level": 2, "question": "植树节是每年的哪一天？", "option_a": "2月14日", "option_b": "3月12日", "answer": "B"},
    {"id": 5, "level": 1, "question": "下列哪个乐器是中国发明的？", "option_a": "钢琴", "option_b": "二胡", "answer": "B"},
    {"id": 6, "level": 3, "question": "《西游记》中的火焰山位于？", "option_a": "甘肃", "option_b": "新疆", "answer": "B"},
    {"id": 7, "level": 1, "question": "在行车道上用斑马线等标线或其他方法标示的、规定行人横穿车道的步行范围叫做？", "option_a": "人行横道", "option_b": "地下通道",
     "answer": "A"},
    {"id": 8, "level": 1, "question": "下列这些交通工具中，哪种速度最快？", "option_a": "飞机", "option_b": "轮船", "answer": "A"},
    {"id": 9, "level": 2, "question": "现代钢琴一般有多少个键？", "option_a": "77", "option_b": "88", "answer": "B"},
    {"id": 10, "level": 1, "question": "飞机的飞行高度是3000米，下降了300米，又上升了500米，现在飞机的高度是？", "option_a": "2200米",
     "option_b": "3200米", "answer": "B"},
    {"id": 11, "level": 2, "question": "你该如何称呼你父亲的兄弟的妻子？", "option_a": "舅妈", "option_b": "婶子", "answer": "B"},
    {"id": 12, "level": 1, "question": "驾驶机动车应当随身携带哪种证件？", "option_a": "驾驶证", "option_b": "身份证", "answer": "A"},
    {"id": 13, "level": 1, "question": "你该如何称呼兄弟的儿子？", "option_a": "表弟", "option_b": "侄子", "answer": "B"},
    {"id": 14, "level": 1, "question": "李白笔下的“飞流直下三千尺，疑是银河落九天”指的是哪个风景？", "option_a": "庐山", "option_b": "香山",
     "answer": "A"},
    {"id": 15, "level": 3, "question": "樱桃小丸子的原型其实就是作者本人，她的名字叫？", "option_a": "樱桃子", "option_b": "小丸子", "answer": "A"},
    {"id": 16, "level": 2, "question": "请问以下关于等腰梯形的描述中，不正确的是？", "option_a": "两条腰不相等", "option_b": "两个底角相等",
     "answer": "A"},
    {"id": 17, "level": 2, "question": "小军跟爸爸到外地旅游，爸爸买一张火车票是5元，小军买半票，他们来回一共要付多少钱？", "option_a": "7.5", "option_b": "15",
     "answer": "B"},
    {"id": 18, "level": 4, "question": "请问第一届现代奥运会在哪举行？", "option_a": "法国巴塞罗那", "option_b": "希腊雅典", "answer": "B"},
    {"id": 19, "level": 2, "question": "根据透视关系，同样大小的物体，远处的会比近处的看起来？", "option_a": "更大", "option_b": "更小",
     "answer": "B"},
    {"id": 20, "level": 5, "question": "来孙是指一对夫妻的第几代子孙？", "option_a": "第四代", "option_b": "第五代", "answer": "B"},
    {"id": 21, "level": 3, "question": "以下哪个不是元音？", "option_a": "E", "option_b": "Y", "answer": "B"},
    {"id": 22, "level": 3, "question": "有一种国画的画法，用笔蘸墨汁大片地洒在纸上或绢上，画出物体形象，这被称为？", "option_a": "喷绘", "option_b": "泼墨",
     "answer": "B"},
    {"id": 23, "level": 2, "question": "小提琴（violin）是现代管弦乐队弦乐组中最主要的乐器，现代小提琴有多少根弦？", "option_a": "4", "option_b": "6",
     "answer": "A"},
    {"id": 24, "level": 3, "question": "表示人或者事物、时间、处所、方位等名称的词被称为？", "option_a": "名词", "option_b": "副词", "answer": "A"},
    {"id": 25, "level": 2, "question": "光滑的反义词是？", "option_a": "粗糙", "option_b": "粗犷", "answer": "A"},
    {"id": 26, "level": 2, "question": "使用电力发动，在道路上不依赖固定的轨道行驶的公共交通工具是？", "option_a": "充电车", "option_b": "无轨电车",
     "answer": "B"},
    {"id": 27, "level": 1, "question": "悟空有多少变？", "option_a": "72", "option_b": "36", "answer": "A"},
    {"id": 28, "level": 3, "question": "以迅速而准确的观察力，运用简练的线条扼要的描画出对象的神态、形体、动作等特征的一种画法被称为？", "option_a": "素描",
     "option_b": "速写", "answer": "B"},
    {"id": 29, "level": 2, "question": "一件衣服100元，现在打8折，打折后多少钱？", "option_a": "80", "option_b": "20", "answer": "A"},
    {"id": 30, "level": 4, "question": "避雷针是靠什么发挥作用的？", "option_a": "和大楼串联分担电压", "option_b": "将闪电不经大楼导入地下",
     "answer": "B"},
    {"id": 31, "level": 4, "question": "驾驶人连续驾驶不得超过多长时间？", "option_a": "4小时", "option_b": "6小时", "answer": "A"},
    {"id": 32, "level": 3, "question": "想开车必须考取驾照，在中国考取驾照的最低年龄是？", "option_a": "16", "option_b": "18", "answer": "B"},
    {"id": 33, "level": 4, "question": "Hold on的意思是？", "option_a": "等一下", "option_b": "保持住", "answer": "A"},
    {"id": 34, "level": 2, "question": "英文字母一共有多少个？", "option_a": "24", "option_b": "26", "answer": "B"},
    {"id": 35, "level": 3, "question": "澳大利亚的国宝动物是什么？", "option_a": "袋鼠", "option_b": "树袋熊", "answer": "A"},
    {"id": 36, "level": 5, "question": "姐妹的丈夫之间的关系通常叫做？", "option_a": "叔伯", "option_b": "连襟", "answer": "B"},
    {"id": 37, "level": 2, "question": "在数学方程式中英文字母X通常表示什么？", "option_a": "未知数", "option_b": "指数", "answer": "A"},
    {"id": 38, "level": 3, "question": "狗热时用什么散热？", "option_a": "舌头", "option_b": "皮肤", "answer": "A"},
    {"id": 39, "level": 2, "question": "蜡笔小新的妈妈叫做？", "option_a": "美伢", "option_b": "美惠", "answer": "A"},
    {"id": 40, "level": 3, "question": "下列哪个植物是生长在热带的？", "option_a": "苹果树", "option_b": "椰子树", "answer": "B"},
    {"id": 41, "level": 1, "question": "以下字母的排列顺序错误的一组是？", "option_a": "OPQ", "option_b": "JMK", "answer": "B"},
    {"id": 42, "level": 4, "question": "数学符号中的“0”起源于？", "option_a": "古印度", "option_b": "古希腊", "answer": "A"},
    {"id": 43, "level": 5, "question": "国画中单用墨色线条勾描形象而不施色彩的画法叫做？", "option_a": "白描", "option_b": "工笔", "answer": "A"},
    {"id": 44, "level": 4, "question": "“三峡水电站”位于？", "option_a": "湖南", "option_b": "湖北", "answer": "B"},
    {"id": 45, "level": 2, "question": "0属于正数吗？", "option_a": "属于", "option_b": "不属于", "answer": "B"},
    {"id": 46, "level": 5, "question": "以下哪个选项不属于全球三大生态系统？", "option_a": "河流", "option_b": "森林", "answer": "A"},
    {"id": 47, "level": 2, "question": "以下这个算式的结果是（23+50）x18x28x38x0？", "option_a": "65535", "option_b": "0",
     "answer": "B"},
    {"id": 48, "level": 2, "question": "下列动画，属于国产美术片的是？", "option_a": "大闹天宫", "option_b": "猫和老鼠", "answer": "A"},
    {"id": 49, "level": 4, "question": "我们吃的胡萝卜属于植物的哪个器官？", "option_a": "根", "option_b": "茎", "answer": "A"},
    {"id": 50, "level": 3, "question": "《茶馆》的作者是？", "option_a": "鲁迅", "option_b": "老舍", "answer": "B"},
    {"id": 51, "level": 3, "question": "中华人民共和国国歌《义勇军进行曲》的作曲是？", "option_a": "田汉", "option_b": "聂耳", "answer": "B"},
    {"id": 52, "level": 3, "question": "下列哪个是成功的名词？", "option_a": "success", "option_b": "successful", "answer": "A"},
    {"id": 53, "level": 3, "question": "人体最坚硬的部分是？", "option_a": "颅骨", "option_b": "牙齿", "answer": "B"},
    {"id": 54, "level": 2, "question": "以下哪句话用来表示感谢？", "option_a": "Thank you", "option_b": "You are welcome",
     "answer": "A"},
    {"id": 55, "level": 3, "question": "2008年第29届北京奥运会使用的奖牌让中外运动员及观众眼前一亮，它是？", "option_a": "金镶玉", "option_b": "象牙玉",
     "answer": "A"},
    {"id": 56, "level": 2, "question": "猫和狗一般可以活多少年？", "option_a": "十几年", "option_b": "三十几年", "answer": "A"},
    {"id": 57, "level": 1, "question": "两岸猿声啼不住的下一句是什么？", "option_a": "一行白鹭上青天", "option_b": "轻舟已过万重山", "answer": "B"},
    {"id": 58, "level": 5, "question": "请问第一届冬季奥林匹克运动会在哪举行？", "option_a": "法国夏蒙尼", "option_b": "俄罗斯莫斯科", "answer": "A"},
    {"id": 59, "level": 5, "question": "世界男子团体羽毛球锦标赛又被称为？", "option_a": "汤姆斯杯", "option_b": "苏迪曼杯", "answer": "A"},
    {"id": 60, "level": 2, "question": "大头儿子的妈妈叫什么？", "option_a": "大头妈妈", "option_b": "围裙妈妈", "answer": "B"},
    {"id": 61, "level": 4, "question": "是不是所有动物的血都是红色的？", "option_a": "是", "option_b": "不是", "answer": "B"},
    {"id": 62, "level": 5, "question": "足踝扭伤后应该？", "option_a": "冷敷", "option_b": "热敷", "answer": "A"},
    {"id": 63, "level": 5, "question": "无偿献血是否会降低免疫力？", "option_a": "会", "option_b": "不会", "answer": "B"},
    {"id": 64, "level": 2, "question": "小猪佩奇的弟弟叫什么？", "option_a": "乔治", "option_b": "乔恩", "answer": "A"},
    {"id": 65, "level": 5, "question": "食醋是否能够去除刀上的铁锈？", "option_a": "是", "option_b": "否", "answer": "A"},
    {"id": 66, "level": 5, "question": "卧室中的植物是否越多越好？", "option_a": "是", "option_b": "否", "answer": "B"},
    {"id": 67, "level": 5, "question": "双层真空玻璃能不能隔音？", "option_a": "能", "option_b": "不能", "answer": "A"},
    {"id": 68, "level": 3, "question": "故宫旧称是什么？", "option_a": "紫禁城", "option_b": "圆明园", "answer": "A"},
    {"id": 69, "level": 5, "question": "在月球上能不能放风筝？", "option_a": "能", "option_b": "不能", "answer": "B"},
    {"id": 70, "level": 5, "question": "血液中血红细胞的作用是？", "option_a": "输送氧气", "option_b": "抵御病原", "answer": "A"},
    {"id": 71, "level": 4, "question": "动漫角色皮卡丘的技能是？", "option_a": "喷火", "option_b": "放电", "answer": "B"},
    {"id": 72, "level": 4, "question": "暖水壶的银色内胆有什么作用？", "option_a": "保温", "option_b": "防摔", "answer": "A"},
    {"id": 73, "level": 4, "question": "容量单位1升等于多少毫升？", "option_a": "100", "option_b": "1000", "answer": "B"},
    {"id": 74, "level": 4, "question": "乐山大佛位于？", "option_a": "四川", "option_b": "湖北", "answer": "A"}
]


@bp.route('/quiz', methods=['GET'])
def quiz_index():
    if 'user' not in session:
        return redirect("/user/login")
    return render_template('quiz.html')


@bp.route('/quiz/question', methods=['GET'])
def quiz_question():
    level = int(request.args.get('level'))

    # 之前的实现
    quiz_data = quiz_find(level=level)
    # 在下方写你的代码：从数据库中查询对应等级的题目


    questions = random.sample(quiz_data, 10)
    for question in questions:
        question['_id'] = str(question['_id'])
    return jsonify({'data': questions})


@bp.route('/quiz/check', methods=['GET'])
def quiz_check():
    quiz_id = ObjectId(request.args.get('quiz_id'))
    answer = request.args.get('answer')

    # 之前的实现（数据在内存）
    quiz_data = quiz_find(id=quiz_id, answer=answer)
    # 在下方写你的代码：从数据库中查询对应id和答案的题目


    if quiz_data is not None:
        return jsonify({'data': 'right'})
    else:
        return jsonify({'data': 'wrong'})


@bp.route('/quiz/addCoins', methods=['GET'])
def add_coins():
    if 'user' not in session:
        redirect('/user/login')
    user = session['user']
    # 获取请求参数coins
    coins = request.args.get('coins')
    # 更新金币，增加金币的数量
    db.user.update_one({'username': user['username']}, {'$inc': {'coins': int(coins)}})
    # 更新session
    user['coins'] = user['coins'] + int(coins)
    session['user'] = user
    return 'success'


def quiz_find(id=None, level=None, answer=None):
    '''
        一站到底数据查询方法
    param:id 题目的id
    param:level 题目的难度等级
    param:answer 题目的正确答案
        可以通过level获取一个等级的所有题目，也可以通过题目id和答案获取一个题目，用于题目的对错检验
    '''
    list = []
    # 按照level查询
    if level is not None and id is None:
        for ques in questions:
            if ques['level'] == int(level):
                list.append(ques)
    # 按照id和answer查询
    if id is not None and answer is not None:
        for ques in questions:
            if ques['id'] == int(id) and ques['answer'] == answer:
                list.append(ques)
    # 返回结果列表
    return list
