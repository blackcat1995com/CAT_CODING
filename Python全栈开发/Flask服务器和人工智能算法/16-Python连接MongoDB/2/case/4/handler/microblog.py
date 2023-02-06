from flask import Blueprint, render_template, redirect, request, jsonify, session, make_response

bp = Blueprint('microblog', __name__)

microblogs = [
    {'id': '1', 'username': '小辛辛', 'head': 'head01.jpg', 'photo': 'blog01.png', 'create_time': '2018/12/26'},
    {'id': '2', 'username': 'YUTAR', 'head': 'head02.jpg', 'photo': 'blog02.png', 'create_time': '2018/12/26'},
    {'id': '3', 'username': '赤道', 'head': 'head03.jpg', 'photo': 'blog03.png', 'create_time': '2018/12/26'},
    {'id': '4', 'username': 'Wang Ming', 'head': 'head04.jpg', 'photo': 'blog04.png', 'create_time': '2018/12/26'},
    {'id': '5', 'username': '--中梁--', 'head': 'head05.jpg', 'photo': 'blog05.png', 'create_time': '2018/12/25'},
    {'id': '6', 'username': 'Y-Y', 'head': 'head06.jpg', 'photo': 'blog06.png', 'create_time': '2018/12/25'},
    {'id': '7', 'username': '蘑菇一号', 'head': 'head07.jpg', 'photo': 'blog07.png', 'create_time': '2018/12/25'},
    {'id': '8', 'username': '雇佣兵', 'head': 'head08.jpg', 'photo': 'blog08.png', 'create_time': '2018/12/24'},
    {'id': '9', 'username': '不万能的喜剧', 'head': 'head09.jpg', 'photo': 'blog09.png', 'create_time': '2018/12/24'},
    {'id': '10', 'username': '达达@达', 'head': 'head10.jpg', 'photo': 'blog10.png', 'create_time': '2018/12/24'},
    {'id': '11', 'username': '@@ @@', 'head': 'head11.jpg', 'photo': 'blog11.jpg', 'create_time': '2018/12/23'},
    {'id': '12', 'username': 'Pansy。', 'head': 'head12.jpg', 'photo': 'blog12.jpg', 'create_time': '2018/12/23'},
    {'id': '13', 'username': 'hope', 'head': 'head13.jpg', 'photo': 'blog13.jpg', 'create_time': '2018/12/23'},
    {'id': '14', 'username': '大阿佳@.', 'head': 'head14.jpg', 'photo': 'blog14.jpg', 'create_time': '2018/12/22'},
    {'id': '15', 'username': 'T_T', 'head': 'head15.jpg', 'photo': 'blog15.jpg', 'create_time': '2018/12/22'},
    {'id': '16', 'username': '带牙套的猴子', 'head': 'head16.jpg', 'photo': 'blog16.jpg', 'create_time': '2018/12/22'},
    {'id': '17', 'username': 'DS.大好人๛ก', 'head': 'head17.jpg', 'photo': 'blog17.jpg', 'create_time': '2018/12/21'},
    {'id': '18', 'username': '跌跌荡荡的青春', 'head': 'head18.jpg', 'photo': 'blog18.jpg', 'create_time': '2018/12/21'},
    {'id': '19', 'username': 'sophia', 'head': 'head19.jpg', 'photo': 'blog19.jpg', 'create_time': '2018/12/21'},
    {'id': '20', 'username': 'KKKL', 'head': 'head20.jpg', 'photo': 'blog20.png', 'create_time': '2018/12/21'}
]


def microblog_find(page, count=5, type='paging'):
    '''
    :param page: 页数
    :param count: 每页显示数量
    :param type: 类型，paging表示分页，all表示获取所有，从下标0开始
    :return: 根据 page 返回列表 microblogs 中的对象
    '''

    if type == 'paging':
        start = (page - 1) * count
    elif type == 'init':
        start = 0

    end = page * count

    if start > len(microblogs):
        # 没有更多，返回空列表
        return []

    return microblogs[start:end]


@bp.route('/')
def index():
    # 若没有则重定向到登录页
    if session.get('user') is None:
        return redirect('/user/login')
    user = session['user']

    # 获取Cookie中保存的用户名
    username = request.cookies.get('username', '')

    # 从 cookie 中获取当前页数
    page = request.cookies.get('page')
    if page is None:
        page = 1
    microblog_data = microblog_find(int(page), type='init')

    return render_template('index.html', user=user, microblogs=microblog_data)


@bp.route('/microblog/load', methods=['GET'])
def microblog_load():
    # 从 cookie 中获取当前页数
    page = request.cookies.get('page')
    print(page)
    # page是None，默认加载第2页，否则加载当前页的下一页
    if page is None:
        page = 2
    else:
        page = int(page) + 1
    microblog_data = microblog_find(page)

    response = make_response(jsonify({'data': microblog_data}))

    if len(microblog_data) > 0:
        # 将当前页数 page 保存到 cookie 中
        response.set_cookie("page", str(page))

    return response
