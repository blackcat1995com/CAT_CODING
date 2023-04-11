from flask import render_template, Blueprint

bp_game = Blueprint('game', __name__)
bp_store = Blueprint('store', __name__)

from . import wm_game, wm_store