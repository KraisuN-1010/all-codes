from flask import Flask
app = Flask(__name__)

def make_bold(function):
    def bold_wrapper():
        return f"<b>{function()}</b>"
    return bold_wrapper

def make_italic(function):
    def italic_wrapper():
        return f"<i>{function()}</i>"
    return italic_wrapper

def make_underlined(function):
    def underlined_wrapper():
        return f"<u>{function()}</u>"
    return underlined_wrapper

@app.route('/')
@make_bold
@make_italic
@make_underlined
def say_hello():
    return "Hello User"

@app.route('/user/<name>')
def greet_user(name):
    return f"Hello {name}"

if __name__ == "__main__":
    app.run(debug=True)
