import numpy as np
import pandas as pd

labels = ['a', 'b', 'c']
my_data = np.arange(10, 31, 10)

label_to_data = pd.Series(data=my_data, index=labels) #If you pass a dictionary then the key will be index

#You can also pass funtions to series


print(label_to_data)

