string="mim mim"
x=0
j=len(string)-1
for i in range(len(string)):
    if(string[i]==string[j]):
        x=1
    else:
        x=0
    j-=1
if(x==1):
    print("Id palindrome")
else:
    print("Not palindrome")
    
    