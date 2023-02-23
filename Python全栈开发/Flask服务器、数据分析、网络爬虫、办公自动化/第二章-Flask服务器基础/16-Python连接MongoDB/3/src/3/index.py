from flask import Flask, render_template
from data_init import db

app = Flask(__name__)
app.debug = True


@app.route('/data', methods=['GET'])
def show_data():
    # 在下方写你的代码：查询apps集合中的所有文档，并要求按照"ranking"字段值大小进行升序排序

    # 获取渠道"应用宝"中"阅读"类别下的5条文档

    # 获取渠道"应用宝"中"视频"类别下的文档，按照排名"ranking" 降序排列的10条文档

    # 在apps集合中按照"ranking"升序排序，如果ranking字段值相同，则按照昨日下载量降序排序

    return render_template('table.html', data=data)


app.run(host='127.0.0.1', port=8001)
