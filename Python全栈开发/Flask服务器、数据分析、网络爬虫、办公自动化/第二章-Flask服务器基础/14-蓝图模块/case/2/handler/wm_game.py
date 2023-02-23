from . import * 

@bp_game.route('/wm/game')
def wm_game():

	return render_template('wm_game.html')
