from flask import render_template, Blueprint
# 请在下方写你的代码：创建game蓝图

bp = Blueprint('game', __name__)

@bp.route('/wm/game')
def wm_game():

	return render_template('wm_game.html')
