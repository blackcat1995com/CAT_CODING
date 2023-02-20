import datetime
from data_init import db
from flask import Blueprint, request, render_template, jsonify

date = Blueprint('date', __name__)


@date.route('/')
def index():
    return render_template('date.html')


@date.route('/delete')
def delete_date():
    date = request.args.get('date')
    time = datetime.datetime.strptime(date, '%Y-%m-%d')
    db.calendar.delete_many({'name': '王小二', 'time': time})
    return jsonify({'result': 'success'})


@date.route('/year')
def get_year():
    year = int(request.args.get('year'))
    data = list(
        db.calendar.find({'time': {"$gte": datetime.datetime(year, 1, 1), "$lt": datetime.datetime(year, 12, 31)}}))
    for dic in data:
        dic['_id'] = str(dic['_id'])
        dic['time'] = datetime.datetime.strftime(dic['time'], '%Y-%m-%d %H:%M:%S')
    return jsonify(data)
