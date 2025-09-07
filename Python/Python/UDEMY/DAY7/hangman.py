import random

comp_choice=["this","that","us","we","can"]
word=random.choice(comp_choice)
char_word=list(word)
guess=['_' for i in range(len(char_word))]
count=5
repeat=[]
x=1
while(count!=0):
    if(guess==char_word):
        x=0
        break
    else:
        letter=input("Enter a leter:")
        if letter in char_word:
            for i in range(len(char_word)):
                if((letter.upper()==char_word[i]) or (letter==char_word[i])):
                    guess[i]=char_word[i]
            for char in guess:
                print(char,end='')
        else:
            count-=1
            print("Wronf guess!!You lose a life",end='')
        print(f"\nYou have {count} lives left")

if x==0:
    print("The game has ended You won!!!")

else:
    print("The game has ended!!You lost")