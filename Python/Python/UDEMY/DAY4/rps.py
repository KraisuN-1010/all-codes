import random

comp_choice=random.randint(0,2)
user_choice=int(input("Enter 0 for rock,1 for paper,2 for scicors:"))
if(user_choice==comp_choice):
    print("Its a draw")
else:
    if(comp_choice==0 and user_choice==1):
        print("You win!!")
    if(comp_choice==1 and user_choice==2):
        print("You win!!")
    if(comp_choice==2 and user_choice==0):
        print("You win!!")
    if(comp_choice==0 and user_choice==2):
        print("You Lose!!Better luck next time")
    if(comp_choice==2 and user_choice==1):
        print("You Lose!!Better luck next time")
    if(comp_choice==1 and user_choice==0):
        print("You Lose!!Better luck next time")
    
