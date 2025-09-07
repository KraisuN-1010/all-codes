initial={
    "water":300,
    "milk":200,
    "coffee":100
}
espresso={
     "water":50,
    "milk":0,
    "coffee":18
}
latte={
     "water":200,
    "milk":150,
    "coffee":24
}
cappucinno={
     "water":250,
    "milk":100,
    "coffee":24
}
end=False
while not end:
    ask=input("What would you like to have?(espresso/latte/cappuccino/report/no thanks):").lower()
    penny=0.01
    nickel=0.05
    Dime=0.10
    quarter=0.25

    if ask=="report":
        print(initial)

    if ask=="espresso":
        initial["water"]=initial["water"]-espresso["water"]
        initial["milk"]=initial["milk"]-espresso["milk"]
        initial["coffee"]=initial["coffee"]-espresso["coffee"]
        if initial["water"]<0:
            print("No enough water,Money refunded..")
            break
        elif initial["milk"]<0:
            print("No enough milk.Money refunded..")
            break
        elif initial["coffee"]<0:
            print("No enough coffee.Money refunded..")
            break
        print("Please give coins?")
        p=int(input("How many penny?"))
        n=int(input("How many Nickel?"))
        d=int(input("how many dime?"))
        q=int(input('How many quarter?'))
        total=p*penny + n*nickel + d*Dime + q*quarter
        change=total-1.50
        if change>=0:
            print(f"Please take your change: {change} and ☕🍵 take your coffee.")
        elif change<0:
            print("insufficient Money")
        print(initial)
    elif ask=="latte":
        initial["water"]=initial["water"]-latte["water"]
        initial["milk"]=initial["milk"]-latte["milk"]
        initial["coffee"]=initial["coffee"]-latte["coffee"]
        if initial["water"]<0:
            print("No enough water,Money refunded..")
            break
        elif initial["milk"]<0:
            print("No enough milk.Money refunded..")
            break
        elif initial["coffee"]<0:
            print("No enough coffee.Money refunded..")
            break
        print("Please give coins?")
        p=int(input("How many penny?"))
        n=int(input("How many Nickel?"))
        d=int(input("how many dime?"))
        q=int(input("How many quarter?"))
        total=p*penny + n*nickel + d*Dime + q*quarter
        change=total-2.50
        if change>=0:
            print(f"Please take your change: {change} and ☕🍵 take your coffee.")
        elif change<0:
            print("insufficient Money")
        print(initial)
    elif ask=="cappuccino":
        initial["water"]=initial["water"]-cappucinno["water"]
        initial["milk"]=initial["milk"]-cappucinno["milk"]
        initial["coffee"]=initial["coffee"]-cappucinno["coffee"]
        if initial["water"]<0:
            print("No enough water,Money refunded..")
            break
        elif initial["milk"]<0:
            print("No enough milk.Money refunded..")
            break
        elif initial["coffee"]<0:
            print("No enough coffee.Money refunded..")
            break
        print("Please give coins?")
        p=int(input("How many penny?"))
        n=int(input("How many Nickel?"))
        d=int(input("how many dime?"))
        q=int(input('How many quarter?'))
        total=p*penny + n*nickel + d*Dime + q*quarter
        change=total-3.00
        if change>=0:
            print(f"Please take your change: {change} and ☕🍵 take your coffee.")
        elif change<0:
            print("insufficient Money")
            print(initial)

    elif ask=="no thanks":
        end=True
        print("THANK you for visiting our cafe.")
