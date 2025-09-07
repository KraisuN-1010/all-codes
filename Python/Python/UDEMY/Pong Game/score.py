from turtle import Turtle,Screen
class Score(Turtle):
    def __init__(self):
        super().__init__()
        self.score=0
        
    def line(self):
        self.hideturtle()
        self.pensize(5)
        self.pencolor("white")
        for i in range(45):
            if i<15:
                self.setheading(90)
                self.pendown()
                self.forward(20)
                self.penup()
                self.forward(15)
            if i>15:
                self.setheading(270)
                self.penup()
                self.forward(15)
                self.pendown()
                self.forward(20)
    def display_score(self,xcor):
        self.clear()
        self.penup()
        self.goto(xcor,250)
        self.pencolor("white")
        self.write(f"Score:{self.score}",align="center",font=("arial",18,"bold"))
        self.hideturtle()
        self.score+=1
    def win(self):
        self.penup()
        self.goto(0,0)
        self.pencolor("white")
        self.write("Game Over!!",align="center",font=("arial",24,"bold"))
        self.hideturtle()
