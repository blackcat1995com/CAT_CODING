from flask import Flask
from handler import *

app = Flask(__name__)
app.debug = True

# 请在下方写你的代码：注册wm_game和wm_store模块中蓝图
app.register_blueprint(bp_game, url_prefix='/cat1')
app.register_blueprint(bp_store, url_prefix='/cat2')

app.run(host='127.0.0.1', port=8001)
