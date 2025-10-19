import numpy as np

#Casting existing arrays
my_list = [1,2,3,4,5]
arr = np.array(my_list)

my_list = [[1,2,3], [4,5,6], [7,8,9]]
matrix = np.array(my_list)

#Using numPy to make Arrays

num_gen = np.arange(0, 50, 3) #First 2 are range and last one is the steps to skip

zero_array = np.zeros(3)
zero_array = np.zeros((3,4)) #Same can be done with ones too

even_ten = np.linspace(1, 10, 10) #Returns 10 evenly spaced numbers in given range 

np.eye(4) #Diagonal matrix having 4 1s
np.random.rand(7)

print(even_ten)