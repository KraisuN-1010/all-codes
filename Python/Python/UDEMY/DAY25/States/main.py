import turtle 
import pandas

state_data = pandas.read_csv("DAY25/States/50_states.csv")
screen = turtle.Screen()
screen.title("US States")
turtle_1 = turtle.Turtle()

IMAGE = "C:/Coding/Python/Python/UDEMY/DAY25/States/blank_states_img.gif"
screen.addshape(IMAGE)
turtle_1.shape(IMAGE)

user_input = screen.textinput(title="Guess the state", prompt="What's another state's name?")
answer_state = user_input.lower() if user_input else ""
state_x_cor = state_data.x

turtle.mainloop()