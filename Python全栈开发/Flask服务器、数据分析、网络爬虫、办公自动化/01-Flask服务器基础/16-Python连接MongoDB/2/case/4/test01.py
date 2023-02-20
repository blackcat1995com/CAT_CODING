from flask import Flask, render_template
from data_init import db

web = Flask(__name__)
web.debug = True


@web.route('/data', methods=['GET'])
def show_data():
    # 在下方写你的代码：使用逻辑与查询体温正常并戴口罩的居民
    data = list(db.residents.find({'temperature': '正常', 'mask':'Yes'}))
    return render_template('table.html', data=data)


web.run(host='127.0.0.1', port=8001)
