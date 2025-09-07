
num1=int(input("Enter a number: "))
num2=int(input("Enter a number: "))
for i in range(num1,num2):
    j=0
    sum=0
    num=i
    while(num>0):
        num//=10
        j+=1
    num=i
    while(num>0):
        rem=num%10
        power=rem**j
        sum+=power
        num//=10
    if(sum==i):
        print(i)
    