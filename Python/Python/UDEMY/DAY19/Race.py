from turtle import Screen,Turtle
import random
turtles=[]
y_coord=[150,100,50,0,-50,-100]
colors=["red","orange","green","blue","black","purple"]
screen=Screen()
screen.setup(500,500)
bet=screen.textinput("Make the bet!!","Which turtule's going to win?" )
for i in range (6):
    turts=Turtle(shape="turtle")
    turts.penup()
    turts.color(colors[i])
    turts.goto(-240,y_coord[i])
    turtles.append(turts)   
win=False 
if bet:
    race_on=True
while race_on:
    for tur_tal in turtles:
        tur_tal.forward(random.randint(0,10))
        if tur_tal.xcor()>220:
            if tur_tal==bet:
                win=True
            race_on=False
            break
if win:
    print("You win!!")
else:
    print("You lose!!")
screen.exitonclick()