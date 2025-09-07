from turtle import Turtle,Screen
import time
positions=[(0,0),(-20,0),(-40,0)]
class Snake:
    def __init__(self):
        self.screen=Screen()
        self.segments=[]
        self.create_snake()
        self.head=self.segments[0]
    def create_snake(self):
        for i in range(3):
            new_seg=Turtle("square")
            new_seg.color("white")
            new_seg.penup()
            new_seg.goto(positions[i])
            self.segments.append(new_seg)
    def move(self):
        self.screen.listen()
        def turn_right():
            if self.head.heading() != 180:
                self.head.setheading(0)
        def turn_left():
            if self.head.heading() != 0:
                self.head.setheading(180)
        def turn_down():
            if self.head.heading() != 90:
                self.head.setheading(270)
        def turn_up():
            if self.head.heading() != 270:
                self.head.setheading(90)
        for i in range(len(self.segments)-1,0,-1):
            x_cord=self.segments[i-1].xcor()
            y_cord=self.segments[i-1].ycor()
            self.segments[i].goto(x_cord,y_cord)     
        self.head.forward(20)
        self.screen.onkey(turn_right,"d")
        self.screen.onkey(turn_left,"a")
        self.screen.onkey(turn_up,"w")
        self.screen.onkey(turn_down,"s")
    def add_body(self):
        new_seg = Turtle("square")
        new_seg.color("white")
        new_seg.penup()

        # Get the position of the last segment (tail)
        last_seg = self.segments[-1]
        new_seg.goto(last_seg.position())  # This is the key fix

        self.segments.append(new_seg)
    def reset(self):
        for seg in self.segments:
            seg.goto(1000,100)
        self.segments.clear()
        self.create_snake()
        self.head = self.segments[0]




        
