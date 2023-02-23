from flask import Flask, render_template
from data_init import db

web = Flask(__name__)
web.debug = True


@web.route('/data', methods=['GET'])
def show_data():
    data = list(db.staffs.find({}))
    # 请在下方写你的代码：使用逻辑或查询有出入证或者有健康码的员工
    data = list(db.staffs.find({'$or': [{'pass': 'Yes'}, {'health_code': 'Yes'}]}))
    
    return render_template('table.html', data=data)


web.run('127.0.0.1', 8001)
