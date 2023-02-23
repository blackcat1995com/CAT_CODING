from flask import Flask, render_template
from player_init import db

app = Flask(__name__)

app.debug = True


@app.route('/data', methods=['GET'])
def show_data():
    # 在下方写你的代码：查询“科比-布莱恩特”的文档数量
    # data = db.players.find({'player':'科比-布莱恩特'}).count()

    # 查询“迈克尔-乔丹”的文档数量
    data = db.players.find({'player': '迈克尔-乔丹'}).count()
    return render_template('table.html', data=data)


app.run(host='127.0.0.1', port=8001)
