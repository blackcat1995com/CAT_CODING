from handler import pets
from data_init import db
from flask import Flask, jsonify, request

app = Flask(__name__)

app.debug = True
app.register_blueprint(pets.pets)


@app.route('/getData', methods=['GET'])
def data():
    # 获取页数page并分页显示文档
    page = int(request.args.get('page'))
    data = list(db.pets.find().skip((page - 1) * 6).limit(6))
    # 在下方写你的代码：把ObjectId对象转为字符串
    for dic in data:
        dic['_id'] = str(dic['_id'])

    return jsonify(data)


if __name__ == "__main__":
    app.run(host='127.0.0.1', port=8000)
