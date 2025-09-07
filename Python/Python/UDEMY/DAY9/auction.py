bid={}
count=0
while True:
    choice=input("What is your name:")
    price=int(input("What's your bid:"))
    bid[choice]=price
    new=int(input("Are there any other bidders?(0 for no and 1 for yes):"))
    count+=1
    if(new==0):
        break
max=0
for key in bid:
    if max<bid[key]:
        max=bid[key]
print(max)