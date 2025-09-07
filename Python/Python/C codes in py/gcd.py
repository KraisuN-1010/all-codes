num1=int(input("Enter number1:"))
num2=int(input("Enter number2:"))
min= num1 if num1<num2 else num2
gcd=min
while(num1%min!=0 or num2%min!=0):
    min-=1
    gcd=min
print(f"GCD is {gcd}")  