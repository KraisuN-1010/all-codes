from turtle import Turtle
import random
class Ball(Turtle):
    def __init__(self):
        super().__init__()
        self.shape("circle")
        self.color("white")
        self.penup()
        self.goto(0,0)
        self.movingX=10
        self.movingY=10

    def move(self):
        x_cor=self.xcor()+self.movingX
        y_cor=self.ycor()+self.movingY
        self.goto(x_cor,y_cor)
    def collide_wall(self):
        self.movingY*=-1
    def collide_racket(self):
        self.movingX*=-1
    def reset(self):
        self.goto(0,0)
        self.collide_racket()
