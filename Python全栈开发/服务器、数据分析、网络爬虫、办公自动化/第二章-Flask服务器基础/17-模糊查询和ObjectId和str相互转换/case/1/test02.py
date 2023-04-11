from handler import menu
from flask import Flask, jsonify, request
from data_init import db

app = Flask(__name__)
app.debug = True
app.register_blueprint(menu.menu)


@app.route('/getData', methods=['GET'])
def menu():
    # 在下方写你的代码：获取关键字tag以及页码page
    tag = request.args.get('tag')
    page = int(request.args.get('page'))

    # 查询字段tags包含关键字的文档，并分页展示，每页展示6条文档
    data = list(db.menu.find({'tags':{'$regex': tag}}).skip((page-1)*6).limit(6))


    # 预留
    for dic in data:
        dic['_id'] = str(dic['_id'])
    return jsonify(data)


if __name__ == '__main__':
    app.run(host='127.0.0.1', port=8000)
