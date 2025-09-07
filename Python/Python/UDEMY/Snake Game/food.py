from turtle import Turtle
import random
class Food(Turtle):
    def __init__(self):
        super().__init__()
        self.shape("circle")
        self.penup()
        self.shapesize(0.5,0.5)
        self.color("blue")
        self.speed("fastest")
        self.new_loc()
    def new_loc(self):
        x_cords=random.randint(-270,270)
        y_cords=random.randint(-270,270)
        self.goto(x_cords,y_cords)