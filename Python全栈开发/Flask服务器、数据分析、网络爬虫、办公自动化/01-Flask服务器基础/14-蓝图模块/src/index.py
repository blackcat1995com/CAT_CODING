from flask import Flask

app = Flask(__name__)
app.debug = True

# 请在下方写你的代码：注册wm_game和wm_store模块中蓝图


app.run(host='127.0.0.1', port=8001)
