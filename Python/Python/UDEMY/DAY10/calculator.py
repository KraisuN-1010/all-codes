import os
def clear_screen():
    if os.name == 'nt':
        os.system('cls')
def addition(num1,num2):
    num3=num1+num2
    print(f"{num1} + {num2}={num3}")
    return num3
def subtraction(num1,num2):
    num3=num1-num2
    print(f"{num1} - {num2}={num3}")
    return num3
def division(num1,num2):
    num3=num1/num2
    print(f"{num1}/{num2}={num3}")
    return num3
def modulo(num1,num2):
    num3=num1%num2
    print(f"{num1}%{num2}={num3}")
    return num3
num1=float(input("Enter the first number:"))
num4=num1
num3=num1
while True:
    operation=input("Which operation do you wanna do?:(+,-,/,*,%): ")
    num2=float(input("Enter the next number:"))
    if(operation=='+'):
        num3=addition(num4,num2)
    if(operation=='-'):
        num3=subtraction(num4,num2)
    if(operation=='/'):
        num3=division(num4,num2)
    if(operation=='%'):
        num3=modulo(num4,num2)
    cont=input("Do you want to continue with the result? y for yes n for new calculation e to end:")
    if(cont=='y'):
        num4=num3
    if(cont=='n'):
        clear_screen()
        num3=float(input("Enter the number:"))
    if(cont=='e'):
        break