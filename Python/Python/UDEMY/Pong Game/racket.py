from turtle import Turtle
y1=0
y2=0
positions=[(0,0),(0,20),(0,40)]
class Racket(Turtle):
    def __init__(self,x_cor,color):
        super().__init__()
        self.shape("square")
        self.color(color)
        self.shapesize(4,1)
        self.penup()
        self.goto(x_cor,0)
    def up(self):
        y1=self.ycor()+20
        self.goto(self.xcor(),y1)
    def down(self):
        y1=self.ycor()-20
        self.goto(self.xcor(),y1)
    def up_r(self):
        y2=self.ycor()+20
        self.goto(self.xcor(),y2)
    def down_r(self):   
        y2=self.ycor()-20
        self.goto(self.xcor(),y2)  
               
            