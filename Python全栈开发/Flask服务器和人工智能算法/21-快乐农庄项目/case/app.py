from flask import Flask, render_template, session, redirect, url_for
from handler import user, plant

app = Flask(__name__)

app.config['SECRET_KEY'] = b'123456'
app.config['JSON_AS_ASCII'] = False

app.register_blueprint(user.user)
app.register_blueprint(plant.plant)

app.debug = True


@app.route('/')
def home():
    # 未登录则重定向到登录页
    if 'username' not in session:
        return redirect(url_for('user.login_page'))
    # 从库中获取当前用户对应的植物信息
    one = user.get_user()
    return render_template('home.html', user=one)


if __name__ == '__main__':
    app.run(host='127.0.0.1', port=8000)
