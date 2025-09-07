FONT = ("Courier", 24, "normal")
from turtle import Turtle,Screen
class Score(Turtle):
    def __init__(self):
        super().__init__()
        self.score=1
        self.hideturtle()
    def display_score(self):
        self.clear()
        self.penup()
        self.goto(-210,250)
        self.pencolor("black")
        self.write(f"level:{self.score}",align="center",font=(FONT))
        
        self.score+=1
    def end_game(self):
        self.goto(0,0)
        self.write("Game Over!!",align="center",font=(FONT))
