class Bank:
    def __init__(self,acc_num,balance):
        self.acc_num=acc_num
        self.balance=balance
    def debit(self):
        deb=float(input("How much do you want to debit:"))
        if self.balance-deb>0:
            self.balance-=deb
        else:
            print("Not sufficient balance")
    def credit(self):
        cred=float(input("How much do you wanna credit:"))
        self.balance+=cred
    def bal_displau(self):
        print(f"Your balance is:{self.balance}")

user1=Bank(1,50000)
while True:
    choice=input("What would you like to do(Debit/Credit/Check balance/Exit):")
    if choice=='debit':
        user1.debit()
    elif choice=='credit':
        user1.credit()
    elif choice=='check':
        user1.bal_displau()
    elif choice=='exit':
        break
        