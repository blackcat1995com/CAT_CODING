from data_init import db
from flask import Blueprint, jsonify

air = Blueprint('air', __name__)


@air.route("/PM25")
def PM25():
    data = list(db.air.find({"PM25": {"$gt": 75}}))
    for d in data:
        d['_id'] = str(d['_id'])
    return jsonify(data)


@air.route("/O3")
def O3():
    data1 = list(db.air.find({"O3": {"$gt": 260}}))
    data2 = list(db.air.find({"O3": {"$lt": 320}}))
    data = [new for new in data1 if new in data2]
    for d in data:
        d['_id'] = str(d['_id'])
    return jsonify(data)
