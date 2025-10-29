import pandas as pd
import numpy as np
from numpy.random import randn

#hierarchy 
outside = ['q1', 'q1', 'q1', 'q2', 'q2', 'q2']
inside = [1,2,3,1,2,3]

hier_index = list(zip(outside, inside))
hier_index = pd.MultiIndex.from_tuples(hier_index)

df = pd.DataFrame(randn(6,2), hier_index, ['A', 'B'])

df.index.names = ['Groups', 'Num']

print(df.xs(1,level='Num'))