from turtle import Turtle,Screen
from racket import Racket
from ball import Ball
from score import Score
import time
screen=Screen()
screen.setup(600,600)
screen.bgcolor("black")
screen.title("Pong Game")
screen.tracer(0)
racket1=Racket(280,"blue")
racket2=Racket(-280,"red")
screen.listen()
line=Score()
line.line()
score1=Score()
score1.display_score(-100)
score2=Score()
score2.display_score(100)
ball=Ball()
x=0.1
while True:
    screen.update()
    time.sleep(x)
    ball.move()
    if score1.score==6 or score2.score==6:
        score1.win()
        break
    if racket1.distance(ball)<50 and ball.xcor()>250:
        ball.collide_racket()
        x*=0.9
    elif ball.xcor()>250:
        score1.display_score(-100)
        time.sleep(0.5)
        ball.reset()
        x=0.1
    if racket2.distance(ball)<50 and ball.xcor()<-250:
        ball.collide_racket()
        x*=0.9
    elif ball.xcor()<-250:
        score2.display_score(100)
        time.sleep(0.5)
        ball.reset()
        x=0.1
    if ball.ycor()>=280 or ball.ycor()<=-280:
        ball.collide_wall()
    screen.onkey(racket2.up,"w")
    screen.onkey(racket2.down,"s")
    screen.onkey(racket1.up_r,"Up")
    screen.onkey(racket1.down_r,"Down")
screen.exitonclick()