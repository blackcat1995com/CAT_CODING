from data_init import db
from flask import Flask, render_template, jsonify

app = Flask(__name__)

app.debug = True


@app.route('/bg', methods=['GET'])
def get_bg():
    return render_template('bg.html')


@app.route("/", methods=['GET'])
def home():
    return render_template('home.html')


@app.route("/income", methods=['GET'])
def income():
    # 在下方写你的代码：统计每个省份三年来总收入
    data = list(
            db.china.aggregate(
                    [{'$group': {
                        '_id': '$province',
                        'all_income': {'$sum' :'$income'}
                    }}]
                )
        )

    return jsonify(data)


if __name__ == "__main__":
    app.run(host='127.0.0.1', port=8000)
