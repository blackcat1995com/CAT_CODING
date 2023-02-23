from flask import Flask
from handler import wm_game, wm_store

app = Flask(__name__)
app.debug = True

# 请在下方写你的代码：注册wm_game和wm_store模块中蓝图
app.register_blueprint(wm_game.bp, url_prefix='/cat')
app.register_blueprint(wm_store.bp)

app.run(host='127.0.0.1', port=8001)
