import pymongo
from flask import render_template, request, jsonify, session, Blueprint, redirect
from urllib.parse import quote_plus

user = 'root'
password = 'root'
host = '127.0.0.1'
port = 27017

uri = 'mongodb://%s:%s@%s' % (quote_plus(user), quote_plus(password), host)

client = pymongo.MongoClient(uri, port=port)
db = client['farm']

user = Blueprint('user', __name__)

@user.route('/user/register', methods=['GET'])
def register_page():
    return render_template('register.html')


@user.route('/user/login', methods=['GET'])
def login_page():
    return render_template('login.html')


@user.route('/user/register', methods=['POST'])
def register():
    """
    注册农场主
    :return:
    """
    # 获取用户名密码
    username = request.form.get('username')
    password = request.form.get('password')

    # 判断用户名密码是否为空
    if username == '' or password == '':
        return render_template('register.html', msg='用户名密码不能为空')

    # 查询用户名对应的文档
    user = db.user.find_one({'username':username})
    # 如果用户名已经注册，返回带提示信息的注册页面
    if user:
        return render_template('register.html', msg='用户名已经存在')
    
    # 保存用户名密码到数据库
    db.user.insert_one({'username':username, 'password':password, 'coins':100})
    # 重定向到登录页
    return redirect('/user/login')


@user.route('/user/login', methods=['POST'])
def login():
    """
    登录
    :return:
    """
    # 获取用户名和密码
    username = request.form.get('username')
    password = request.form.get('password')
    
    # 判断用户名和密码是否空
    if username == '' or password == '':
        return render_template('login.html', msg='用户名密码不能为空')

    # 查询用户名对应的文档
    user = db.user.find_one({'username':username})

    # 如果用户名不存在，则给出提示信息的登录页
    if user is None:
        return render_template('login.html', msg='用户名不存在，请先注册')
    
    # 如果密码不正确，给出提示信息的登录页
    if user['password'] != password:
        return render_template('login.html', msg='密码错误，请重试')
    
    # 将用户名保存在 session 中
    session['username'] = username
    
    # 重定向到首页
    
    return redirect('/')


def get_user():
    """
    返回用户的所有信息
    :return:
    """
    username = session['username']
    one = db.user.find_one({'username': username})
    result = {"username": one['username'], "coins": one['coins'], "crops": []}
    # 遍历获取所有植物，存到list中
    print(one)

    for key in one:
        print('key =', key)
        if "land" in key and one[key]:
            crop = one[key]
            result['crops'].append(
                {"land": key[-1], "name": crop['crop_name'], "level": crop['level'], "seed_price": crop['seed_price']})
    return result
