from flask import Flask, render_template, request
colors = ['red', 'blue']

app = Flask('__name__')

@app.route('/', methods=['POST', 'GET'])
def index():
    if request.method == 'GET':
        return render_template('index.html')
    elif request.method == 'POST':
        print('Form submitted!')
        color = request.form.get('color')
        if color not in colors:
            return render_template('index.html')
        return render_template('color.html', color=color)
