COLORS = ["red", "orange", "yellow", "green", "blue", "purple"]
STARTING_MOVE_DISTANCE = 5
MOVE_INCREMENT = 10
from turtle import Turtle
import random
class CarManager(Turtle):
    def __init__(self):
        super().__init__()
        self.hideturtle()
        self.speeds=5
        self.cars=[]
    def create_car(self):
        choice=random.randint(1,5)
        if choice==1 or choice==2:
            new_car=Turtle("square")
            new_car.penup()
            new_car.shapesize(1,2)
            new_car.goto(280,random.randint(-280,280))
            new_car.color(random.choice(COLORS))
            self.cars.append(new_car)
    def move_car(self):
        for i in range(len(self.cars)):
            
            self.cars[i].backward(self.speeds)

    
