# *ARGS without names

def add(*args):
    sum = 0
    for num in args:
        sum += num
    
    return sum

print (add(1,2,3,4,5))
    
# **Kwargs with names

def calculations(num, **kwargs):
    num += kwargs["add"]
    num *= kwargs["multiply"]

    return num

print (calculations(5, add = 5, multiply = 7))