num1=int(input("Enter a number: "))
num2=int(input("Enter a number: "))
x=0
for j in range(num1,num2):
    if(j<2):
        continue
    for i in range(2,j):
        if(j%i==0):
            x=1
            break
        else:
            x=0
    if(x==0):
        print(j)
