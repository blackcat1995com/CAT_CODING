from flask import Blueprint, render_template, request, jsonify, session, redirect
import random
from config import db
from bson import ObjectId

bp = Blueprint('quiz', __name__)


@bp.route('/quiz', methods=['GET'])
def quiz_index():
    if 'user' not in session:
        return redirect("/user/login")
    return render_template('quiz.html')


@bp.route('/quiz/question', methods=['GET'])
def quiz_question():
    level = int(request.args.get('level'))
    # 在下方写你的代码：从数据库中查询对应等级的题目
    quiz_data = list(db.quiz.find({'level': level}))
    questions = random.sample(quiz_data, 10)
    for question in questions:
        question['_id'] = str(question['_id'])
    return jsonify({'data': questions})


@bp.route('/quiz/check', methods=['GET'])
def quiz_check():
    quiz_id = ObjectId(request.args.get('quiz_id'))
    answer = request.args.get('answer')
    # 在下方写你的代码：从数据库中查询对应id和答案的题目
    quiz_data = db.quiz.find_one({'_id': quiz_id, 'answer': answer})
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
