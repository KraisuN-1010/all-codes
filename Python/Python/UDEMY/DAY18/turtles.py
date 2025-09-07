from turtle import Turtle, Screen
import random
jimmy_turtle=Turtle()
jimmy_turtle.shape("turtle")
colors = ["turquoise", "magenta", "lime", "violet", "gold", "indigo", "teal", "coral", "chartreuse", "crimson"]
lit=[0,90,180,270]
distance_steps=50
# for _ in range(distance_steps):
#     jimmy_turtle.pencolor(random.choice(colors))
#     jimmy_turtle.right(random.choice(lit))
#     jimmy_turtle.forward(30)
jimmy_turtle.speed(0)
dimension=10
for _ in range(int(360/dimension)):
    jimmy_turtle.pencolor(random.choice(colors))
    jimmy_turtle.setheading(jimmy_turtle.heading()+dimension)
    jimmy_turtle.circle(100)
screen=Screen()
screen.exitonclick()
