from data import question_data
from question_model import Question
from quiz_brain import Brains
questions=[]
for question in question_data:
    question_text=question["text"]
    cor_ans=question["answer"]
    new_question=Question(question_text,cor_ans)
    questions.append(new_question)
quiz=Brains(questions)

while quiz.still_has_questions():
    quiz.next_question()