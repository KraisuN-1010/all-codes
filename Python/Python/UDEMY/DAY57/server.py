from flask import Flask, render_template
import requests
import time

app = Flask(__name__)
AGIFY_ENDPOINT = "https://api.agify.io"


@app.route('/')
def home():
    return "<h1>Guess Age</h1><p>Go to /YOUR_NAME in the URL to guess an age!</p>"



@app.route('/<name>')
def index(name):
    params = {
        "name" : name
    }
    response = requests.get(AGIFY_ENDPOINT, params=params)
    response.raise_for_status() 
    age = response.json()['age']
    return render_template('index.html', age=age, name=name)

if __name__ == "__main__":
    app.run(debug=True)