import time
from turtle import Screen
from player import Player
from car_manager import CarManager
from scoreboard import Score

screen = Screen()
screen.setup(width=600, height=600)
screen.tracer(0)
turtle=Player()
scores=Score()
car=CarManager()
scores.display_score()
game_is_on = True
screen.listen()
while game_is_on:
    time.sleep(0.1)
    car.create_car()
    car.move_car()
    screen.onkey(turtle.move,"w")
    if turtle.ycor()>280:
        time.sleep(1)
        turtle.goto(0, -280)
        car.speeds+=10
        scores.display_score()
    for cars in car.cars:
        if turtle.distance(cars)<20:
            scores.end_game()
            game_is_on=False
            break
    screen.update()
screen.exitonclick()
