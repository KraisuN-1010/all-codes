import numpy as np
import pandas as pd
print(pd.__version__)

data = {'Company':['GOOG','GOOG','MSFT','MSFT','FB','FB'],
        'Person':['Sam','Charlie','Amy','Vanessa','Carl','Sarah'],
        'Sales':[200,120,340,124,243,350]}

df = pd.DataFrame(data)

bycomp = df.groupby("Company").describe()

# Add numeric_only=True to the mean() call
print(bycomp)