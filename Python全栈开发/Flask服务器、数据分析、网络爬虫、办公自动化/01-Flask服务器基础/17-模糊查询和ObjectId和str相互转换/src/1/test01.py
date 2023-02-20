from flask import Flask, render_template
from data_init import db

app = Flask(__name__)
app.debug = True


@app.route('/data', methods=['GET'])
def show_data():
    # 在下方写你的代码：查询材料包含"鸡蛋"的文档


    # 在menu集合中查询调料包含辣椒的文档，并要求分页展示第三页，每页展示6条文档


    return render_template('table.html', data=data)


if __name__ == '__main__':
    app.run(host='127.0.0.1', port=8001)
    
    
    
    
    
    
    
    
    
    
