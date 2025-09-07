marks=[]

m1=int(input("marks of student 1: "))
marks.append(m1)
m2=int(input("marks of student 2: "))
marks.append(m2)
m3=int(input("marks of student 3: "))
marks.append(m3)
m4=int(input("marks of student 4: "))
marks.append(m4)
marks.sort()
print(marks)
print(sum(marks))