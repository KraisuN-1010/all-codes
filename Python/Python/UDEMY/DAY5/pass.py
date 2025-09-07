import random
import string

nums=list(range(10))
char_nums=[chr(n+48) for n in nums]
letters=list(string.ascii_lowercase)
special_chars=list(string.punctuation)
password=[]
num_lets=int(input("How many letters do you want in your password?:"))
num_nums=int(input("How many numbers do you want in your password?:"))
num_spc=int(input("How many special characters do you want in your password?:"))
for i in range(num_lets):
    password.append(random.choice(letters))
for j in range(num_nums):
    password.append(random.choice(char_nums))
for k in range(num_spc):
    password.append(random.choice(special_chars))
random.shuffle(password)
for i in range(num_spc+num_lets+num_nums):
    print(password[i],end='')