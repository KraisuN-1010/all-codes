num1=int(input("Enter number1:"))
num2=int(input("Enter number2:"))
max= num1 if num1>num2 else num2
lcm=max
while(max%num1!=0 or max%num2!=0):
    max+=1
    lcm=max
print(f"LCM is {lcm}")    