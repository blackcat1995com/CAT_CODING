from . import * 

@bp_store.route('/wm/store')
def wm_game():

	return render_template('wm_store.html')