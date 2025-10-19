import numpy as np 

#View of the array Not actual copy
arr = np.arange(0,11)
slice_arr = arr[1:5]
slice_arr[:] = 99

print(arr)
print(slice_arr)

#Use Copy method
arr_copy = arr.copy()
arr_copy[:] = 58

print(arr)
print(arr_copy)

#2d Arrays

arr_2d = np.random.rand(5,3)
arr_2d_slice = arr_2d[1:]
print(arr_2d_slice)

#Conditional selection

cond_array = arr > 6
print(arr[cond_array])



