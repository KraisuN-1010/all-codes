ofnum=int(input("Enter a number: "))
num=ofnum
i=0
sum=0
while(num>0):
    num//=10
    i+=1
print(i)
num=ofnum
while(num>0):
    rem=num%10
    power=rem**i
    sum+=power
    num//=10
print(sum)
if(sum==ofnum):
    print("Entered number is an armstrong number")
else:
    print("Not an armstrong number")
# num=int(input("number:"))
# num2=num
# n=0
# while num2!=0:
#     num2=num2/10
#     n+=1
# num2=num
# sum=0
# while num2!=0:
#     rem=num2%10
#     sum=sum+ rem**n
#     num2=num2/10
# print(sum)
# if num==sum:
#     print("armstrong")
# else:
#     print("not armstrong")