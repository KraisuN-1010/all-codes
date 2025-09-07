class Student:
    def __init__(self,name,marks):
       self.name=name
       self.marks=marks 
    def average(self):
        total=0
        for i in range(len(self.marks)):
            total+=self.marks[i]
        print(f"Average is {total/3}")

s1=Student("uday",[10,20,30])
s1.average()