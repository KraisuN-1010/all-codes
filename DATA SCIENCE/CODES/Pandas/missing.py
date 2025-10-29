import pandas as pd
import numpy as np

d = {'A':[1,2,np.nan],'B' : [3,np.nan,5], 'C' : [1,2,3]}

df = pd.DataFrame(d)
df.dropna(thresh=3) #Dropping the null values
df.fillna(value="Filled", inplace=True)
print(df)