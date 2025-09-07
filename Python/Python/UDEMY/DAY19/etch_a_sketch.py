import turtle as t
jim=t.Turtle()
screen=t.Screen()
def move_forward():
    jim.forward(10)
def move_backwards():
    jim.backward(10)
def turn_left():
    jim.left(10)
def turn_right():
    jim.right(10)

screen.listen()
screen.onkey(move_forward,"w")
screen.onkey(move_backwards,"s")
screen.onkey(turn_left,"a")
screen.onkey(turn_right,"d")
screen.onkey(screen.resetscreen,"c")

screen.exitonclick()