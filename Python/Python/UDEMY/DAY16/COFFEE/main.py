from menu import Menu
from coffee_maker import CoffeeMaker
from money_machine import MoneyMachine

menu=Menu()
cofee_maker=CoffeeMaker()
money_machine=MoneyMachine()
while True:
    order=input("What would you like to have?(latte/espresso/capuccino)type 'report' for remaining ingridients,n to stop:")
    if order=='n':
        break
    elif order=='report':
        cofee_maker.report()
        money_machine.report()
    else:
        drink=menu.find_drink(order)
        if cofee_maker.is_resource_sufficient(drink):
            if money_machine.make_payment(drink.cost):
                cofee_maker.make_coffee(drink)
    

