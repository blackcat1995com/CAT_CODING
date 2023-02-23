from flask import Blueprint, render_template

bp = Blueprint('game', __name__)


@bp.route('/game')
def game():
    return render_template('game.html')
