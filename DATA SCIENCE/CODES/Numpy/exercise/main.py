import numpy as np

arr = np.linspace(0.01,1,100).reshape(10,10)
total = np.sum(arr)
std_dev = np.std(arr)
column_sum = np.sum(arr,axis=0)
print(total)
print(std_dev)
print(column_sum)