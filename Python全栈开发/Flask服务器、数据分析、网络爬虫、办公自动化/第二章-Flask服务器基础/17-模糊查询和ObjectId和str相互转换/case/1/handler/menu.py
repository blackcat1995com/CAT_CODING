import math
from data_init import db
from flask import Blueprint, render_template, jsonify, request

menu = Blueprint('cook', __name__)


@menu.route('/')
def home():
    return render_template('menu.html')


@menu.route('/allData')
def allData():
    page = int(request.args.get('page'))
    data = list(db.menu.find().skip((page - 1) * 6).limit(6))

    for dic in data:
        dic['_id'] = str(dic['_id'])
    return jsonify(data)


@menu.route('/allPage')
def allPage():
    counts = int(db.menu.estimated_document_count())
    pages = math.ceil(counts / 6)
    return jsonify({'pages': pages, 'counts': counts})


@menu.route('/getPages')
def getPages():
    tag = request.args.get('tag')
    counts = db.menu.count_documents({'tags': {'$regex': tag}})
    pages = math.ceil(counts / 6)
    return jsonify({'pages': pages, 'counts': counts})
