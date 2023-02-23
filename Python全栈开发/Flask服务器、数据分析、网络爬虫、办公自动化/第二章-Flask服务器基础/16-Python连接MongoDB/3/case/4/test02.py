from flask import Flask, render_template
from data_init import db

app = Flask(__name__)
app.debug = True


@app.route('/data', methods=['GET'])
def show_data():
    # 在下方写你的代码：查看第2页的3条文档，每一页3条
    data = list(db.video.find().skip((2-1)*3).limit(3))
    
    return render_template('table.html', data=data)
   
 
if __name__ == '__main__':
    app.run(host='127.0.0.1', port=8002)
