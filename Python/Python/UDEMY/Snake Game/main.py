from turtle import Turtle,Screen
from snake import Snake
from food import Food
from score import Score
import time
screen=Screen()
screen.setup(600,600)
screen.bgcolor("black")
screen.title("Snake Game")
snake=Snake()
screen.tracer(0)
food=Food()
score=Score()
score.display_score()
game_on=True
while game_on:
    screen.update()
    time.sleep(0.1)
    snake.move()
    if snake.head.distance(food)<=15:
        food.new_loc()
        snake.add_body()
        score.display_score()
    xcoords=snake.head.xcor()
    ycoords=snake.head.ycor()
    for segment in snake.segments:
        if segment==snake.head:
            continue
        if snake.head.distance(segment)<1:
            score.reset_game()
            snake.reset()
            break
    if xcoords<-290 or xcoords>290 or ycoords<-290 or ycoords>290:
        score.reset_game()
        snake.reset()

screen.exitonclick()