class Brains:
    def __init__(self,question_list):
        self.q_num=0
        self.question_list=question_list
        self.score=0
    def still_has_questions(self):
        if(self.q_num<len(self.question_list)):
            return 1
        else:
            return 0
    def check_ans(self,u_ans,c_ans):
        if u_ans==c_ans:
            self.score+=1
            print("Correct answer!!")
            print(f"Your score is {self.score}/{self.q_num}")
        else:
            self.score-=1
            print("Wrong answer!!")
            print(f"Your score is {self.score}/{self.q_num}")
    def next_question(self):
        q_text=self.question_list[self.q_num]
        self.q_num+=1
        answer=input(f"Q.{self.q_num}:{q_text.question}(True/False?):")
        self.check_ans(answer,q_text.answer)
    
    

        
    