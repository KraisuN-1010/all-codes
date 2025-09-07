import turtle as t
import colorgram
import random
colors=colorgram.extract('DAY18/this.jpg',30)
screen=t.Screen()
img_colors=[]
for color in colors:
    r=color.rgb.r
    g=color.rgb.g
    b=color.rgb.b
    colour=(r,g,b)
    img_colors.append(colour)
t.colormode(255)
jimmy=t.Turtle()
jimmy.pensize(10)
jimmy.penup()
for i in range (10):
    for j in range (10):
        # jimmy.color(random.choice(img_colors))
        # jimmy.pendown()
        # jimmy.forward(1)
        # jimmy.penup()
        jimmy.dot(20,random.choice(img_colors))
        jimmy.forward(20)
    if i%2==0:
        jimmy.setheading(90)
        jimmy.forward(20)
        jimmy.setheading(180)
        jimmy.forward(20)
    #     # jimmy.pendown()
    #     # jimmy.forward(1)
    #     # jimmy.pendown()
    #     # jimmy.right(90)
    #     # jimmy.penup()
    #     # jimmy.forward(20)
    #     # jimmy.right(90)
    if i%2==1:
        jimmy.setheading(90)
        jimmy.forward(20)
        jimmy.setheading(0)
        jimmy.forward(20)
       
    #     jimmy.pendown()
    #     jimmy.forward(1)
    #     jimmy.pendown()
    #     jimmy.left(90)
    #     jimmy.penup()
    #     jimmy.forward(20)
    #     jimmy.left(90)
screen.exitonclick()