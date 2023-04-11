from flask import Flask, render_template, request

app = Flask(__name__)
app.debug = True

stars = [
    {'name': '水星', 'secret': '离太阳最近行星，是太阳系中最小的行星。直径小于木星和土星，但它的密度更大'},
    {'name': '木星', 'secret': '太阳外第五颗行星，而且是最大的一颗，质量是地球的318倍'},
    {'name': '金星', 'secret': '太阳外第二颗行星，太阳系第六大行星。在所有行星中，金星的轨道最接近圆，偏差不到1%'},
    {'name': '火星', 'secret': '太阳外第四颗行星，太阳系第七大行星，在中国古代又称荧火，因为火星呈红色，荧荧像火，亮度常有变化'},
    {'name': '土星', 'secret': '太阳外第六颗行星，它是气态巨行星，欧洲古希腊称之为克为由斯，中国古代人们把土星称为瑞星。'},
    {'name': '天王星', 'secret': '太阳外第七颗行星，英文名称Uranus来自古希腊神话中的天空之神乌拉诺斯（Οὐρανός），是克洛诺斯的父亲，宙斯的祖父。'}
]


@app.route('/', methods=['GET'])
def home():

    return render_template('star.html')


@app.route('/star', methods=['GET'])
def secret():
    name = request.args.get('star')
    for star in stars:
        if star['name'] == name:
            return render_template('star.html', data=star)


if __name__ == '__main__':
    app.run(host='127.0.0.1', port=8001)
