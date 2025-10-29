import numpy as np
import pandas as pd
from numpy.random import randn

df = pd.DataFrame(randn(5,4),['a','b','c','d','e'],[1,2,3,4])
df["new"] = df[1] + df[3]

#df.drop("new", axis=1) #Makes a new view with a dropped column doesnt happen in place

#df.drop("new", axis=1, inplace=True) #Happens inplace #Axix = 1 for column and axis = 0 for rows

df.loc['a'] #Find a row with the name
df.iloc(0) #Find a row with the index

