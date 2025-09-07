from turtle import Turtle,Screen
    
class Score(Turtle):
    def __init__(self):
        super().__init__()
        self.score = 0
        with open("C:/Coding/Python/Python/UDEMY/Snake Game/data.txt") as data: 
            self.high_score = int(data.read())
    def display_score(self):
        self.clear()
        self.penup()
        self.goto(0,250)
        self.pencolor("white")
        self.write(f"Score:{self.score} High Score:{self.high_score}",align="center",font=("arial",24,"bold"))
        self.hideturtle()
        self.score+=1
    def reset_game(self):
        if self.score > self.high_score:
            self.high_score = self.score
            with open("C:/Coding/Python/Python/UDEMY/Snake Game/data.txt", mode = 'w') as data:
                data.write(f"{self.score}")
        self.score = 0
        self.display_score()
        